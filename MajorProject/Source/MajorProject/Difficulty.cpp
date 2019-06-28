// Fill out your copyright notice in the Description page of Project Settings.

#define print(text) if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.0, FColor::Green, text)

#include "Difficulty.h"
#include "Engine/GameEngine.h"

Difficulty::Difficulty()
{
	_state = new DifficultyState();
}

void Difficulty::SaveDataToTextFile(FString Level, FString LevelSection, FString Difficulty,
	FString TotalTime, FString TotalMovementTime,
	FString TotalInLightTime, FString TextFileNumber)
{
	// Save difficulty details to text file
	m_textFile->SaveTxt(FString(Level + " - Section " + LevelSection) +
						FString("\r\nDifficulty Set to: " + Difficulty) +
						FString("\r\nTotal Time: " + TotalTime) +
						FString("\r\nTotal Movement Time: " + TotalMovementTime) +
						FString("\r\nTotal In Light Time: " + TotalInLightTime),
						FString("TextFiles/" + Level + "/Test" + TextFileNumber + ".txt"));
}

void Difficulty::Update(EStates EState)
{
	class DifficultyState* state = _state->Update(*this, EState);

	if (state != nullptr)
	{
		print("!= nullptr");
		_state->Exit(*this);

		delete _state;
		_state = state;

		_state->Enter(*this);
		m_currentDiff = _state->GetStrDiff();
		m_stateEDiff = _state->GetDifficulty();
	}
}

Difficulty::~Difficulty()
{
	print("Deleting _state pointer");
	delete _state;
}