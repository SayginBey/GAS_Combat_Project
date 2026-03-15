// Fill out your copyright notice in the Description page of Project Settings.


#include "SagoBaseCharacter.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "ElSagoGAS/AbilitySystem/SagoAttributeSet.h"

// Sets default values
ASagoBaseCharacter::ASagoBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(AscReplicationMode);
	
	AttributeSet = CreateDefaultSubobject<USagoAttributeSet>(TEXT("AttributeSet"));

}

void ASagoBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASagoBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASagoBaseCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	
	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->InitAbilityActorInfo(this,this);
		
		/* We grant abilities here because this function only runs on the server, and giving abilities only works on the server. 
		 * If we were to give abilities in BeginPlay, we would have to check for authority and it would be possible for 
		 * clients to miss out on being granted abilities if they join late.*/
		GrantAbilities(StartupAbilities);
	}
}

void ASagoBaseCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	
	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->InitAbilityActorInfo(this,this);
	}
}

void ASagoBaseCharacter::SendAbilitiesChangedEvent()
{
	FGameplayEventData EventData;
	EventData.Instigator = this;
	EventData.Target = this;
	UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(this, FGameplayTag::RequestGameplayTag(FName("Event.Abilities.Changed")),
		EventData);
	
}

TArray<FGameplayAbilitySpecHandle> ASagoBaseCharacter::GrantAbilities(
	TArray<TSubclassOf<UGameplayAbility>> AbilitiesToGrant)
{
	//Give ability only works on the server, so we check for authority and if the ability system component is valid before granting abilities.
	if (!AbilitySystemComponent || !HasAuthority())
	{
		return TArray<FGameplayAbilitySpecHandle>();
	}
	
	TArray<FGameplayAbilitySpecHandle> GrantedAbilityHandles;
	for (const auto& Ability : AbilitiesToGrant)
	{
		if (Ability)
		{
			FGameplayAbilitySpecHandle AbilityHandle = GetAbilitySystemComponent()->GiveAbility(FGameplayAbilitySpec(Ability,1, INDEX_NONE, this));
			SendAbilitiesChangedEvent();
			GrantedAbilityHandles.Add(AbilityHandle);
		}
	}
	return GrantedAbilityHandles;
}

void ASagoBaseCharacter::RemoveAbilities(TArray<FGameplayAbilitySpecHandle> AbilitiesToRemove) const
{
	if (!AbilitySystemComponent || !HasAuthority()) { return; }
	
	for (const auto& AbilityHandle : AbilitiesToRemove)
	{
		GetAbilitySystemComponent()->ClearAbility(AbilityHandle);
	}
}

void ASagoBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

UAbilitySystemComponent* ASagoBaseCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

