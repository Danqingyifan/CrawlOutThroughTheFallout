// Fill out your copyright notice in the Description page of Project Settings.


#include "Input/FalloutInputConfig.h"

const UInputAction* UFalloutInputConfig::FindAbilityInputActionForTag(const FGameplayTag& InputTag, bool bLogNotFound) const
{
	for (const FFalloutInputAction& FalloutAction : AbilityInputActions)
	{
		if (FalloutAction.InputAction && FalloutAction.InputTag.MatchesTagExact(InputTag))
		{
			return FalloutAction.InputAction;
		}
	}

	if (bLogNotFound)
	{
		UE_LOG(LogTemp, Error, TEXT("Can't find InputTag [%s] in InputConfig [%s]."), *InputTag.ToString(), *GetNameSafe(this));
	}

	return nullptr;
}
