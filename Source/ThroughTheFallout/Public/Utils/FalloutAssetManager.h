// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "FalloutAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class THROUGHTHEFALLOUT_API UFalloutAssetManager : public UAssetManager
{
	GENERATED_BODY()

public:
	UFalloutAssetManager();

	UFalloutAssetManager& Get();
protected:

	virtual void StartInitialLoading() override;
};
