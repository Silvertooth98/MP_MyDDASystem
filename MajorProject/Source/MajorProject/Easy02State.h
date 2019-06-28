#pragma once

#include "CoreMinimal.h"
#include "DifficultyState.h"
#include "EasyState.h"
#include "MediumState.h"

class MAJORPROJECT_API Easy02State : public DifficultyState
{
public:
	Easy02State();
	virtual ~Easy02State();
	virtual DifficultyState* Update(class Difficulty& diff, EStates State);
	virtual void Enter(class Difficulty& diff);
	virtual void Exit(class Difficulty& diff);
};
