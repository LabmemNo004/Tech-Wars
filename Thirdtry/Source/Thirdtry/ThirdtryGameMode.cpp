// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "ThirdtryGameMode.h"
#include "ThirdtryPawn.h"

AThirdtryGameMode::AThirdtryGameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AThirdtryPawn::StaticClass();
}

