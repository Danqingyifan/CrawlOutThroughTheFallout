// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Data/AttributeInfoDataAsset.h"

UAttributeInfoDataAsset::UAttributeInfoDataAsset()
{

}

FFalloutAttributeInfo UAttributeInfoDataAsset::GetAttributeInfoForTag(const FGameplayTag& AttributeGameplayTag, bool bLogNotFound)
{
	for (auto& AttributeInfo : AttributeInfos)
	{
		if (AttributeInfo.AttributeGameplayTag.MatchesTagExact(AttributeGameplayTag))
		{
			return AttributeInfo;
		}
	}

	if(bLogNotFound)
	{
		UE_LOG(LogTemp, Warning, TEXT("AttributeInfoDataAsset: AttributeInfo not found for tag %s"), *AttributeGameplayTag.ToString());
	}

	return FFalloutAttributeInfo();
}
