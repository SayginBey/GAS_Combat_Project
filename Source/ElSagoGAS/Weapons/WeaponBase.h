// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WeaponDataAsset.h"
#include "GameFramework/Actor.h"
#include "WeaponDataTypes.h"

#include "WeaponBase.generated.h"


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
	FORCEINLINE FWeaponInfo GetWeaponInfo() const { return WeaponData->WeaponInfo;}
	
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION(BlueprintCallable)
	FORCEINLINE EWeaponType GetWeaponType() const {return WeaponType;}
	
private:
	
	EWeaponType WeaponType;
	
	UPROPERTY(EditDefaultsOnly, Category= "WeaponProperties")
	TObjectPtr<UWeaponDataAsset> WeaponData;
};
