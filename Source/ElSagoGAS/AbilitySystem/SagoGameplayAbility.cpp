// Fill out your copyright notice in the Description page of Project Settings.


#include "SagoGameplayAbility.h"

#include "SagoAbilityPrimaryDataAsset.h"

FAbilityInfo USagoGameplayAbility::GetAbilityInfo() const
{
	if (AbilityDataAsset)
	{
		// I already checked validation in FindAbilityInfoByTag function.
		return AbilityDataAsset->FindAbilityInfoByTag(GetAssetTags().First());
	}
	return FAbilityInfo();
}
