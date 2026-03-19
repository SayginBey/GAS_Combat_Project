// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponDataTypes.h"

#include "WeaponBase.generated.h"


class UWeaponDataAsset;

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
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category= "WeaponProperties")
	TObjectPtr<UWeaponDataAsset> WeaponData;
	
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION(BlueprintCallable)
	FORCEINLINE EWeaponType GetWeaponType() const {return WeaponType;}
	
private:
	
	EWeaponType WeaponType;
	
};
