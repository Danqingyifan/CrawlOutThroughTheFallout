// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"
#include "FalloutPlayerState.generated.h"

UCLASS()
class THROUGHTHEFALLOUT_API AFalloutPlayerState : public APlayerState,public IAbilitySystemInterface
{	
	GENERATED_BODY()
public:
	AFalloutPlayerState();
	virtual class UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	class UAttributeSet* GetAttributeSet() const { return AttributeSet; }

protected:
	UPROPERTY()
	TObjectPtr<class UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<class UAttributeSet> AttributeSet;
};
