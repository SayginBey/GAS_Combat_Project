// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "Net/UnrealNetwork.h"
#include "SagoAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class ELSAGOGAS_API USagoAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	
	USagoAttributeSet();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Health)
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS_BASIC(USagoAttributeSet, Health)

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MaxHealth)
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS_BASIC(USagoAttributeSet, MaxHealth);
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Stamina)
	FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS_BASIC(USagoAttributeSet, Stamina)
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MaxStamina)
	FGameplayAttributeData MaxStamina;
	ATTRIBUTE_ACCESSORS_BASIC(USagoAttributeSet, MaxStamina)
	
public:
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(USagoAttributeSet, Health, OldHealth);
	}
	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(USagoAttributeSet, MaxHealth, OldMaxHealth);
	}
	UFUNCTION()
	void OnRep_Stamina(const FGameplayAttributeData& OldStamina) const
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(USagoAttributeSet, Stamina, OldStamina);
	}
	UFUNCTION()
	void OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina) const
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(USagoAttributeSet, MaxStamina, OldMaxStamina);
	}
		
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	
	//For clamping the attributes.
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;
	
	virtual void PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue) override;
};
