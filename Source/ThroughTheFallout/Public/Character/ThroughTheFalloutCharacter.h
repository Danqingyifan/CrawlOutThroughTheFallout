// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "Interaction/Interface/CombatInterface.h"
#include "Logging/LogMacros.h"
#include "ThroughTheFalloutCharacter.generated.h"

UCLASS(config = Game)
class AThroughTheFalloutCharacter : public ACharacter, public IAbilitySystemInterface,public ICombatInterface
{
	GENERATED_BODY()
public:
	AThroughTheFalloutCharacter();
protected:
	virtual void BeginPlay();

	virtual class UAbilitySystemComponent* GetAbilitySystemComponent() const override;
protected:
	class UAttributeSet* GetAttributeSet() const { return AttributeSet; }

protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AbilitySystemComponent")
	TObjectPtr<class UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AttributeSet")
	TObjectPtr<class UAttributeSet> AttributeSet;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character")
	TSubclassOf<class UGameplayEffect> InitializePrimaryAttributeEffect;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character")
	TSubclassOf<class UGameplayEffect> InitializeSecondaryAttributeEffect;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character")
	TSubclassOf<class UGameplayEffect> InitializeVitalAttributeEffect;
protected:
	void ApplyEffectToSelf(TSubclassOf<class UGameplayEffect> Effect, float Level = 1.0f) const;
	void InitializeDefaultAttributes() const;
	void AddCharacterAbilities();
private:
	UPROPERTY(EditAnywhere,Category="GAS|GameAbilities")
	TArray<TSubclassOf<class UGameplayAbility>> StartupAbilities;
};

