#pragma once

#include "CoreMinimal.h"
#include "DifficultyState.h"
#include "EasyState.h"
#include "HardState.h"

class MAJORPROJECT_API Medium02State : public DifficultyState
{
public:
	Medium02State();
	virtual ~Medium02State();
	virtual DifficultyState* Update(class Difficulty& diff, EStates State);
	virtual void Enter(class Difficulty& diff);
	virtual void Exit(class Difficulty& diff);
};
