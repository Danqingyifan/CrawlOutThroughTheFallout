// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "AttributeInfoDataAsset.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FFalloutAttributeInfo
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AttributeInfo")
	FGameplayTag AttributeGameplayTag = FGameplayTag();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AttributeInfo")
	FText AttributeName = FText();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AttributeInfo")
	FText AttributeDescription = FText();

	UPROPERTY(BlueprintReadOnly, Category = "AttributeInfo")
	float AttributeValue = 0.0f;
};

UCLASS()
class THROUGHTHEFALLOUT_API UAttributeInfoDataAsset : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UAttributeInfoDataAsset();

	FFalloutAttributeInfo GetAttributeInfoForTag(const FGameplayTag& AttributeGameplayTag, bool bLogNotFound = false);

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AttributeInfoDataAsset")
	TArray<FFalloutAttributeInfo> AttributeInfos;

};
