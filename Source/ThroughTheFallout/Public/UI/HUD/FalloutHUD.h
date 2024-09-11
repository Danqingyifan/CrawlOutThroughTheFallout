// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"

#include "Player/FalloutPlayerState.h"
#include "AbilitySystemComponent.h"
#include "UI/WidgetController/FalloutWidgetController.h"

#include "FalloutHUD.generated.h"

/**
 *
 */
UCLASS()
class THROUGHTHEFALLOUT_API AFalloutHUD : public AHUD
{
	GENERATED_BODY()
public:
	AFalloutHUD();

	void InitializeOverlayWidget(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS);

	class UOverlayWidgetController* GetOverLayWidgetController(const FWidgetControllerParams& WCParams);
	class UAttributeMenuWidgetController* GetAttributeMenuWidgetController(const FWidgetControllerParams& WCParams);

	template<typename T>
	T* CreateOrGetWidgetController(TObjectPtr<T>& WidgetController, const TSubclassOf<UFalloutWidgetController> WidgetControllerClass, const FWidgetControllerParams& WCParams);

private:
	// Overlay Widget
	UPROPERTY()
	TObjectPtr<class UFalloutUserWidget> OverlayWidget;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UFalloutUserWidget> OverlayWidgetClass;

	// Ovverlay Widget Controller
	UPROPERTY()
	TObjectPtr<class UOverlayWidgetController> OverlayWidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UOverlayWidgetController> OverlayWidgetControllerClass;

	// AttributeMenu Widget
	UPROPERTY()
	TObjectPtr<class UFalloutUserWidget> AttributeMenuWidget;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UFalloutUserWidget> AttributeMenuWidgetClass;

	// AttributeMenu Widget Controller
	UPROPERTY()
	TObjectPtr<class UAttributeMenuWidgetController> AttributeMenuWidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UAttributeMenuWidgetController> AttributeMenuWidgetControllerClass;
};

template <typename T>
T* AFalloutHUD::CreateOrGetWidgetController(TObjectPtr<T>& WidgetController, const TSubclassOf<UFalloutWidgetController> WidgetControllerClass, const FWidgetControllerParams& WCParams)
{
	if (WidgetController == nullptr)
	{
		WidgetController = NewObject<T>(this, WidgetControllerClass);
		WidgetController->SetWidgetControllerParams(WCParams);
		WidgetController->BindCallbacksToDependencies();
	}
	return WidgetController;
};
