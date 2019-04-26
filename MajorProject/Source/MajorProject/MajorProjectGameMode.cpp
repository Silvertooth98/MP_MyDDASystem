// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "MajorProjectGameMode.h"
#include "MajorProjectHUD.h"
#include "MajorProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMajorProjectGameMode::AMajorProjectGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AMajorProjectHUD::StaticClass();
}
