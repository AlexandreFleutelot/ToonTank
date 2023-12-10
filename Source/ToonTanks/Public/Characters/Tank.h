// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputComponent;

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()
	
public:
	ATank();

	virtual void PossessedBy(AController* NewController) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void HandleDestruction() override;
	virtual void BeginPlay() override;

	APlayerController* GetTankPlayerController() const { return TankPlayerController; }

	void Move(float Value);
	void Turn(float Value);

	bool bAlive = true;

private:
	
	UPROPERTY(EditAnywhere, Category="Movement")
	float Speed = 500.f;
	
	UPROPERTY(EditAnywhere, Category="Movement")
	float TurnSpeed = 60.f;
	
	UPROPERTY(VisibleAnywhere, Category="Components")
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, Category="Components")
	UCameraComponent* Camera;

	APlayerController* TankPlayerController;
};
