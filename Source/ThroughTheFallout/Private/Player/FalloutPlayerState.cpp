// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/FalloutPlayerState.h"

#include "AbilitySystem/FalloutAbilitySystemComponent.h"
#include "AbilitySystem/FalloutAttributeSet.h"

#include "Net/UnrealNetwork.h"

AFalloutPlayerState::AFalloutPlayerState() 
{
    // AbilitySystemComponent
    AbilitySystemComponent = CreateDefaultSubobject<UFalloutAbilitySystemComponent>("AbilitySystemComponent");
    AbilitySystemComponent->SetIsReplicated(true);
    AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

    // AttributeSet
    AttributeSet = CreateDefaultSubobject<UFalloutAttributeSet>("AttributeSet");

    // Multiplayer Settings
    NetUpdateFrequency = 100.f;
}

void AFalloutPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(AFalloutPlayerState, Level);
}

UAbilitySystemComponent* AFalloutPlayerState::GetAbilitySystemComponent() const
{
    return AbilitySystemComponent;
}

void AFalloutPlayerState::OnRep_Level(int32 OldLevel)
{

}
