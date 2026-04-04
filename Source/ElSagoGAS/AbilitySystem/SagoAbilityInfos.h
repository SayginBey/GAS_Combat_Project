// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

#include "SagoAbilityInfos.generated.h"

USTRUCT(BlueprintType)
struct FAbilityInfo
{
	GENERATED_BODY()
	
	// Suan kullanmiyorum lazim olursa acarim.
	/*UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FGameplayTag AbilityTag = FGameplayTag();*/
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FText AbilityName;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UTexture2D* AbilityImage;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	bool bShowInAbilityBar = false;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	bool bAutoActivateOnGranted = false;
	
};

/**
 * 
 */
class ELSAGOGAS_API SagoAbilityInfos
{
public:
	SagoAbilityInfos();
	~SagoAbilityInfos();
};
