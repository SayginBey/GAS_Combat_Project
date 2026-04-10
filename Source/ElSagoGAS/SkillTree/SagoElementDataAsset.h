// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SagoElementDataAsset.generated.h"

/**
 * 
 */

class UGameplayEffect;
class UGameplayAbility;

UENUM(BlueprintType)
enum class EElementTypes: uint8
{
	EET_None UMETA(DisplayName = "None"),
	EET_Fire UMETA(DisplayName = "Fire"),
	EET_Ice UMETA(DisplayName = "Ice"),
	EET_Curse UMETA(DisplayName = "Curse")
};
USTRUCT(BlueprintType)
struct FElementInfo
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="UI")
	FName Name;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="UI")
	FName Description;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="UI")
	TObjectPtr<UTexture2D> Icon;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Logic")
	EElementTypes Type;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Logic")
	TArray<TSubclassOf<UGameplayAbility>> AbilitiesToGrant;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Logic")
	TArray<TSubclassOf<UGameplayEffect>> EffectsToApply;
};

UCLASS()
class ELSAGOGAS_API USagoElementDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Element")
	FElementInfo ElementInfo;
};
