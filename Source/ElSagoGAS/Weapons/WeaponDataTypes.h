// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "WeaponDataTypes.generated.h"

USTRUCT(BlueprintType)
struct FWeaponAnimationData
{
	
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TSubclassOf<UAnimInstance> AnimationClass;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TObjectPtr<UAnimMontage> EquipMontage;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TObjectPtr<UAnimMontage> UnequipMontage;
	
	
};

USTRUCT(BlueprintType)
struct FWeaponMovementProperties
{
	
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float MaxWalkSpeed;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	bool bOrientRotationToMovement;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	bool bUseControllerDesiredRotation;
};

USTRUCT(BlueprintType)
struct FWeaponInfo
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FString WeaponName;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int32 DamageAmount;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FName HandSocketName;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FName BackSocketName;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FWeaponAnimationData AnimationData;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FWeaponMovementProperties MovementProperties;
};

UENUM(BlueprintType)
enum class EWeaponType: uint8
{
	EWT_None UMETA(DisplayName = "None"),
	EWT_Axe UMETA(DisplayName = "Axe")
	
};

class ELSAGOGAS_API WeaponDataTypes
{
public:
	WeaponDataTypes();
	~WeaponDataTypes();
};
