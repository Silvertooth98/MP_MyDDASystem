// Fill out your copyright notice in the Description page of Project Settings.

#define print(text) if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.0, FColor::Green, text)

#include "Difficulty.h"
#include "Engine/GameEngine.h"

Difficulty::Difficulty()
{
}

EDDifficulty Difficulty::SetDDifficulty(EDDifficulty SetDDifficulty)
{
	m_DDifficulty = SetDDifficulty;

	return m_DDifficulty;
}

void Difficulty::StartingDifficulty(bool Easy, bool Medium, bool Hard)
{
	// If Easy boolean is true, set difficulty to Easy_01
	if (Easy)
	{
		print("STARTING DIFFICULTY - EASY_01 (Difficulty Class)");
		m_DDifficulty = EDDifficulty::EASY_01;
	}

	// If Medium boolean is true, set difficulty to Medium_01
	else if (Medium)
	{
		print("STARTING DIFFICULTY - MEDIUM_01 (Difficulty Class)");
		m_DDifficulty = EDDifficulty::MEDIUM_01;
	}

	// If Hard boolean is true, set difficulty to Hard_01
	else if (Hard)
	{
		print("STARTING DIFFICULTY - HARD_01 (Difficulty Class)");
		m_DDifficulty = EDDifficulty::HARD_01;
	}
	
	// Else, Error messages
	else
	{
		print("ERROR SETTING STARTING DIFFICULTY IN STARTINGDIFFICULTY (DIFFICULTY CLASS)");
		m_DDifficulty = EDDifficulty::NONE;
	}
}

void Difficulty::EasyDifficulty()
{
	// If no difficulty or Medium_01 difficulty, set difficulty to Easy_01
	if (m_DDifficulty == EDDifficulty::NONE ||
		m_DDifficulty == EDDifficulty::MEDIUM_01)
	{
		print("DIFFICULTY - EASY_01 (Difficulty Class)");
		m_DDifficulty = EDDifficulty::EASY_01;
	}

	// If Easy_01 or Easy_02 difficulty, set difficulty to Easy_02
	else if (m_DDifficulty == EDDifficulty::EASY_01 ||
			 m_DDifficulty == EDDifficulty::EASY_02)
	{
		print("DIFFICULTY - EASY_02 (Difficulty Class)");
		m_DDifficulty = EDDifficulty::EASY_02;
	}

	// If Medium_02 or Hard_01 difficulty, set difficulty to Medium_01
	else if (m_DDifficulty == EDDifficulty::MEDIUM_02 ||
			 m_DDifficulty == EDDifficulty::HARD_01)
	{
		print("DIFFICULTY - MEDIUM_01 (Difficulty Class)");
		m_DDifficulty = EDDifficulty::MEDIUM_01;
	}

	// If Hard_02 difficulty, set difficulty to Hard_01
	else if (m_DDifficulty == EDDifficulty::HARD_02)
	{
		print("DIFFICULTY - HARD_01 (Difficulty Class)");
		m_DDifficulty = EDDifficulty::HARD_01;
	}

	// Else, Error messages
	else
	{
		print("ERROR SETTING DIFFICULTY IN EASYDIFFICULTY (DIFFICULTY CLASS)");
		m_DDifficulty = EDDifficulty::NONE;
	}
}

void Difficulty::PureEasyDifficulty()
{
	// If Easy_01 or Easy_02, set difficulty to Easy_02
	if (m_DDifficulty == EDDifficulty::EASY_01 ||
		m_DDifficulty == EDDifficulty::EASY_02)
	{
		print("DIFFICULTY - EASY_02 (Difficulty Class)");
		m_DDifficulty = EDDifficulty::EASY_02;
	}

	// Else if any other difficulty, set difficulty to Hard_01
	else if (m_DDifficulty == EDDifficulty::NONE ||
			 m_DDifficulty == EDDifficulty::HARD_01 ||
			 m_DDifficulty == EDDifficulty::HARD_02 ||
			 m_DDifficulty == EDDifficulty::MEDIUM_01 ||
			 m_DDifficulty == EDDifficulty::MEDIUM_02)
	{
		print("DIFFICULTY - EASY_01 (Difficulty Class)");
		m_DDifficulty = EDDifficulty::EASY_01;
	}

	// Else, Error messages
	else
	{
		print("ERROR SETTING DIFFICULTY IN PUREEASYDIFFICULTY (DIFFICULTY CLASS)");
		m_DDifficulty = EDDifficulty::NONE;
	}
}

