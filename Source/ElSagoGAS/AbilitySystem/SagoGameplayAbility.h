// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SagoAbilityInfos.h"
#include "Abilities/GameplayAbility.h"
#include "SagoGameplayAbility.generated.h"

class USagoAbilityPrimaryDataAsset;
/**
 * 
 */
UCLASS()
class ELSAGOGAS_API USagoGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
	
public:
	
	// I moved AbilityInfo under AbilityPrimaryDataAsset.
	/*UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Info")
	FAbilityInfo AbilityInfo;*/
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Info")
	USagoAbilityPrimaryDataAsset* AbilityPrimaryDataAsset;
	
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FAbilityInfo GetAbilityInfo() const;
	
	UFUNCTION(BlueprintCallable,BlueprintPure,Category="AbilitySystem")
	const bool HasPC() const;
	
	UFUNCTION(BlueprintCallable,Category="AbilitySystem")
	void SetAbilityLevel(int32 NewLevel);
};
