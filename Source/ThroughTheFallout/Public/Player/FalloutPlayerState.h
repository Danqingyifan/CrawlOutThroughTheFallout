// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"
#include "FalloutPlayerState.generated.h"

UCLASS()
class THROUGHTHEFALLOUT_API AFalloutPlayerState : public APlayerState,public IAbilitySystemInterface
{	
	GENERATED_BODY()
public:
	AFalloutPlayerState();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual class UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	class UAttributeSet* GetAttributeSet() const { return AttributeSet; }

	FORCEINLINE int32 GetPlayerLevel() const { return Level; }
protected:
		
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	TObjectPtr<class UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AttributeSet")
	TObjectPtr<class UAttributeSet> AttributeSet;

private:
	UFUNCTION()
	void OnRep_Level(int32 OldLevel);

	UPROPERTY(VisibleAnywhere,ReplicatedUsing = OnRep_Level)
	int32 Level = 1;
};
