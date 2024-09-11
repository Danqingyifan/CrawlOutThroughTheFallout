// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/FalloutEnemyCharacter.h"

#include "AbilitySystem/FalloutAbilitySystemComponent.h"
#include "AbilitySystem/FalloutAttributeSet.h"


AFalloutEnemyCharacter::AFalloutEnemyCharacter()
{
    // AbilitySystemComponent
    AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComponent");
    AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

    // AttributeSet
    AttributeSet = CreateDefaultSubobject<UAttributeSet>("AttributeSet");
}

void AFalloutEnemyCharacter::BeginPlay()
{
    Super::BeginPlay();
    AbilitySystemComponent->InitAbilityActorInfo(this, this);
}

int32 AFalloutEnemyCharacter::GetCharacterLevel() const
{
    return Level;
}

