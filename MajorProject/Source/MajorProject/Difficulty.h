// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TextFile.h"
#include "DifficultyState.h"
#include "MyEnums.h"

class MAJORPROJECT_API Difficulty
{
public:
	Difficulty();
	virtual ~Difficulty();

	void SaveDataToTextFile(FString Level, FString LevelSection, FString Difficulty,
							FString TotalTime, FString TotalMovementTime,
							FString TotalInLightTime, FString TextFileNumber);

	EDifficulty GetDifficulty() { return m_Difficulty; }
	EDifficulty GetStateEDiff() { return m_stateEDiff; }
	FString GetStrDiff() { return m_currentDiff; }

	virtual void Update(EStates EState);

private:
	UTextFile* m_textFile;
	class DifficultyState* _state;

	EDifficulty m_Difficulty = EDifficulty::NONE;
	EDifficulty m_stateEDiff = EDifficulty::NONE;

	FString m_currentDiff;
};
