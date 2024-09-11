// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "FalloutAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class THROUGHTHEFALLOUT_API UFalloutAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
public:
	void AddCharacterAbilities(TArray<TSubclassOf<class UGameplayAbility>>& StartupAbilities);
	void AbilityInputTagHeld(const FGameplayTag& InputTag);
	void AbilityInputTagReleased(const FGameplayTag& InputTag);
protected:
	void AbilitySpecInputReleased(FGameplayAbilitySpec& Spec) override;
};
