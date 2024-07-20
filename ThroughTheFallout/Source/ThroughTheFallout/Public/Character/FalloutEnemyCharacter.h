// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/ThroughTheFalloutCharacter.h"
#include "FalloutEnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class THROUGHTHEFALLOUT_API AFalloutEnemyCharacter : public AThroughTheFalloutCharacter
{
	GENERATED_BODY()
public:
	AFalloutEnemyCharacter();
	virtual void BeginPlay();
private:
};
