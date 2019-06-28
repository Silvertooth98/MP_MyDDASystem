#pragma once

#include "CoreMinimal.h"
#include "DifficultyState.h"
#include "Easy02State.h"
#include "MediumState.h"

class MAJORPROJECT_API EasyState : public DifficultyState
{
public:
	EasyState();
	virtual ~EasyState();
	virtual DifficultyState* Update(class Difficulty& diff, EStates State);
	virtual void Enter(class Difficulty& diff);
	virtual void Exit(class Difficulty& diff);
};
