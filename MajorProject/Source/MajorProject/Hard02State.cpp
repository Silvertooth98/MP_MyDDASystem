#include "Hard02State.h"
#include "Engine/GameEngine.h"

Hard02State::Hard02State()
{
}

void Hard02State::Enter(Difficulty& diff)
{
	ESTATEDIFF = EDifficulty::HARD_02;
	m_currentDiff = HARD02DIFF;
}

DifficultyState* Hard02State::Update(Difficulty& diff, EStates State)
{
	switch (State)
	{
	case EStates::NONE:
		return nullptr;
		break;
	case EStates::EASY: case EStates::MEDIUM:
	{
		// If EASY - Don't want to jump from Hard_02 to Easy so go to Medium
		DifficultyState* ms = new MediumState();
		return ms;
		break;
	}
	case EStates::HARD:
		return nullptr;
		break;
	default:
		return nullptr;
		break;
	}

	return nullptr;
}

void Hard02State::Exit(Difficulty& diff)
{
}

Hard02State::~Hard02State()
{
}
