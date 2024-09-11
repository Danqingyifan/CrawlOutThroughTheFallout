// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/FalloutHUD.h"
#include "UI/WidgetController/OverlayWidgetController.h"
#include "UI/WidgetController/AttributeMenuWidgetController.h"

AFalloutHUD::AFalloutHUD()
{

}

void AFalloutHUD::InitializeOverlayWidget(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{

}

UOverlayWidgetController* AFalloutHUD::GetOverLayWidgetController(const FWidgetControllerParams& WCParams)
{
	return CreateOrGetWidgetController<UOverlayWidgetController>(OverlayWidgetController, OverlayWidgetControllerClass, WCParams);
}

class UAttributeMenuWidgetController* AFalloutHUD::GetAttributeMenuWidgetController(const FWidgetControllerParams& WCParams)
{
	return CreateOrGetWidgetController<UAttributeMenuWidgetController>(AttributeMenuWidgetController, AttributeMenuWidgetControllerClass, WCParams);
}
