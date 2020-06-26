// Fill out your copyright notice in the Description page of Project Settings.

#include "SProjectileWeapon.h"

#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/Actor.h"

inline void ASProjectileWeapon::Fire()
{
	AActor* MyOwner = GetOwner();
	if (MyOwner)
	{
		FVector EyeLocation;
		FRotator EyeRotation;
		MyOwner->GetActorEyesViewPoint(EyeLocation, EyeRotation);
		FVector MuzzleLocation = MeshComponent->GetSocketLocation(MuzzleSocketName);
		FRotator MuzzleRotation = MeshComponent->GetSocketRotation(MuzzleSocketName);
		FActorSpawnParameters SpawnParameters;
		SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		GetWorld()->SpawnActor<AActor>(ProjectileClass, MuzzleLocation, EyeRotation, SpawnParameters);
	}
}