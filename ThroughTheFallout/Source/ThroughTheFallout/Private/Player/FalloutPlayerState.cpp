// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/FalloutPlayerState.h"

#include "AbilitySystem/FalloutAbilitySystemComponent.h"
#include "AbilitySystem/FalloutAttributeSet.h"

AFalloutPlayerState::AFalloutPlayerState() 
{
    // AbilitySystemComponent
    AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComponent");
    AbilitySystemComponent->SetIsReplicated(true);
    AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

    // AttributeSet
    AttributeSet = CreateDefaultSubobject<UAttributeSet>("AttributeSet");

    // Multiplayer Settings
    NetUpdateFrequency = 100.f;
}

UAbilitySystemComponent* AFalloutPlayerState::GetAbilitySystemComponent() const
{
    return AbilitySystemComponent;
}