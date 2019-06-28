#define print(text) if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.0, FColor::Green, text)

#include "HardState.h"
#include "Engine/GameEngine.h"

HardState::HardState()
{
}

void HardState::Enter(Difficulty& diff)
{
	ESTATEDIFF = EDifficulty::HARD_01;
	m_currentDiff = HARD01DIFF;
}

DifficultyState* HardState::Update(Difficulty& diff, EStates State)
{
	switch (State)
	{
	case EStates::NONE:
		return nullptr;
		break;
	case EStates::EASY:
	{
		// Don't want to jump from Hard to Easy so go to Medium
		DifficultyState* ms = new MediumState();
		return ms;
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
		DifficultyState* hs2 = new Hard02State();
		return hs2;
		break;
	}
	default:
		return nullptr;
		break;
	}

	return nullptr;
}

void HardState::Exit(Difficulty& diff)
{
}

HardState::~HardState()
{
}
