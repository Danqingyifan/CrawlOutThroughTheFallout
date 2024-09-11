// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FalloutUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class THROUGHTHEFALLOUT_API UFalloutUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);

protected:
	UPROPERTY(BlueprintReadOnly, Category = "Widget")
	TObjectPtr<UObject> WidgetController;

	// Implemented in Blueprint
	UFUNCTION(BlueprintImplementableEvent)
	void OnWidgetControllerSet();
};
