// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "FalloutAttributeSet.generated.h"

/**
 *
 */

 // We usually use gameplay effects to imply the changes but not accessors
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
 	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
 	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
 	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

USTRUCT()
struct FEffectProperites
{
	GENERATED_BODY()
	FEffectProperites() {}

	UPROPERTY()
	FGameplayEffectContextHandle EffectContextHandle;

	UPROPERTY()
	UAbilitySystemComponent* SourceASC;

	UPROPERTY()
	AActor* SourceAvatarActor;

	UPROPERTY()
	AController* SourceController;

	UPROPERTY()
	ACharacter* SourceCharacter;

	UPROPERTY()
	UAbilitySystemComponent* TargetASC;

	UPROPERTY()
	AActor* TargetAvatarActor;

	UPROPERTY()
	AController* TargetController;

	UPROPERTY()
	ACharacter* TargetCharacter;
};



UCLASS()
class THROUGHTHEFALLOUT_API UFalloutAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UFalloutAttributeSet();
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const;

	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;

	virtual void PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const override;


public:
	// FGameplayAttributeData
	// S.P.E.C.I.A.L. Primary Attributes
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Strength, Category = "PrimaryAttributes")
	FGameplayAttributeData Strength;
	ATTRIBUTE_ACCESSORS(UFalloutAttributeSet, Strength);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Perception, Category = "PrimaryAttributes")
	FGameplayAttributeData Perception;
	ATTRIBUTE_ACCESSORS(UFalloutAttributeSet, Perception);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Endurance, Category = "PrimaryAttributes")
	FGameplayAttributeData Endurance;
	ATTRIBUTE_ACCESSORS(UFalloutAttributeSet, Endurance);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Charisma, Category = "PrimaryAttributes")
	FGameplayAttributeData Charisma;
	ATTRIBUTE_ACCESSORS(UFalloutAttributeSet, Charisma);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Intelligence, Category = "PrimaryAttributes")
	FGameplayAttributeData Intelligence;
	ATTRIBUTE_ACCESSORS(UFalloutAttributeSet, Intelligence);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Agility, Category = "PrimaryAttributes")
	FGameplayAttributeData Agility;
	ATTRIBUTE_ACCESSORS(UFalloutAttributeSet, Agility);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Luck, Category = "PrimaryAttributes")
	FGameplayAttributeData Luck;
	ATTRIBUTE_ACCESSORS(UFalloutAttributeSet, Luck);

	//On_Rep
	UFUNCTION()
	void OnRep_Strength(const FGameplayAttributeData& OldStrength);

	UFUNCTION()
	void OnRep_Perception(const FGameplayAttributeData& OldPerception);

	UFUNCTION()
	void OnRep_Endurance(const FGameplayAttributeData& OldEndurance);

	UFUNCTION()
	void OnRep_Charisma(const FGameplayAttributeData& OldCharisma);

	UFUNCTION()
	void OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence);

	UFUNCTION()
	void OnRep_Agility(const FGameplayAttributeData& OldAgility);

	UFUNCTION()
	void OnRep_Luck(const FGameplayAttributeData& OldLuck);

public:

	// Secondary Attributes


	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "SecondaryAttributes")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UFalloutAttributeSet, MaxHealth);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxStamina, Category = "SecondaryAttributes")
	FGameplayAttributeData MaxStamina;
	ATTRIBUTE_ACCESSORS(UFalloutAttributeSet, MaxStamina);

	//On_Rep
	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth);

	UFUNCTION()
	void OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina);

	//Vital Attributes
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "VitalAttributes")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UFalloutAttributeSet, Health);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Stamina, Category = "VitalAttributes")
	FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS(UFalloutAttributeSet, Stamina);

	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth);

	UFUNCTION()
	void OnRep_Stamina(const FGameplayAttributeData& OldStamina);
private:
	void SetEffectProperites(const FGameplayEffectModCallbackData& Data, FEffectProperites& EffectProperites) const;
};

