// Fill out your copyright notice in the Description page of Project Settings.

#define print(text) if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.0, FColor::Green, text)

#include "Difficulty.h"
#include "Engine/GameEngine.h"

Difficulty::Difficulty()
{
	// Create a new DifficultyState pointer
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
	// Make local pointer variable to the DifficultyState class and then make the
	// variable equal to the current DifficultyState class's Update function returned value
	class DifficultyState* state = _state->Update(*this, EState);

	// If the local pointer variable does not equal a nullptr
	if (state != nullptr)
	{
		// Exit the current DifficultyState
		print("!= nullptr");
		_state->Exit(*this);

		// Delete the current DifficultyState pointer
		delete _state;
		// Make the DifficultyState pointer equal to the local variable pointer
		// which is equal to the returned value from the Update function
		_state = state;

		// Enter the new state and run the Enter function
		_state->Enter(*this);
		
		// Set the current difficulty FString to the current difficulty
		// by calling the GetStrDiff function from the new state pointer
		m_currentDiff = _state->GetStrDiff();
		// Set the difficulty enum value to the newly set difficulty
		m_stateEDiff = _state->GetDifficulty();
	}
}

Difficulty::~Difficulty()
{
	// Delete the DifficultyState pointer
	print("Deleting _state pointer");
	delete _state;
}