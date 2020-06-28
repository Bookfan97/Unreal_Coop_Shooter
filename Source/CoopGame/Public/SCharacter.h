// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#define WIN32_LEAN_AND_MEAN
#include "SHealthComponent.h"
#include "SWeapon.h"
#include "Windows.h"
#include "SCharacter.generated.h"

//class UCameraComponent;

UCLASS()
class COOPGAME_API ASCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void MoveForward(float Value);
	void MoveRight(float Value);
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		UCameraComponent* CameraComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
		USpringArmComponent* SpringArmComponent;
	USHealthComponent* HealthComponent;
	bool bWantToZoom;
	UPROPERTY(EditDefaultsOnly, Category = "Player")
		float zoomFOV;
	UPROPERTY(EditDefaultsOnly, Category = "Player", meta = (ClampMin = 0.1, ClampMax = 100))
		float ZoomInterpSpeed;
	float DefaultFOV;
	void BeginCrouch();
	void EndCrouch();
	void BeginZoom();
	void EndZoom();
	ASWeapon* CurrentWeapon;
	UPROPERTY(VisibleDefaultsOnly, Category = "Player")
		FName WeaponAttachSocketName;
	UPROPERTY(EditDefaultsOnly, Category = "Player")
		TSubclassOf<ASWeapon> StarterWeaponClass;
	void StartFire();
	void StopFire();
	UFUNCTION()
		void OnHealthChanged(USHealthComponent* OwningHealthComp, float Health, float HealthDelta, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);
	UPROPERTY(BlueprintReadOnly, Category = "Player")
		bool isDead;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual FVector GetPawnViewLocation() const override;
};
