// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

enum class EDifficulty : uint8
{
	NONE,

	EASY_01,
	EASY_02,

	MEDIUM_01,
	MEDIUM_02,

	HARD_01,
	HARD_02
};

enum class EStates : uint8
{
	NONE,
	EASY,
	MEDIUM,
	HARD
};

enum class ESections : uint8
{
	SECTION_01,
	SECTION_02,
	SECTION_03,
	SECTION_04,
	SECTION_05
};

class MAJORPROJECT_API MyEnums
{
};
