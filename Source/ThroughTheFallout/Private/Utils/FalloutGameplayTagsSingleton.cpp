// Fill out your copyright notice in the Description page of Project Settings.


#include "Utils/FalloutGameplayTagsSingleton.h"
#include "GameplayTagsManager.h"

FFalloutGameplayTagsSingleton FFalloutGameplayTagsSingleton::Instance;

void FFalloutGameplayTagsSingleton::InitializeNativeGameplayTags()
{
	// Primary
	Instance.Attributes_Primary_Strength = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Strength"), FString("Strength"));
	Instance.Attributes_Primary_Perception = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Perception"), FString("Perception"));
	Instance.Attributes_Primary_Endurance = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Endurance"), FString("Endurance"));
	Instance.Attributes_Primary_Charisma = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Charisma"), FString("Charisma"));
	Instance.Attributes_Primary_Intelligence = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Intelligence"), FString("Intelligence"));
	Instance.Attributes_Primary_Agility = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Agility"), FString("Agility"));
	Instance.Attributes_Primary_Luck = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Luck"), FString("Luck"));

	// Secondary
	Instance.Attributes_Secondary_MaxHealth = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.MaxHealth"), FString("MaxHealth"));
	Instance.Attributes_Secondary_MaxStamina = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.MaxStamina"), FString("MaxStamina"));

	// Vital
	Instance.Attributes_Vital_Health = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Vital.Health"), FString("Health"));
	Instance.Attributes_Vital_Stamina = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Vital.Stamina"), FString("Stamina"));

	// Input
	Instance.InputAction_LMB = Instance.InputAction_LMB = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputAction.LMB"), FString("LeftMouseButton"));
	
}
