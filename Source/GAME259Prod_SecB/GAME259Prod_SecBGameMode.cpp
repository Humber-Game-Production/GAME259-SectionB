// Copyright Epic Games, Inc. All Rights Reserved.

#include "GAME259Prod_SecBGameMode.h"
#include "GAME259Prod_SecBCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGAME259Prod_SecBGameMode::AGAME259Prod_SecBGameMode()
{
	// set default pawn class to our Blueprinted character

	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ProjectAmulet/GameObjects/Blueprints/TPC"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
