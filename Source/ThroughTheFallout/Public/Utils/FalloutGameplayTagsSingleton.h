// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

struct FFalloutGameplayTagsSingleton
{
public:
	static const FFalloutGameplayTagsSingleton& Get() { return Instance; }
	static void InitializeNativeGameplayTags();

	/* GameplayAttribute Tags */
	// Primary Attributes
	FGameplayTag Attributes_Primary_Strength;
	FGameplayTag Attributes_Primary_Perception;
	FGameplayTag Attributes_Primary_Endurance;
	FGameplayTag Attributes_Primary_Charisma;
	FGameplayTag Attributes_Primary_Intelligence;
	FGameplayTag Attributes_Primary_Agility;
	FGameplayTag Attributes_Primary_Luck;

	// Secondary Attributes
	FGameplayTag Attributes_Secondary_MaxHealth;
	FGameplayTag Attributes_Secondary_MaxStamina;

	// Vital Attributes
	FGameplayTag Attributes_Vital_Health;
	FGameplayTag Attributes_Vital_Stamina;

	/* InputAction Tags */
	FGameplayTag InputAction_LMB;

protected:

private:
	static FFalloutGameplayTagsSingleton Instance;
};
