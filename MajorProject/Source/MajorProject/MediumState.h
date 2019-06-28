#pragma once

#include "CoreMinimal.h"
#include "DifficultyState.h"
#include "EasyState.h"
#include "Medium02State.h"
#include "HardState.h"

class MAJORPROJECT_API MediumState : public DifficultyState
{
public:
	MediumState();
	virtual ~MediumState();
	virtual DifficultyState* Update(class Difficulty& diff, EStates State);
	virtual void Enter(class Difficulty& diff);
	virtual void Exit(class Difficulty& diff);
};
