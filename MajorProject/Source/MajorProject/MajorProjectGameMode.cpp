// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "MajorProjectGameMode.h"
#include "MajorProjectHUD.h"
#include "MajorProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/GameEngine.h"
#include "Kismet/GameplayStatics.h"

AMajorProjectGameMode::AMajorProjectGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AMajorProjectHUD::StaticClass();
}

int AMajorProjectGameMode::GetElapedTime(bool intSeconds, bool floatSeconds)
{
	m_secondsFlt = UGameplayStatics::GetTimeSeconds(GetWorld());

	if (intSeconds)
	{
		m_secondsInt = (int)m_secondsFlt;
		m_secondsInInt = true;

		return m_secondsInt;
	}
	else if (floatSeconds)
	{
		m_secondsInInt = false;

		return m_secondsFlt;
	}

	return 0;
}