// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "SagoBaseCharacter.generated.h"

class USagoAttributeSet;
enum class EGameplayEffectReplicationMode : uint8;
class UAbilitySystemComponent;

UCLASS()
class ELSAGOGAS_API ASagoBaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASagoBaseCharacter();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ability System")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ability System")
	TObjectPtr<USagoAttributeSet> AttributeSet;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ability System")
	TArray<TSubclassOf<UGameplayAbility>> StartupAbilities;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability System")
	EGameplayEffectReplicationMode AscReplicationMode = EGameplayEffectReplicationMode::Mixed;
	
	//For the init ability actor info.
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
	void SendAbilitiesChangedEvent();

	UFUNCTION(BlueprintCallable, Category = "Ability")
	TArray<FGameplayAbilitySpecHandle> GrantAbilities(TArray<TSubclassOf<UGameplayAbility>> AbilitiesToGrant);
	UFUNCTION(BlueprintCallable, Category = "Ability")
	void RemoveAbilities(TArray<FGameplayAbilitySpecHandle> AbilitiesToRemove) const;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
};
