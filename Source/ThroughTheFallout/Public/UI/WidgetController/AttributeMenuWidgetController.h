// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/FalloutWidgetController.h"
#include "AttributeMenuWidgetController.generated.h"

class UAttributeInfoDataAsset;
struct FFalloutAttributeInfo;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAttributeInfoSignature,const FFalloutAttributeInfo&,Info);

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class THROUGHTHEFALLOUT_API UAttributeMenuWidgetController : public UFalloutWidgetController
{
	GENERATED_BODY()

public:
	UAttributeMenuWidgetController();

	virtual void BindCallbacksToDependencies() override;
public:
	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FAttributeInfoSignature AttributeInfoDelegate;
protected:
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UAttributeInfoDataAsset> AttributeInfoDataAsset;
	
};
