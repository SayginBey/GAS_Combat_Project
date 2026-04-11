// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

#include "GameFramework/Actor.h"
#include "WeaponDataTypes.h"

#include "WeaponBase.generated.h"


class USagoWeaponPrimaryDataAsset;

UCLASS()
class ELSAGOGAS_API AWeaponBase : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AWeaponBase();

protected:
	
	virtual void BeginPlay() override;

public:
	
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FWeaponInfo GetWeaponInfo() const;
	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category= "Weapon Properties")
	FGameplayTag WeaponTag;
	
private:
	
	UPROPERTY(EditDefaultsOnly, Category= "Weapon Properties")
	TObjectPtr<USagoWeaponPrimaryDataAsset> WeaponPrimaryDataAsset;
};
