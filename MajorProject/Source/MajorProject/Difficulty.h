// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

enum class EDDifficulty : uint8
{
	NONE,

	EASY_01,
	EASY_02,

	MEDIUM_01,
	MEDIUM_02,

	HARD_01,
	HARD_02
};

class MAJORPROJECT_API Difficulty
{
public:
	Difficulty();
	~Difficulty();

	EDDifficulty GetDDifficulty() { return m_DDifficulty; }
	EDDifficulty SetDDifficulty(EDDifficulty SetDDifficulty);

	void StartingDifficulty(bool Easy = false, bool Medium = false, bool Hard = false);
	void EasyDifficulty();
	void PureEasyDifficulty();
	void MediumDifficulty();
	void HardDifficulty();
	void PureHardDifficulty();
	void FinalDifficulty(bool Easy = false, bool Medium = false, bool Hard = false);

private:
	EDDifficulty m_DDifficulty = EDDifficulty::NONE;

};
