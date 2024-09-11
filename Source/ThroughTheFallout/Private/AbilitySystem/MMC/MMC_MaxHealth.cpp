// Fill out your copyright notice in the Description page of Project Settings.

#include "AbilitySystem/MMC/MMC_MaxHealth.h"
#include "AbilitySystem/FalloutAttributeSet.h"
#include "Interaction/Interface/CombatInterface.h"

UMMC_MaxHealth::UMMC_MaxHealth()
{
	EnduranceDef.AttributeToCapture = UFalloutAttributeSet::GetEnduranceAttribute();
	EnduranceDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	EnduranceDef.bSnapshot = false;

	RelevantAttributesToCapture.Add(EnduranceDef);
}

float UMMC_MaxHealth::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	FAggregatorEvaluateParameters EvaluationParams;
	EvaluationParams.SourceTags = SourceTags;
	EvaluationParams.TargetTags = TargetTags;

	float Endurance = 0.f;
	GetCapturedAttributeMagnitude(EnduranceDef, Spec, EvaluationParams, Endurance);
	Endurance = FMath::Max<float>(Endurance, 0.f);

	ICombatInterface* CombatInterface = Cast<ICombatInterface>(Spec.GetContext().GetSourceObject());
	const int32 CharacterLevel = CombatInterface->GetCharacterLevel();

	return 5 * Endurance + 2 * CharacterLevel;
}
