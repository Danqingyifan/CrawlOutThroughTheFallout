// Copyright Epic Games, Inc. All Rights Reserved.

#include "ThroughTheFalloutGameMode.h"
#include "ThroughTheFalloutCharacter.h"
#include "UObject/ConstructorHelpers.h"

AThroughTheFalloutGameMode::AThroughTheFalloutGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
