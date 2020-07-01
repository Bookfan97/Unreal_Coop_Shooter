// Fill out your copyright notice in the Description page of Project Settings.

#include "SPowerupActor.h"

#include "TimerManager.h"

// Sets default values
ASPowerupActor::ASPowerupActor()
{
	PowerupInterval = 0.0f;
	TotalNumTicks = 0.0f;
}

void ASPowerupActor::ActivatePowerup()
{
	if (PowerupInterval > 0.0f)
	{
		GetWorldTimerManager().SetTimer(TimerHandle_PowerupTick, this, &ASPowerupActor::OnTickPowerup, true, 0.0f);
	}
	else
	{
		OnTickPowerup();
	}
}

// Called when the game starts or when spawned
void ASPowerupActor::BeginPlay()
{
	Super::BeginPlay();
}

void ASPowerupActor::OnTickPowerup()
{
	TicksProcessed++;
	OnPowerupTicked();
	if (TicksProcessed >= TotalNumTicks)
	{
		OnExpired();
		GetWorldTimerManager().ClearTimer(TimerHandle_PowerupTick);
	}
}