#pragma once

#include "CoreMinimal.h"
#include "DifficultyState.h"
#include "MediumState.h"
#include "Hard02State.h"

class MAJORPROJECT_API HardState : public DifficultyState
{
public:
	HardState();
	virtual ~HardState();
	virtual DifficultyState* Update(class Difficulty& diff, EStates State);
	virtual void Enter(class Difficulty& diff);
	virtual void Exit(class Difficulty& diff);
};
