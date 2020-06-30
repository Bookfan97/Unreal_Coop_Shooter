// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SHealthComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Pawn.h"
#include "Components/StaticMeshComponent.h"
#include "STrackerBot.generated.h"

UCLASS()
class COOPGAME_API ASTrackerBot : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASTrackerBot();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleDefaultsOnly, Category = "Components")
		UStaticMeshComponent* MeshComponent;
	UPROPERTY(VisibleDefaultsOnly, Category = "Components")
		USHealthComponent* HealthComponent;
	UPROPERTY(VisibleDefaultsOnly, Category = "Components")
	USphereComponent* SphereComponent;
	UFUNCTION()
		void HandleTakeDamage(USHealthComponent* OwningHealthComp, float Health, float HealthDelta, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);
	FVector GetNextPathPoint();
	FVector NextPathPoint;
	UPROPERTY(EditDefaultsOnly, Category = "TrackerBot")
		float MovementForce;
	UPROPERTY(EditDefaultsOnly, Category = "TrackerBot")
		bool bUseVelocityChange;
	UPROPERTY(EditDefaultsOnly, Category = "TrackerBot")
		float RequiredDistanceToTarget;
	UMaterialInstanceDynamic* MaterialInstanceDynamic;
	void SelfDestruct();
	UPROPERTY(EditDefaultsOnly, Category = "TrackerBot")
		UParticleSystem* ExplosionEffect;
	bool bExploded;
	bool bStartedSelfDestruction;
	UPROPERTY(EditDefaultsOnly, Category = "TrackerBot")
		float ExplosionRadius;
	UPROPERTY(EditDefaultsOnly, Category = "TrackerBot")
		float ExplosionDamage;
	FTimerHandle TimerHandle_SelfDamage;
	void DamageSelf();
};
