#define print(text) if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.0, FColor::Green, text)

#include "Easy02State.h"
#include "Engine/GameEngine.h"

Easy02State::Easy02State()
{
}

void Easy02State::Enter(Difficulty& diff)
{
	ESTATEDIFF = EDifficulty::EASY_02;
	m_currentDiff = EASY02DIFF;
	print("Entered Easy02State - Enter function");
}

DifficultyState* Easy02State::Update(Difficulty& diff, EStates State)
{
	switch (State)
	{
	case EStates::NONE:
		return nullptr;
		break;
	case EStates::EASY:
		return nullptr;
		break;
	case EStates::MEDIUM:
	{
		DifficultyState* ms = new MediumState();
		return ms;
		break;
	}
	case EStates::HARD:
	{
		// Don't want to jump from Easy02 to Hard so go to Medium
		DifficultyState* ms = new MediumState();
		return ms;
		break;
	}
	default:
		return nullptr;
		break;
	}

	return nullptr;
}

void Easy02State::Exit(Difficulty& diff)
{
}

Easy02State::~Easy02State()
{
}
