// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/FalloutEffectActor.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"

// Sets default values
AFalloutEffectActor::AFalloutEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRootComponent = CreateDefaultSubobject<USceneComponent>("SceneRoot");
	SetRootComponent(SceneRootComponent);
}

// Called when the game starts or when spawned
void AFalloutEffectActor::BeginPlay()
{
	Super::BeginPlay();
}

void AFalloutEffectActor::ApplyEffectToTarget(AActor* EffectTarget, TSubclassOf<UGameplayEffect> GameplayEffectClass)
{
	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(EffectTarget);

	if (TargetASC == nullptr) return;

	// GameplayEffectClass must be Set in Blueprint Side
	check(GameplayEffectClass);

	FGameplayEffectContextHandle EffectContextHandle = TargetASC->MakeEffectContext();
	EffectContextHandle.AddSourceObject(this);
	FGameplayEffectSpecHandle GameplayEffectSpecHandle = TargetASC->MakeOutgoingSpec(GameplayEffectClass, 1.0f, EffectContextHandle);

	if (GameplayEffectSpecHandle.IsValid())
	{
		FActiveGameplayEffectHandle ActiveHandle = TargetASC->ApplyGameplayEffectSpecToSelf(*GameplayEffectSpecHandle.Data);
		const bool bIsInfinite = GameplayEffectSpecHandle.Data.Get()->Def.Get()->DurationPolicy == EGameplayEffectDurationType::Infinite;
		if (bIsInfinite && InfiniteEffectRemovalPolicy == EEffectRemovalPolicy::RemoveEffect)
		{
			ActiveEffectHandles.Add(ActiveHandle, TargetASC);
		}
	}

}	

void AFalloutEffectActor::RemoveEffectFromTarget(AActor* EffectTarget)
{
	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(EffectTarget);

	if (!IsValid(TargetASC)) return;

	TArray<FActiveGameplayEffectHandle> HandlesToRemove;
	for (auto activeHandlePair : ActiveEffectHandles)
	{
		if (activeHandlePair.Value == TargetASC)
		{
			TargetASC->RemoveActiveGameplayEffect(activeHandlePair.Key);
			HandlesToRemove.Add(activeHandlePair.Key);
		}
	}

	for (auto& handleToRemove : HandlesToRemove)
	{
		ActiveEffectHandles.FindAndRemoveChecked(handleToRemove);
	}
}

