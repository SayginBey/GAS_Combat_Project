// Fill out your copyright notice in the Description page of Project Settings.


#include "SagoWeaponPrimaryDataAsset.h"

#include "WeaponDataTypes.h"
#include "ElSagoGAS/AbilitySystem/SagoAbilityInfos.h"

FWeaponInfo USagoWeaponPrimaryDataAsset::FindWeaponInfoByTag(const FGameplayTag& WeaponTag)
{
	if (!WeaponTag.IsValid()) {return FWeaponInfo();}

	if (FWeaponInfo* Info = GameplayTagToWeaponInfoMap.Find(WeaponTag))
	{
		return *Info;
	}
	else
	{
		UE_LOG(LogTemp,Warning,TEXT("WeaponInfo couldn't find by tag in SagoWeaponPrimaryDataAsset"))
		return FWeaponInfo();
	}
}
