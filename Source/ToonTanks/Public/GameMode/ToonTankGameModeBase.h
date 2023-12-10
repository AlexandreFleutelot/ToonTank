// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ToonTankGameModeBase.generated.h"

class ATank;
class AToonTankPlayerController;

/**
 * 
 */
UCLASS()
class TOONTANKS_API AToonTankGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void ActorDied(AActor* DeadActor);
	virtual void BeginPlay() override;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void StartGame();

	UFUNCTION(BlueprintImplementableEvent)
	void GameOver(bool bWonGame);
	
private:

	void HandleGameStart();
	
	ATank* Tank;
	AToonTankPlayerController* ToonTanksPlayerController;

	float StartDelay = 3.f;
	
	int32 GetTowerCount();
};
