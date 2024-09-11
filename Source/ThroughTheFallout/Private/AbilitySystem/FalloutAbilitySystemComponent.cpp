// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/FalloutAbilitySystemComponent.h"

#include "AbilitySystem/Abilities/FalloutGameplayAbility.h"

void UFalloutAbilitySystemComponent::AddCharacterAbilities(TArray<TSubclassOf<class UGameplayAbility>>& StartupAbilities)
{
	for (const TSubclassOf<UGameplayAbility> AbilityClass : StartupAbilities)
	{
		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(AbilityClass, 1);

		if (const UFalloutGameplayAbility* FalloutGameplayAbility = CastChecked<UFalloutGameplayAbility>(AbilitySpec.Ability))
		{
			AbilitySpec.DynamicAbilityTags.AddTag(FalloutGameplayAbility->StartupInputTag);
			GiveAbility(AbilitySpec);
		}
	}
}

void UFalloutAbilitySystemComponent::AbilityInputTagHeld(const FGameplayTag& InputTag)
{
	if (!InputTag.IsValid())
	{
		return;
	}
	TArray<FGameplayAbilitySpec> Abilities = GetActivatableAbilities();
	
	for (FGameplayAbilitySpec& AbilitySpec : Abilities)
	{
		if(AbilitySpec.DynamicAbilityTags.HasTagExact(InputTag))
		{
			AbilitySpecInputPressed(AbilitySpec);
			if(!AbilitySpec.IsActive())
			{
				TryActivateAbility(AbilitySpec.Handle);
			}
		}
	}

}

void UFalloutAbilitySystemComponent::AbilityInputTagReleased(const FGameplayTag& InputTag)
{
	if (!InputTag.IsValid())
	{
		return;
	}
	for (FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		if(AbilitySpec.DynamicAbilityTags.HasTagExact(InputTag))
		{
			AbilitySpecInputReleased(AbilitySpec);
		}
	}
}

void UFalloutAbilitySystemComponent::AbilitySpecInputReleased(FGameplayAbilitySpec& Spec)
{
	
}
