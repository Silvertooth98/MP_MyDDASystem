// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "MajorProjectGameMode.h"
#include "MajorProjectHUD.h"
#include "MajorProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/GameEngine.h"
#include "Kismet/GameplayStatics.h"

AMajorProjectGameMode::AMajorProjectGameMode() : Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AMajorProjectHUD::StaticClass();
}

FString AMajorProjectGameMode::SetLevelName(FString LevelName)
{
	m_currentLevel = LevelName;

	return m_currentLevel;
}

int AMajorProjectGameMode::GetElapsedTime()
{
	m_secondsInt = (int)UGameplayStatics::GetTimeSeconds(GetWorld());

	return m_secondsInt;
}