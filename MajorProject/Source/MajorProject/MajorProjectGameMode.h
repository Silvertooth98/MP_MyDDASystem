// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MajorProjectGameMode.generated.h"

UCLASS(minimalapi)
class AMajorProjectGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AMajorProjectGameMode();

	// Set the level name
	UFUNCTION(BlueprintCallable, Category = "Level Name")
	FString SetLevelName(FString LevelName);
	// Get the level name
	UFUNCTION(BlueprintCallable, Category = "Level Name")
	FString GetLevelName() { return m_currentLevel; }

	// Get the overall elapsed time within the level
	UFUNCTION(BlueprintCallable)
	int GetElapsedTime();
	
	// Get the seconds count
	UFUNCTION(BlueprintCallable)
	int GetSecondsInt() { return m_secondsInt; }

protected:
	int m_secondsInt;
	FString m_currentLevel;

};