// Fill out your copyright notice in the Description page of Project Settings.


#include "SagoGameplayAbility.h"

#include "SagoAbilityPrimaryDataAsset.h"

FAbilityInfo USagoGameplayAbility::GetAbilityInfo() const
{
	if (AbilityPrimaryDataAsset)
	{
		// I already checked validation in FindAbilityInfoByTag function.
		ensure(GetAssetTags().First().IsValid());
		return AbilityPrimaryDataAsset->FindAbilityInfoByTag(GetAssetTags().First());
	}
	return FAbilityInfo();
}

const bool USagoGameplayAbility::HasPC() const
{
	APawn* Pawn = Cast<APawn>(GetAvatarActorFromActorInfo());
	if (Pawn)
	{
		return Pawn->GetController()->IsA<APlayerController>();
	}
	return false;
}
