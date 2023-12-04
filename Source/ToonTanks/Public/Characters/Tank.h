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

	void Move(float Value);
	void Turn(float Value);

private:
	
	UPROPERTY(EditAnywhere, Category="Movement")
	float Speed = 500.f;
	
	UPROPERTY(EditAnywhere, Category="Movement")
	float TurnSpeed = 60.f;
	
	UPROPERTY(VisibleAnywhere, Category="Components")
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, Category="Components")
	UCameraComponent* Camera;
	
};
