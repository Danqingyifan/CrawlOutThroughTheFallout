// Copyright Epic Games, Inc. All Rights Reserved.

#include "Character/ThroughTheFalloutCharacter.h"
#include "Interaction/ThroughTheFalloutProjectile.h"

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
