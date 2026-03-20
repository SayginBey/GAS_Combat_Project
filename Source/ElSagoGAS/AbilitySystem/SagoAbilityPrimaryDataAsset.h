// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SagoAbilityInfos.h"
#include "Engine/DataAsset.h"

#include "SagoAbilityPrimaryDataAsset.generated.h"

struct FGameplayTag;
/**
 * 
 */
UCLASS()
class ELSAGOGAS_API USagoAbilityPrimaryDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("AbilityInfo", GetFName());
	}
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TMap<FGameplayTag, FAbilityInfo> AbilityTagToInfoMap;
	
	UFUNCTION()
	FAbilityInfo FindAbilityInfoByTag(const FGameplayTag& AbilityAssetTag);
};
