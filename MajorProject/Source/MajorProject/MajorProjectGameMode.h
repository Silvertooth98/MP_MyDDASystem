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

	UFUNCTION(BlueprintCallable, Category = "Level Name")
	FString SetLevelName(FString LevelName);
	UFUNCTION(BlueprintCallable, Category = "Level Name")
	FString GetLevelName() { return m_currentLevel; }

	UFUNCTION(BlueprintCallable)
	int GetElapedTime(bool intSeconds, bool floatSeconds);
	
	UFUNCTION(BlueprintCallable)
	int GetSecondsInt() { return m_secondsInt; }

	UFUNCTION(BlueprintCallable)
	int GetSecondsFlt() { return m_secondsFlt; }
	
	UFUNCTION(BlueprintCallable)
	bool GetIsSecondsInInt() { return m_secondsInInt; }

protected:
	float m_secondsFlt;
	int m_secondsInt;
	bool m_secondsInInt;
	FString m_currentLevel;

};