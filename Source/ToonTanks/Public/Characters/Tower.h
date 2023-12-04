// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/BasePawn.h"
#include "Tower.generated.h"

class ATank;
/**
 * 
 */
UCLASS()
class TOONTANKS_API ATower : public ABasePawn
{
	GENERATED_BODY()

public:
	
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, Category="Combat")
	float FireRange=1000.f;

protected:
	
	virtual void BeginPlay() override;

private:

	ATank* Tank;
	FTimerHandle FireRateTimerHandle;
	float FireRate = 2.f;
	void CheckFireCondition();
	bool InFireRange();
;	
};
