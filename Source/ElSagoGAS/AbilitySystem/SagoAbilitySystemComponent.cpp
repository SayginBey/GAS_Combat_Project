// Fill out your copyright notice in the Description page of Project Settings.


#include "SagoAbilitySystemComponent.h"

#include "ElSagoGAS/Characters/SagoBaseCharacter.h"


// Sets default values for this component's properties
USagoAbilitySystemComponent::USagoAbilitySystemComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USagoAbilitySystemComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void USagoAbilitySystemComponent::OnRep_ActivateAbilities()
{
	Super::OnRep_ActivateAbilities();
	
	ASagoBaseCharacter* Character = Cast<ASagoBaseCharacter>(GetOwner());
	if (!Character) {return;}
	/* Ilk herhangi bi ability activate oldugunda lastactiavatableAbilities bos oldugu icin direk o abilityler eklenir,
	bundan sonra her ability activate oldugunda lastactivatableAbilities bir onceki abilityler olur. LastActivatableAbilities ilk ability activate oldugunda setlenir yani. */
	if (LastActivatableAbilities.Num() != ActivatableAbilities.Items.Num())
	{
		Character->SendAbilitiesChangedEvent();
		LastActivatableAbilities = ActivatableAbilities.Items;
	}
	else
	{
		for (int32 i = 0; i < LastActivatableAbilities.Num(); i++)
		{
			if (LastActivatableAbilities[i].Ability != ActivatableAbilities.Items[i].Ability)
			{
				Character->SendAbilitiesChangedEvent();
				LastActivatableAbilities = ActivatableAbilities.Items;
				break;
			}
		}
	}
}


// Called every frame
void USagoAbilitySystemComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                                FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

