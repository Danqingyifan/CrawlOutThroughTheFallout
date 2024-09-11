// Fill out your copyright notice in the Description page of Project Settings.


#include "Utils/FalloutAssetManager.h"
#include "Utils/FalloutGameplayTagsSingleton.h"

UFalloutAssetManager::UFalloutAssetManager()
{

}

UFalloutAssetManager& UFalloutAssetManager::Get()
{
	check(GEngine)

	return *Cast<UFalloutAssetManager>(GEngine->AssetManager);
}

void UFalloutAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();
	
	FFalloutGameplayTagsSingleton::InitializeNativeGameplayTags();
}
