// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "forthtryGameMode.h"
#include "forthtryPawn.h"

AforthtryGameMode::AforthtryGameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AforthtryPawn::StaticClass();
}

