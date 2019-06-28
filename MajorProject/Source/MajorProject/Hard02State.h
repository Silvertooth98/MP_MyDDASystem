#pragma once

#include "CoreMinimal.h"
#include "DifficultyState.h"
#include "MediumState.h"

class MAJORPROJECT_API Hard02State : public DifficultyState
{
public:
	Hard02State();
	virtual ~Hard02State();
	virtual DifficultyState* Update(class Difficulty& diff, EStates State);
	virtual void Enter(class Difficulty& diff);
	virtual void Exit(class Difficulty& diff);
};
