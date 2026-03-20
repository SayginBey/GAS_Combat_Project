// Fill out your copyright notice in the Description page of Project Settings.


#include "SagoAbilityPrimaryDataAsset.h"

FAbilityInfo USagoAbilityPrimaryDataAsset::FindAbilityInfoByTag(const FGameplayTag& AbilityAssetTag)
{
	if (!AbilityAssetTag.IsValid()){return FAbilityInfo();}

	if (const FAbilityInfo* AbilityInfo = AbilityTagToInfoMap.Find(AbilityAssetTag))
	{
		return *AbilityInfo;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AbilityInfo couldn't find by tag in SagoAbilityPrimaryDataAsset"))
		return FAbilityInfo();
	}
}
