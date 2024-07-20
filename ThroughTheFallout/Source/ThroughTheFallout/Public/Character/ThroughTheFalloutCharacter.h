// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "Logging/LogMacros.h"
#include "ThroughTheFalloutCharacter.generated.h"

UCLASS(config = Game)
class AThroughTheFalloutCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()
public:
	AThroughTheFalloutCharacter();
protected:
	virtual void BeginPlay();

	virtual class UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	class UAttributeSet* GetAttributeSet() const { return AttributeSet; }
protected:

	UPROPERTY()
	TObjectPtr<class UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<class UAttributeSet> AttributeSet;
};

