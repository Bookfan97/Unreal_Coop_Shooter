// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "SPickupActor.generated.h"

UCLASS()
class COOPGAME_API ASPickupActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASPickupActor();
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, Category = "Components")
		USphereComponent* SphereComponent;
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UDecalComponent* DecalComponent;
};
