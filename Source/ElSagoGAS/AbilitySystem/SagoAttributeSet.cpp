// Fill out your copyright notice in the Description page of Project Settings.


#include "SagoAttributeSet.h"

#include "GameplayEffectExtension.h"

USagoAttributeSet::USagoAttributeSet()
{
	Stamina = 100.f;
	MaxStamina = 100.f;
	Health = 100.f;
	MaxHealth = 100.f;
	Shield = 0.f;
	MaxShield = 100.f;
	Damage = 0.f;
	Armor = 0.f;
	MaxArmor = 100.f;
	Strength = 0.f;
	MaxStrength = 100.f;
}

void USagoAttributeSet::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME_CONDITION_NOTIFY( USagoAttributeSet, Damage, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY( USagoAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY( USagoAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY( USagoAttributeSet, Stamina, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY( USagoAttributeSet, MaxStamina, COND_None, REPNOTIFY_Always);	
	DOREPLIFETIME_CONDITION_NOTIFY( USagoAttributeSet, Shield, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY( USagoAttributeSet, MaxShield, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY( USagoAttributeSet, Armor, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY( USagoAttributeSet, MaxArmor, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY( USagoAttributeSet, Strength, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY( USagoAttributeSet, MaxStrength, COND_None, REPNOTIFY_Always);
}

void USagoAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);
	
	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxHealth());
	}
	else if (Attribute == GetStaminaAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxStamina());
	}
	else if (Attribute == GetShieldAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxShield());
	}
	else if (Attribute == GetArmorAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxArmor());
	}
	else if (Attribute == GetStrengthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxStrength());
	}
}

void USagoAttributeSet::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
	
	if (Data.EvaluatedData.Attribute == GetDamageAttribute())
	{
		//Incase we forget to choose override in Gameplay Effect, set damage to 0 after applying it.
		float IncomingDamage = GetDamage();
		SetDamage(0.f);
		if (IncomingDamage <= 0.f) {return;}
		float CurrentShield = GetShield();
		if (CurrentShield > 0.f)
		{
			SetShield(CurrentShield - IncomingDamage);
			float RemainingDamage = IncomingDamage - CurrentShield; //We get current shield in the beginning.
			if (RemainingDamage > 0.f)
			{
				SetHealth(GetHealth() - RemainingDamage);
			}
		}
		else //No shield, apply damage to health directly.
		{
			SetHealth(GetHealth() - IncomingDamage);
		}
		if (Data.EffectSpec.Def->GetAssetTags().HasTag(FGameplayTag::RequestGameplayTag(FName("Effects.DoHitReaction")))
			&& Data.EvaluatedData.Magnitude != 0.f)
		{
			// If the GameplayEffect has the "Effects.DoHitReaction" tag and the magnitude of the damage is not 0, we trigger hit reaction.
			FGameplayTagContainer AbilityTagContainer;
			AbilityTagContainer.AddTag(FGameplayTag::RequestGameplayTag(FName("Ability.HitReaction")));
			GetOwningAbilitySystemComponent()->TryActivateAbilitiesByTag(AbilityTagContainer);
		}
	}
	else if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		//Set health already clamping the new value. So we don't have to clamp again.
		SetHealth(GetHealth());
	}
	else if (Data.EvaluatedData.Attribute == GetStaminaAttribute())
	{
		//Set Stamina already clamping the new value. So we don't have to clamp again.
		SetStamina(GetStamina());
	}
	else if (Data.EvaluatedData.Attribute == GetShieldAttribute())
	{
		//Set Shield already clamping the new value. So we don't have to clamp again.
		SetShield(GetShield());
	}
	else if (Data.EvaluatedData.Attribute == GetArmorAttribute())
	{
		//Set Armor already clamping the new value. So we don't have to clamp again.
		SetArmor(GetArmor());
	}
	else if (Data.EvaluatedData.Attribute == GetStrengthAttribute())
	{
		//Set Strength already clamping the new value. So we don't have to clamp again.
		SetStrength(GetStrength());
	}
}

void USagoAttributeSet::PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue)
{
	Super::PostAttributeChange(Attribute, OldValue, NewValue);
	
	if (Attribute == GetHealthAttribute())
	{
		if (NewValue <= 0.f)
		{
			// If health is 0 or less, we trigger death.
			FGameplayTagContainer AbilityTagContainer;
			AbilityTagContainer.AddTag(FGameplayTag::RequestGameplayTag(FName("Ability.Death")));
			GetOwningAbilitySystemComponent()->TryActivateAbilitiesByTag(AbilityTagContainer);
		}
	}
}

