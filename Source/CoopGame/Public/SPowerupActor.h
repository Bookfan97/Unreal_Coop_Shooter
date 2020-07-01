// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SPowerupActor.generated.h"

UCLASS()
class COOPGAME_API ASPowerupActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASPowerupActor();
	UFUNCTION(BlueprintImplementableEvent, Category = "PowerUp")
		void OnActivated();
	UFUNCTION(BlueprintImplementableEvent, Category = "PowerUp")
		void OnExpired();
	UFUNCTION(BlueprintImplementableEvent, Category = "PowerUp")
		void OnPowerupTicked();
	void ActivatePowerup();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditDefaultsOnly, Category = "PowerUp")
		float PowerupInterval;
	UPROPERTY(EditDefaultsOnly, Category = "PowerUp")
		int32 TotalNumTicks;
	FTimerHandle TimerHandle_PowerupTick;
	int32 TicksProcessed;
	UFUNCTION()
		void OnTickPowerup();
};
