// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SGameMode.generated.h"

enum class EWaveState : uint8;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnActorKilled, AActor*, VictimActor, AActor*, KillerActor, AController*, KillerController);

UCLASS()
class COOPGAME_API ASGameMode : public AGameModeBase
{
	GENERATED_BODY()
protected:
	UFUNCTION(BlueprintImplementableEvent, Category = "GameMode")
		void SpawnNewBot();
	void SpawnBotTimerElapsed();
	void StartWave();
	void EndWave();
	void NextWavePrep();
	void CheckWaveState();
	void CheckPlayerAlive();
	void GameOver();
	void SetWaveState(EWaveState NewState);
	void RespawnDeadPlayers();
	FTimerHandle TimerHandle_BotSpawner;
	FTimerHandle TimerHandle_NextWaveStart;
	int32 NumBotsToSpawn;
	int32 WaveCount;
	UPROPERTY(EditDefaultsOnly, Category = "GameMode")
		float TimeBetweenWaves;
public:
	ASGameMode();
	virtual void StartPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	UPROPERTY(BlueprintAssignable, Category = "GameMode")
		FOnActorKilled OnActorKilled;
};