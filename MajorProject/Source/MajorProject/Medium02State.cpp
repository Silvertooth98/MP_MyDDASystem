#include "Medium02State.h"
#include "Engine/GameEngine.h"

Medium02State::Medium02State()
{
}


void Medium02State::Enter(Difficulty& diff)
{
	ESTATEDIFF = EDifficulty::MEDIUM_02;
	m_currentDiff = MEDIUM02DIFF;
}

DifficultyState* Medium02State::Update(Difficulty& diff, EStates State)
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
		return nullptr;
		break;
	case EStates::HARD:
	{
		DifficultyState* hs = new HardState();
		return hs;
		break;
	}
	default:
		break;
	}

	return nullptr;
}

void Medium02State::Exit(Difficulty& diff)
{
}

Medium02State::~Medium02State()
{
}