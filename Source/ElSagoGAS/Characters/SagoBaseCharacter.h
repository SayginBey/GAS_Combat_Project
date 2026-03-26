// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "ElSagoGAS/AbilitySystem/SagoBaseCharacterInterface.h"
#include "GameFramework/Character.h"
#include "SagoBaseCharacter.generated.h"

class USagoAbilitySystemComponent;
class USagoAttributeSet;
enum class EGameplayEffectReplicationMode : uint8;
class UAbilitySystemComponent;

UCLASS()
class ELSAGOGAS_API ASagoBaseCharacter : public ACharacter, public IAbilitySystemInterface, public ISagoBaseCharacterInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASagoBaseCharacter();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ability System")
	TObjectPtr<USagoAbilitySystemComponent> AbilitySystemComponent;
	
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
	
	UFUNCTION(BlueprintCallable, Category = "Ability")
	TArray<FGameplayAbilitySpecHandle> GrantAbilities(TArray<TSubclassOf<UGameplayAbility>> AbilitiesToGrant);
	UFUNCTION(BlueprintCallable, Category = "Ability")
	void RemoveAbilities(TArray<FGameplayAbilitySpecHandle> AbilitiesToRemove);
	
	/* SagoBaseCharacterInterface Start */
	virtual TArray<FGameplayAbilitySpecHandle> SagoGrantAbilities(TArray<TSubclassOf<UGameplayAbility>> AbilitiesToGrant) override;
	virtual void SagoRemoveAbilities(TArray<FGameplayAbilitySpecHandle> AbilitiesToRemove) override;
	 /* SagoBaseCharacterInterface End */
	
	/* Death Logic Start*/
	UFUNCTION(BlueprintCallable, Category = "Death")
	virtual void OnDeadTagChanged(const FGameplayTag CallbackTag, int32 NewCount);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Death")
	void HandleDeath();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Death")
	float DeathImpulseAmount = 25000.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Death")
	float DeathZImpulseAmount = 20000.f;
	/* Death Logic End*/
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	
	void SendAbilitiesChangedEvent();

};
