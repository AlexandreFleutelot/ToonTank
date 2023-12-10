// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/ToonTankPlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Characters/Tank.h"
#include "Kismet/GameplayStatics.h"

AToonTankPlayerController::AToonTankPlayerController()
{
}

void AToonTankPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	FHitResult HitResult;
	GetHitResultUnderCursor(
		ECC_Visibility,
		false,
		HitResult);
	
	RotateTurret(HitResult.Location);
}

void AToonTankPlayerController::SetPlayerEnabledState(bool bPlayerEnabled)
{
	if (bPlayerEnabled)
	{
		EnableInput(this);
	}
	else
	{
		DisableInput(this);
	}
	bShowMouseCursor = bPlayerEnabled;

}

void AToonTankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	check(ToonTankContext);
	
	// Get the Enhanced Input Local Player Subsystem (Singleton)
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(
		GetLocalPlayer())) 
	{
		Subsystem->AddMappingContext(ToonTankContext, 0);
	}
	
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	//Setting input mode
	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

void AToonTankPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AToonTankPlayerController::MoveAndTurn);
	EnhancedInputComponent->BindAction(FireAction, ETriggerEvent::Started, this, &AToonTankPlayerController::Fire);
}

void AToonTankPlayerController::MoveAndTurn(const FInputActionValue& InputActionValue)
{	
	if (ATank* ControlledTank = GetPawn<ATank>())
	{
		const FVector2d InputAxisVector = InputActionValue.Get<FVector2d>();
		ControlledTank->Turn(InputAxisVector.X);
		ControlledTank->Move(InputAxisVector.Y);
	}
}

void AToonTankPlayerController::Fire(const FInputActionValue& InputActionValue)
{
	if (ABasePawn* ControlledPawn = GetPawn<ABasePawn>())
	{
		ControlledPawn->Fire();
	}
}

void AToonTankPlayerController::RotateTurret(FVector CursorLocation)
{
	if (ATank* ControlledTank = GetPawn<ATank>())
	{
		ControlledTank->RotateTurret(CursorLocation);
	}
}
