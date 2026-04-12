// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "WeaponDataTypes.generated.h"

struct FGameplayEffectSpecHandle;
class UGameplayAbility;

UENUM(BlueprintType)
enum class EWeaponType: uint8
{
	EWT_None UMETA(DisplayName = "None"),
	EWT_Axe UMETA(DisplayName = "Axe"),
	EWT_Katana UMETA(DisplayName = "Katana"),
	EWT_Staff UMETA(DisplayName = "Staff")
};

UENUM(BlueprintType)
enum class EElementTypes: uint8
{
	EET_None UMETA(DisplayName = "None"),
	EET_Fire UMETA(DisplayName = "Fire"),
	EET_Ice UMETA(DisplayName = "Ice"),
	EET_Curse UMETA(DisplayName = "Curse")
};

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
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TMap<int32,TObjectPtr<UAnimMontage>> ComboIndexToMontageMap;
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
struct FElementalAbility
{
	
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TMap<FGameplayTag, TSubclassOf<UGameplayAbility>> ElementalAbilitiesAndTheirTalentTagMap;
};

USTRUCT(BlueprintType)
struct FWeaponInfo
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FString WeaponName;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	EWeaponType WeaponType;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TMap<FGameplayTag, TSubclassOf<UGameplayAbility>> GrantedAbilitiesByWeaponAndTheirTalentTagMap;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TMap<EElementTypes, FElementalAbility> ElementalGrantedAbilitiesByWeaponMap;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FName HandSocketName;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FName UnequippedSocketName;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float HitTraceRadius;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FWeaponAnimationData AnimationData;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FWeaponMovementProperties MovementProperties;
};

class ELSAGOGAS_API FWeaponDataTypes
{
public:
	FWeaponDataTypes();
	~FWeaponDataTypes();
	
	
};
