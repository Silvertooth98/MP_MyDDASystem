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
		return nullptr;
		break;
	case EStates::EASY:
	{
		DifficultyState* es = new EasyState();
		return es;
		break;
	}
	case EStates::MEDIUM:
	{
		DifficultyState* ms = new MediumState();
		return ms;
		break;
	}
	case EStates::HARD:
	{
		DifficultyState* hs = new HardState();
		return hs;
		break;
	}
	default:
		return nullptr;
		break;
	}

	return nullptr;
}
