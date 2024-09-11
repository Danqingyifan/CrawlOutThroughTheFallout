// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/FalloutAttributeSet.h"

#include "GameFramework/Character.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "GameplayEffectExtension.h"

#include "Net/UnrealNetwork.h"

UFalloutAttributeSet::UFalloutAttributeSet()
{
	//PrimaryAttribute means indenpendent attribute that all other secondaries depend on.
	//SecondaryAttributes can depend on PrimaryAttribute or other SecondaryAttributes.

	// S.P.E.C.I.A.L. as PrimaryAttribute


	// InitSecondaryAttributes
	InitHealth(100.f);
	InitMaxHealth(100.f);
	InitStamina(100.f);
	InitMaxStamina(100.f);
}

void UFalloutAttributeSet::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// Primary Attributes
	DOREPLIFETIME_CONDITION_NOTIFY(UFalloutAttributeSet, Strength, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFalloutAttributeSet, Perception, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFalloutAttributeSet, Endurance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFalloutAttributeSet, Charisma, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFalloutAttributeSet, Intelligence, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFalloutAttributeSet, Agility, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFalloutAttributeSet, Luck, COND_None, REPNOTIFY_Always);

	// Secondary Attributes
	DOREPLIFETIME_CONDITION_NOTIFY(UFalloutAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFalloutAttributeSet, MaxStamina, COND_None, REPNOTIFY_Always);
	
	// Vital Attributes
	DOREPLIFETIME_CONDITION_NOTIFY(UFalloutAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFalloutAttributeSet, Stamina, COND_None, REPNOTIFY_Always);
}

// Recommended Only for Clamping Attribute Values
void UFalloutAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp<float>(NewValue, 0.f, GetMaxHealth());
	}
	else if (Attribute == GetStaminaAttribute())
	{
		NewValue = FMath::Clamp<float>(NewValue, 0.f, GetMaxStamina());
	}
}



void UFalloutAttributeSet::PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const
{
	Super::PreAttributeBaseChange(Attribute, NewValue);
	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp<float>(NewValue, 0.f, GetMaxHealth());
	}
	else if (Attribute == GetStaminaAttribute())
	{
		NewValue = FMath::Clamp<float>(NewValue, 0.f, GetMaxStamina());
	}
}

void UFalloutAttributeSet::SetEffectProperites(const FGameplayEffectModCallbackData& Data, FEffectProperites& EffectProperites) const
{
	// Source = causer of the effect, Target = target of the effect(owner of the attribute set)
	EffectProperites.EffectContextHandle = Data.EffectSpec.GetContext();
	EffectProperites.SourceASC = Data.EffectSpec.GetContext().GetInstigatorAbilitySystemComponent();

	// Source
	if (IsValid(EffectProperites.SourceASC) &&
		EffectProperites.SourceASC->AbilityActorInfo.IsValid() &&
		EffectProperites.SourceASC->AbilityActorInfo->AvatarActor.IsValid())
	{
		EffectProperites.SourceAvatarActor = EffectProperites.SourceASC->AbilityActorInfo->AvatarActor.Get();
		EffectProperites.SourceController = EffectProperites.SourceASC->AbilityActorInfo->PlayerController.Get();

		if (EffectProperites.SourceController == nullptr && EffectProperites.SourceAvatarActor != nullptr)
		{
			if (const APawn* Pawn = Cast<APawn>(EffectProperites.SourceAvatarActor))
			{
				EffectProperites.SourceController = Pawn->GetController();
			}
		}
		if (EffectProperites.SourceController)
		{
			EffectProperites.SourceCharacter = Cast<ACharacter>(EffectProperites.SourceController->GetPawn());
		}
	}

	// Target
	if (Data.Target.AbilityActorInfo.IsValid() && Data.Target.AbilityActorInfo->AvatarActor.IsValid())
	{
		EffectProperites.TargetAvatarActor = Data.Target.AbilityActorInfo->AvatarActor.Get();
		EffectProperites.TargetController = Data.Target.AbilityActorInfo->PlayerController.Get();
		EffectProperites.TargetCharacter = Cast<ACharacter>(EffectProperites.TargetController->GetPawn());
		EffectProperites.TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(EffectProperites.TargetAvatarActor);
	}
}

void UFalloutAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	FEffectProperites EffectProperites;
	SetEffectProperites(Data, EffectProperites);
}


// -------------------------------------On_Rep functions--------------------------------------------

void UFalloutAttributeSet::OnRep_Strength(const FGameplayAttributeData& OldStrength)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UFalloutAttributeSet, Strength, OldStrength);
}

void UFalloutAttributeSet::OnRep_Perception(const FGameplayAttributeData& OldPerception)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UFalloutAttributeSet, Perception, OldPerception)
}

void UFalloutAttributeSet::OnRep_Endurance(const FGameplayAttributeData& OldEndurance)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UFalloutAttributeSet, Endurance, OldEndurance)
}

void UFalloutAttributeSet::OnRep_Charisma(const FGameplayAttributeData& OldCharisma)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UFalloutAttributeSet, Charisma, OldCharisma)
}

void UFalloutAttributeSet::OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UFalloutAttributeSet, Intelligence, OldIntelligence)
}

void UFalloutAttributeSet::OnRep_Agility(const FGameplayAttributeData& OldAgility)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UFalloutAttributeSet, Agility, OldAgility)
}

void UFalloutAttributeSet::OnRep_Luck(const FGameplayAttributeData& OldLuck)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UFalloutAttributeSet, Luck, OldLuck)
}

// Secondary Attributes On_Rep functions

void UFalloutAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldStamina)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UFalloutAttributeSet, Stamina, OldStamina);
}

void UFalloutAttributeSet::OnRep_MaxStamina(const FGameplayAttributeData& OldMaxHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UFalloutAttributeSet, MaxStamina, OldMaxHealth);
}

// Vital Attributes On_Rep functions

void UFalloutAttributeSet::OnRep_Health(const FGameplayAttributeData& OldMaxStamina)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UFalloutAttributeSet, MaxStamina, OldMaxStamina);
}
void UFalloutAttributeSet::OnRep_Stamina(const FGameplayAttributeData& OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UFalloutAttributeSet, Health, OldHealth);
}
