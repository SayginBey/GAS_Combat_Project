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
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Damage)
	FGameplayAttributeData Damage;
	ATTRIBUTE_ACCESSORS_BASIC(USagoAttributeSet, Damage)
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Health)
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS_BASIC(USagoAttributeSet, Health)

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MaxHealth)
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS_BASIC(USagoAttributeSet, MaxHealth);
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Shield)
	FGameplayAttributeData Shield;
	ATTRIBUTE_ACCESSORS_BASIC(USagoAttributeSet, Shield)

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MaxShield)
	FGameplayAttributeData MaxShield;
	ATTRIBUTE_ACCESSORS_BASIC(USagoAttributeSet, MaxShield);
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Stamina)
	FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS_BASIC(USagoAttributeSet, Stamina)
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MaxStamina)
	FGameplayAttributeData MaxStamina;
	ATTRIBUTE_ACCESSORS_BASIC(USagoAttributeSet, MaxStamina)
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Armor)
    FGameplayAttributeData Armor;
    ATTRIBUTE_ACCESSORS_BASIC(USagoAttributeSet, Armor)
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MaxArmor)
    FGameplayAttributeData MaxArmor;
    ATTRIBUTE_ACCESSORS_BASIC(USagoAttributeSet, MaxArmor);
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Strength)
	FGameplayAttributeData Strength;
	ATTRIBUTE_ACCESSORS_BASIC(USagoAttributeSet, Strength)
    
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MaxStrength)
	FGameplayAttributeData MaxStrength;
	ATTRIBUTE_ACCESSORS_BASIC(USagoAttributeSet, MaxStrength);

public:
	UFUNCTION()
	void OnRep_Damage(const FGameplayAttributeData& OldDamage) const
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(USagoAttributeSet, Damage, OldDamage);
	}
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
	void OnRep_Shield(const FGameplayAttributeData& OldShield) const
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(USagoAttributeSet, Shield, OldShield);
	}
	UFUNCTION()
	void OnRep_MaxShield(const FGameplayAttributeData& OldMaxShield) const
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(USagoAttributeSet, MaxShield, OldMaxShield);
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
		
	UFUNCTION()
    	void OnRep_Armor(const FGameplayAttributeData& OldArmor) const
    	{
    		GAMEPLAYATTRIBUTE_REPNOTIFY(USagoAttributeSet, Armor, OldArmor);
    	}
    	UFUNCTION()
    	void OnRep_MaxArmor(const FGameplayAttributeData& OldMaxArmor) const
    	{
    		GAMEPLAYATTRIBUTE_REPNOTIFY(USagoAttributeSet, MaxArmor, OldMaxArmor);
    	}
	UFUNCTION()
	void OnRep_Strength(const FGameplayAttributeData& OldStrength) const
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(USagoAttributeSet, Strength, OldStrength);
	}
	UFUNCTION()
	void OnRep_MaxStrength(const FGameplayAttributeData& OldMaxStrength) const
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(USagoAttributeSet, MaxStrength, OldMaxStrength);
	}
	
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	
	//For clamping the attributes.
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;
	
	virtual void PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue) override;
};
