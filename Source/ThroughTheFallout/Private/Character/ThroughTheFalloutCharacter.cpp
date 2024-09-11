// Copyright Epic Games, Inc. All Rights Reserved.

#include "Character/ThroughTheFalloutCharacter.h"
#include "Interaction/ThroughTheFalloutProjectile.h"
#include "AbilitySystem/FalloutAbilitySystemComponent.h"

#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "Engine/LocalPlayer.h"

AThroughTheFalloutCharacter::AThroughTheFalloutCharacter()
{

}

void AThroughTheFalloutCharacter::BeginPlay()
{
	Super::BeginPlay();
}

UAbilitySystemComponent* AThroughTheFalloutCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AThroughTheFalloutCharacter::ApplyEffectToSelf(TSubclassOf<class UGameplayEffect> GameplayEffect, float Level /*= 1.0f*/) const
{
	check(IsValid(GetAbilitySystemComponent()));
	check(GameplayEffect);

	FGameplayEffectContextHandle EffectContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	EffectContextHandle.AddSourceObject(this);

	const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(GameplayEffect, Level, EffectContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
}

void AThroughTheFalloutCharacter::InitializeDefaultAttributes() const
{
	//The order of initialization matters here, as SecondaryAttribute depend on PrimaryAttribute being initialized first.
	ApplyEffectToSelf(InitializePrimaryAttributeEffect);
	ApplyEffectToSelf(InitializeSecondaryAttributeEffect);
	ApplyEffectToSelf(InitializeVitalAttributeEffect);
}

void AThroughTheFalloutCharacter::AddCharacterAbilities()
{
	UFalloutAbilitySystemComponent* FalloutASC = CastChecked<UFalloutAbilitySystemComponent>(AbilitySystemComponent);
	
	if(!HasAuthority())
	{
		return;
	}

	FalloutASC->AddCharacterAbilities(StartupAbilities);
}

