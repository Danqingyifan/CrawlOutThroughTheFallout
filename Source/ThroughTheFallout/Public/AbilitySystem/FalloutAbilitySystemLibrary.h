// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"

#include "UI/HUD/FalloutHUD.h"
#include "Player/FalloutPlayerState.h"
#include "AbilitySystemComponent.h"
#include "UI/WidgetController/OverlayWidgetController.h"

#include "FalloutAbilitySystemLibrary.generated.h"

/**
 *
 */
UCLASS()
class THROUGHTHEFALLOUT_API UFalloutAbilitySystemLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	// Always Static function
	UFUNCTION(BlueprintPure, Category = "FalloutAbilitySystemLibrary|WidgetController")
	static UOverlayWidgetController* GetHUDWidgetController(const UObject* WorldContextObject);
};

UOverlayWidgetController* UFalloutAbilitySystemLibrary::GetHUDWidgetController(const UObject* WorldContextObject)
{
	if (APlayerController* PlayerController = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
	{
		if (AFalloutHUD* HUD = Cast<AFalloutHUD>(PlayerController->GetHUD()))
		{
			AFalloutPlayerState* PlayerState = PlayerController->GetPlayerState<AFalloutPlayerState>();
			UAbilitySystemComponent* AbilitySystemComponent = PlayerState->GetAbilitySystemComponent();
			UAttributeSet* AttributeSet = PlayerState->GetAttributeSet();
			const FWidgetControllerParams WidgetControllerParams(PlayerController, PlayerState, AbilitySystemComponent, AttributeSet);

			return HUD->GetOverLayWidgetController(WidgetControllerParams);
		}
	}
	return nullptr;
}
