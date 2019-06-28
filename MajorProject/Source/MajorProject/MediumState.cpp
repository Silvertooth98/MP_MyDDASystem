#define print(text) if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.0, FColor::Green, text)

#include "MediumState.h"
#include "Engine/GameEngine.h"

MediumState::MediumState()
{
}

void MediumState::Enter(Difficulty& diff)
{
	ESTATEDIFF = EDifficulty::MEDIUM_01;
	m_currentDiff = MEDIUM01DIFF;
}

DifficultyState* MediumState::Update(Difficulty& diff, EStates State)
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
		DifficultyState* ms2 = new Medium02State();
		return ms2;
		break;
	}
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

void MediumState::Exit(Difficulty& diff)
{
}

MediumState::~MediumState()
{
}
