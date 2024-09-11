// Copyright Epic Games, Inc. All Rights Reserved.


#include "Player/ThroughTheFalloutPlayerController.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "EnhancedInputSubsystems.h"
#include "GameplayTagContainer.h"
#include "AbilitySystem/FalloutAbilitySystemComponent.h"
#include "AbilitySystem/FalloutAbilitySystemLibrary.h"
#include "Engine/LocalPlayer.h"
#include "Input/FalloutInputComponent.h"

void AThroughTheFalloutPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// get the enhanced input subsystem
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		// add the mapping context so we get controls
		Subsystem->AddMappingContext(InputMappingContext, 0);
	}
}

void AThroughTheFalloutPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Bind actions to input
	if (UFalloutInputComponent* FalloutInputComponent = CastChecked<UFalloutInputComponent>(InputComponent))
	{
		FalloutInputComponent->BindAbilityActions
		(
			InputConfig, this,
			&AThroughTheFalloutPlayerController::AbilityInputTagPressed,
			&AThroughTheFalloutPlayerController::AbilityInputTagHeld,
			&AThroughTheFalloutPlayerController::AbilityInputTagReleased
		);
	}
}

void AThroughTheFalloutPlayerController::AbilityInputTagPressed(FGameplayTag InputTag)
{
	//GEngine->AddOnScreenDebugMessage(1,3.f,FColor::Blue, *InputTag.ToString());
}

void AThroughTheFalloutPlayerController::AbilityInputTagHeld(FGameplayTag InputTag)
{
	GEngine->AddOnScreenDebugMessage(2, 3.f, FColor::Green, *InputTag.ToString());

	if(GetASC() == nullptr)
	{
		return;
	}
	
	GetASC()->AbilityInputTagHeld(InputTag);
}

void AThroughTheFalloutPlayerController::AbilityInputTagReleased(FGameplayTag InputTag)
{
	GEngine->AddOnScreenDebugMessage(3, 3.f, FColor::Yellow, *InputTag.ToString());

	if(GetASC() == nullptr)
	{
		return;
	}
	
	GetASC()->AbilityInputTagReleased(InputTag);
}

UFalloutAbilitySystemComponent* AThroughTheFalloutPlayerController::GetASC()
{
	if (FalloutASC == nullptr)
	{
		FalloutASC = CastChecked<UFalloutAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetPawn<APawn>()));
	}
	return FalloutASC;
}
