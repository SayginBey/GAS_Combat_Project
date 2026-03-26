// Fill out your copyright notice in the Description page of Project Settings.


#include "SagoAttributeSet.h"

#include "GameplayEffectExtension.h"

USagoAttributeSet::USagoAttributeSet()
{
	Stamina = 100.f;
	MaxStamina = 100.f;
	Health = 100.f;
	MaxHealth = 100.f;
}

void USagoAttributeSet::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME_CONDITION_NOTIFY( USagoAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY( USagoAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY( USagoAttributeSet, Stamina, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY( USagoAttributeSet, MaxStamina, COND_None, REPNOTIFY_Always);	
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
}

void USagoAttributeSet::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		//Set health already clamping the new value. So we don't have to clamp again.
		SetHealth(GetHealth());
		
		if (Data.EffectSpec.Def->GetAssetTags().HasTag(FGameplayTag::RequestGameplayTag(FName("Effects.DoHitReaction"))))
		{
			FGameplayTagContainer AbilityTagContainer;
			AbilityTagContainer.AddTag(FGameplayTag::RequestGameplayTag(FName("Ability.HitReaction")));
			GetOwningAbilitySystemComponent()->TryActivateAbilitiesByTag(AbilityTagContainer);
		}
	}
	else if (Data.EvaluatedData.Attribute == GetStaminaAttribute())
	{
		//Set Stamina already clamping the new value. So we don't have to clamp again.
		SetStamina(GetStamina());
	}
}

void USagoAttributeSet::PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue)
{
	Super::PostAttributeChange(Attribute, OldValue, NewValue);
	
	if (Attribute == GetHealthAttribute())
	{
		if (NewValue <= 0.f)
		{
			FGameplayTagContainer AbilityTagContainer;
			AbilityTagContainer.AddTag(FGameplayTag::RequestGameplayTag(FName("Ability.Death")));
			GetOwningAbilitySystemComponent()->TryActivateAbilitiesByTag(AbilityTagContainer);
		}
	}
}

