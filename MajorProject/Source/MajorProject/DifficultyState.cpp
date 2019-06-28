// Fill out your copyright notice in the Description page of Project Settings.
#define print(text) if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.0, FColor::Green, text)

#include "DifficultyState.h"
#include "EasyState.h"
#include "Engine/GameEngine.h"

DifficultyState::DifficultyState()
{
}

DifficultyState::~DifficultyState()
{
}

DifficultyState* DifficultyState::Update(Difficulty& diff, EStates State)
{
	switch (State)
	{
	case EStates::NONE:
		print("returning nullptr");
		return nullptr;
		break;
	case EStates::EASY:
	{
		print("returning Easy");
		DifficultyState* es = new EasyState();
		return es;
		break;
	}
	case EStates::MEDIUM:
	{
		print("returning Medium");
		DifficultyState* ms = new MediumState();
		return ms;
		break;
	}
	case EStates::HARD:
	{
		print("returning Hard");
		DifficultyState* hs = new HardState();
		return hs;
		break;
	}
	default:
		print("returning nullptr");
		return nullptr;
		break;
	}

	return nullptr;
}
