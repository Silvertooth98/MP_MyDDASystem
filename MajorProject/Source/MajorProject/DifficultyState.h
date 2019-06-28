#pragma once

#include "CoreMinimal.h"
#include "Difficulty.h"
#include "TextFile.h"
#include "MyEnums.h"

class MAJORPROJECT_API DifficultyState
{
public:
	DifficultyState();
	virtual ~DifficultyState();

	EDifficulty GetDifficulty() { return ESTATEDIFF; }
	FString GetStrDiff() { return m_currentDiff; }

	virtual DifficultyState* Update(class Difficulty& diff, EStates State);
	virtual void Enter(class Difficulty& diff) {}
	virtual void Exit(class Difficulty& diff) {}

protected:

	UTextFile* m_textFile;

	EDifficulty ESTATEDIFF = EDifficulty::NONE;
	EStates ESTATE = EStates::NONE;

	FString m_currentDiff;

	const FString EASY01DIFF = "EASY_01";
	const FString EASY02DIFF = "EASY_02";
	const FString MEDIUM01DIFF = "MEDIUM_01";
	const FString MEDIUM02DIFF = "MEDIUM_02";
	const FString HARD01DIFF = "HARD_01";
	const FString HARD02DIFF = "HARD_02";

};
