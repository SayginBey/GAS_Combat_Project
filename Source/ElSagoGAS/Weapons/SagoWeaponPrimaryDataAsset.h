// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "WeaponDataTypes.h"
#include "Engine/DataAsset.h"
#include "SagoWeaponPrimaryDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class ELSAGOGAS_API USagoWeaponPrimaryDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("WeaponInfo", GetFName());;
	}

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	TMap<FGameplayTag,FWeaponInfo> GameplayTagToWeaponInfoMap;
	
	UFUNCTION()
	FWeaponInfo FindWeaponInfoByTag(const FGameplayTag& WeaponTag);
};
