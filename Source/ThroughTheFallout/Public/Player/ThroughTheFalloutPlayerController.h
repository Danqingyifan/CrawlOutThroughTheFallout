// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ThroughTheFalloutPlayerController.generated.h"

class UFalloutAbilitySystemComponent;
class UFalloutInputConfig;
struct FGameplayTag;
class UInputMappingContext;

/**
 *
 */
UCLASS()
class THROUGHTHEFALLOUT_API AThroughTheFalloutPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	/** Input Mapping Context to be used for player input */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* InputMappingContext;
	UPROPERTY(EditDefaultsOnly, Category= Input)
	TObjectPtr<UFalloutInputConfig> InputConfig;

protected:
	// Begin Actor interface
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	// End Actor interface

private:
	void AbilityInputTagPressed(FGameplayTag InputTag);
	void AbilityInputTagHeld(FGameplayTag InputTag);
	void AbilityInputTagReleased(FGameplayTag InputTag);

	UFalloutAbilitySystemComponent* GetASC();
	TObjectPtr<UFalloutAbilitySystemComponent> FalloutASC;
};
