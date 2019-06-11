// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TextFile.h"

enum class EDifficulty : uint8
{
	NONE,

	EASY_01,
	EASY_02,

	MEDIUM_01,
	MEDIUM_02,

	HARD_01,
	HARD_02
};

class MAJORPROJECT_API Difficulty
{
public:
	Difficulty();
	~Difficulty();

	void SaveDataToTextFile(FString Level, FString LevelSection, FString Difficulty,
							FString TotalTime, FString TotalMovementTime,
							FString TotalInLightTime, FString TextFileNumber);

	EDifficulty GetDifficulty() { return m_Difficulty; }
	EDifficulty SetDifficulty(EDifficulty SetDifficulty);

	void SetExactDifficulty(bool Easy = false, bool Medium = false, bool Hard = false,
		FString Level = "", FString SectionNum = "", FString TotalTime = "", FString TotalMovementTime = "", FString TotalInLightTime = "");
	void EasyDifficulty(FString Level, FString SectionNum, FString TotalTime, FString TotalMovementTime, FString TotalInLightTime);
	void PureEasyDifficulty(FString Level, FString SectionNum, FString TotalTime, FString TotalMovementTime, FString TotalInLightTime);
	void MediumDifficulty(FString Level, FString SectionNum, FString TotalTime, FString TotalMovementTime, FString TotalInLightTime);
	void HardDifficulty(FString Level, FString SectionNum, FString TotalTime, FString TotalMovementTime, FString TotalInLightTime);
	void PureHardDifficulty(FString Level, FString SectionNum, FString TotalTime, FString TotalMovementTime, FString TotalInLightTime);

private:
	UTextFile* m_textFile;
	EDifficulty m_Difficulty = EDifficulty::NONE;

};
