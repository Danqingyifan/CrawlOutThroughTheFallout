// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "FalloutInputConfig.h"
#include "FalloutInputComponent.generated.h"

/**
 * 
 */
UCLASS()
class THROUGHTHEFALLOUT_API UFalloutInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()
public:
	template<class UserClass,typename PressedFuncType,typename HeldFuncType,typename ReleasedFuncType>
	void BindAbilityActions(const UFalloutInputConfig* InputConfig, UserClass* UserObject,PressedFuncType PressedFunc,HeldFuncType HeldFunc,ReleasedFuncType ReleasedFunc);
};

template <class UserClass, typename PressedFuncType, typename HeldFuncType, typename ReleasedFuncType>
void UFalloutInputComponent::BindAbilityActions(const UFalloutInputConfig* InputConfig, UserClass* UserObject, PressedFuncType PressedFunc, HeldFuncType HeldFunc,
	ReleasedFuncType ReleasedFunc)
{
	check(InputConfig);

	for(FFalloutInputAction Action : InputConfig->AbilityInputActions)
	{
		if(Action.InputAction && Action.InputTag.IsValid())
		{
			if(PressedFunc)
			{
				BindAction(Action.InputAction, ETriggerEvent::Started, UserObject, PressedFunc, Action.InputTag);
			}
			if(HeldFunc)
			{
				BindAction(Action.InputAction, ETriggerEvent::Triggered, UserObject, HeldFunc, Action.InputTag);
			}
			if(ReleasedFunc)
			{
				BindAction(Action.InputAction, ETriggerEvent::Completed, UserObject, ReleasedFunc, Action.InputTag);
			}
		}
	}
}