void Difficulty::MediumDifficulty()
{
	// If no difficulty is set or Easy_01, Easy_02, Hard_01 or Hard_02, set difficulty to Medium_01
	if (m_DDifficulty == EDDifficulty::NONE ||
		m_DDifficulty == EDDifficulty::EASY_01 ||
		m_DDifficulty == EDDifficulty::EASY_02 ||
		m_DDifficulty == EDDifficulty::HARD_01 ||
		m_DDifficulty == EDDifficulty::HARD_02)
	{
		print("DIFFICULTY - MEDIUM_01 (Difficulty Class)");
		m_DDifficulty = EDDifficulty::MEDIUM_01;
	}

	else if (m_DDifficulty == EDDifficulty::MEDIUM_01 ||
			 m_DDifficulty == EDDifficulty::MEDIUM_02)
	{
		print("DIFFICULTY - MEDIUM_02 (Difficulty Class)");
		m_DDifficulty = EDDifficulty::MEDIUM_02;
	}

	// Else, Error messages
	else
	{
		print("ERROR SETTING DIFFICULTY IN MEDIUMDIFFICULTY (DIFFICULTY CLASS)");
		m_DDifficulty = EDDifficulty::NONE;
	}
}

void Difficulty::HardDifficulty()
{
	// If no difficulty is set or Medium_02 difficulty, set difficulty to Hard_02
	if (m_DDifficulty == EDDifficulty::MEDIUM_02 ||
		m_DDifficulty == EDDifficulty::NONE)
	{
		print("DIFFICULTY - HARD_01 (Difficulty Class)");
		m_DDifficulty = EDDifficulty::HARD_01;
	}

	// If Easy_01 or Easy_02 difficulty, set difficulty to Medium_01
	else if (m_DDifficulty == EDDifficulty::EASY_01 ||
			 m_DDifficulty == EDDifficulty::EASY_02)
	{
		print("DIFFICULTY - MEDIUM_01 (Difficulty Class)");
		m_DDifficulty = EDDifficulty::MEDIUM_01;
	}

	// If Medium_01 difficulty, set difficulty to Medium_02
	else if (m_DDifficulty == EDDifficulty::MEDIUM_01)
	{
		print("DIFFICULTY - MEDIUM_02 (Difficulty Class)");
		m_DDifficulty = EDDifficulty::MEDIUM_02;
	}

	else if (m_DDifficulty == EDDifficulty::HARD_01 ||
			 m_DDifficulty == EDDifficulty::HARD_02)
	{
		print("DIFFICULTY - HARD_02 (Difficulty Class)");
		m_DDifficulty = EDDifficulty::HARD_02;
	}

	// Else, Error messages
	else
	{
		print("ERROR SETTING DIFFICULTY IN HARDDIFFICULTY (DIFFICULTY CLASS)");
		m_DDifficulty = EDDifficulty::NONE;
	}
}

void Difficulty::PureHardDifficulty()
{
	// If Hard_01 or Hard_02, set difficulty to Hard_02
	if (m_DDifficulty == EDDifficulty::HARD_01 ||
		m_DDifficulty == EDDifficulty::HARD_02)
	{
		print("DIFFICULTY - HARD_02 (Difficulty Class)");
		m_DDifficulty = EDDifficulty::HARD_02;
	}

	// Else if any other difficulty, set difficulty to Hard_01
	else if (m_DDifficulty == EDDifficulty::NONE		||
			 m_DDifficulty == EDDifficulty::EASY_01		||
			 m_DDifficulty == EDDifficulty::EASY_02		||
			 m_DDifficulty == EDDifficulty::MEDIUM_01	||
			 m_DDifficulty == EDDifficulty::MEDIUM_02)
	{
		print("DIFFICULTY - HARD_01 (Difficulty Class)");
		m_DDifficulty = EDDifficulty::HARD_01;
	}

	// Else, Error messages
	else
	{
		print("ERROR SETTING DIFFICULTY IN PUREHARDDIFFICULTY (DIFFICULTY CLASS)");
		m_DDifficulty = EDDifficulty::NONE;
	}
}

void Difficulty::FinalDifficulty(bool Easy, bool Medium, bool Hard)
{
	// If Easy boolean is true, set difficulty to Easy_01
	if (Easy)
	{
		print("FINAL DIFFICULTY - EASY_01 (Difficulty Class)");
		m_DDifficulty = EDDifficulty::EASY_01;
	}

	// If Medium boolean is true, set difficulty to Medium_01
	else if (Medium)
	{
		print("FINAL DIFFICULTY - MEDIUM_01 (Difficulty Class)");
		m_DDifficulty = EDDifficulty::MEDIUM_01;
	}

	// If Hard boolean is true, set difficulty to Hard_01
	else if (Hard)
	{
		print("FINAL DIFFICULTY - HARD_01 (Difficulty Class)");
		m_DDifficulty = EDDifficulty::HARD_01;
	}

	// Else, Error messages
	else
	{
		print("ERROR SETTING FINAL DIFFICULTY IN FINALDIFFICULTY (DIFFICULTY CLASS)");
		m_DDifficulty = EDDifficulty::NONE;
	}
}

Difficulty::~Difficulty()
{
}