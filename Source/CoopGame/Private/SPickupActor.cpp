// Fill out your copyright notice in the Description page of Project Settings.

#include "SPickupActor.h"
#include "SPowerupActor.h"
#include "TimerManager.h"
#include "Components/DecalComponent.h"
// Sets default values
ASPickupActor::ASPickupActor()
{
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	SphereComponent->SetSphereRadius(75.0f);
	RootComponent = SphereComponent;
	DecalComponent = CreateDefaultSubobject<UDecalComponent>(TEXT("DecalComponent"));
	DecalComponent->SetRelativeRotation(FRotator(0, 90, 0));
	DecalComponent->DecalSize = FVector(64.0f, 75.0f, 75.0f);
	DecalComponent->SetupAttachment(RootComponent);
}

void ASPickupActor::BeginPlay()
{
	Super::BeginPlay();
	Respawn();
}

void ASPickupActor::Respawn()
{
	if (PowerupClass == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("PowerUpClass is nullptr in %s. Please update your Blueprint"), *GetName());
		return;
	}
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	PowerupInstance = GetWorld()->SpawnActor<ASPowerupActor>(PowerupClass, GetTransform(), SpawnParams);
}

void ASPickupActor::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	if (PowerupInstance)
	{
		PowerupInstance->ActivatePowerup();
		PowerupInstance = nullptr;
		GetWorldTimerManager().SetTimer(TimerHandle_RespawnTimer, this, &ASPickupActor::Respawn, coolDownDuration);
	}
}