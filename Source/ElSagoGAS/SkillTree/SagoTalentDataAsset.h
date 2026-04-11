// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "SagoTalentDataAsset.generated.h"

/**
 * 
 */

class UGameplayEffect;
class UGameplayAbility;

UENUM(BlueprintType)
enum class ETalentType: uint8
{
	ETT_None UMETA(DisplayName = "None"),
	ETT_Active UMETA(DisplayName = "Active"),
	ETT_Passive UMETA(DisplayName = "Passive"),
	ETT_Triggered UMETA(DisplayName = "Reactive")
};

USTRUCT(BlueprintType)
struct FTalentInfo
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="UI")
	FName Name;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="UI")
	FName Description;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="UI")
	TObjectPtr<UTexture2D> Icon;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Logic")
	ETalentType Type;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Logic")
	int32 MaxLevel;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Logic")
	TMap<FGameplayTag, TSubclassOf<UGameplayAbility>> AbilityTagToAbilitiesToGrantMap;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Logic")
	TArray<TSubclassOf<UGameplayEffect>> EffectsToApply;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="For Stat Talents")
	FGameplayAttribute Attribute;
	
};

UCLASS()
class ELSAGOGAS_API USagoTalentDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Talent")
	FTalentInfo TalentInfo;
	
};
