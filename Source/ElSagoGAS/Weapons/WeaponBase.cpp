// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponBase.h"
#include "SagoWeaponPrimaryDataAsset.h"


// Sets default values
AWeaponBase::AWeaponBase()
{
	PrimaryActorTick.bCanEverTick = true;
	
}

void AWeaponBase::BeginPlay()
{
	Super::BeginPlay();
	
}

FWeaponInfo AWeaponBase::GetWeaponInfo() const
{
	if (WeaponPrimaryDataAsset)
	{
		ensure(WeaponTag.IsValid());
		return WeaponPrimaryDataAsset->FindWeaponInfoByTag(WeaponTag);
	}
	return FWeaponInfo();
}

void AWeaponBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	
}

