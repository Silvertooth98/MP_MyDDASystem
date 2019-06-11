// Fill out your copyright notice in the Description page of Project Settings.

#define print(text) if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.0, FColor::Green, text)

#include "Difficulty.h"
#include "Engine/GameEngine.h"

Difficulty::Difficulty()
{
}

void Difficulty::SaveDataToTextFile(FString Level, FString LevelSection, FString Difficulty,
	FString TotalTime, FString TotalMovementTime,
	FString TotalInLightTime, FString TextFileNumber)
{
	// Save difficulty details to text file
	m_textFile->SaveTxt(FString(Level + " - Section " + LevelSection) +
						FString("\r\nDifficulty Set to: " + Difficulty) +
						FString("\r\nTotal Time: " + TotalTime) +
						FString("\r\nTotal Movement Time: " + TotalMovementTime) +
						FString("\r\nTotal In Light Time: " + TotalInLightTime),
						FString("TextFiles/" + Level + "/Test" + TextFileNumber + ".txt"));
}

EDifficulty Difficulty::SetDifficulty(EDifficulty SetDifficulty)
{
	m_Difficulty = SetDifficulty;

	return m_Difficulty;
}

void Difficulty::SetExactDifficulty(bool Easy, bool Medium, bool Hard,
	FString Level, FString SectionNum, FString TotalTime, FString TotalMovementTime, FString TotalInLightTime)
{
	// If Easy boolean is true, set difficulty to Easy_01
	if (Easy)
	{
		print("DIFFICULTY - EASY_01 (Difficulty Class)");
		m_Difficulty = EDifficulty::EASY_01;

		// Save difficulty details to text file
		SaveDataToTextFile(Level, SectionNum, FString("EASY_01"), TotalTime, TotalMovementTime, TotalInLightTime, SectionNum);
	}

	// If Medium boolean is true, set difficulty to Medium_01
	else if (Medium)
	{
		print("DIFFICULTY - MEDIUM_01 (Difficulty Class)");
		m_Difficulty = EDifficulty::MEDIUM_01;

		// Save difficulty details to text file
		SaveDataToTextFile(Level, SectionNum, FString("MEDIUM_01"), TotalTime, TotalMovementTime, TotalInLightTime, SectionNum);
	}

	// If Hard boolean is true, set difficulty to Hard_01
	else if (Hard)
	{
		print("DIFFICULTY - HARD_01 (Difficulty Class)");
		m_Difficulty = EDifficulty::HARD_01;

		// Save difficulty details to text file
		SaveDataToTextFile(Level, SectionNum, FString("HARD_01"), TotalTime, TotalMovementTime, TotalInLightTime, SectionNum);
	}
	
	// Else, Error messages
	else
	{
		print("ERROR SETTING DIFFICULTY IN SETEXACTDIFFICULTY (DIFFICULTY CLASS)");
		m_Difficulty = EDifficulty::NONE;
	}
}

void Difficulty::EasyDifficulty(FString Level, FString SectionNum, FString TotalTime, FString TotalMovementTime, FString TotalInLightTime)
{
	// If no difficulty or Medium_01 difficulty, set difficulty to Easy_01
	if (m_Difficulty == EDifficulty::NONE ||
		m_Difficulty == EDifficulty::MEDIUM_01)
	{
		print("DIFFICULTY - EASY_01 (Difficulty Class)");
		m_Difficulty = EDifficulty::EASY_01;

		// Save difficulty details to text file
		SaveDataToTextFile(Level, SectionNum, FString("EASY_01"), TotalTime, TotalMovementTime, TotalInLightTime, SectionNum);
	}

	// If Easy_01 or Easy_02 difficulty, set difficulty to Easy_02
	else if (m_Difficulty == EDifficulty::EASY_01 ||
			 m_Difficulty == EDifficulty::EASY_02)
	{
		print("DIFFICULTY - EASY_02 (Difficulty Class)");
		m_Difficulty = EDifficulty::EASY_02;

		// Save difficulty details to text file
		SaveDataToTextFile(Level, SectionNum, FString("EASY_02"), TotalTime, TotalMovementTime, TotalInLightTime, SectionNum);
	}

	// If Medium_02 or Hard_01 difficulty, set difficulty to Medium_01
	else if (m_Difficulty == EDifficulty::MEDIUM_02 ||
			 m_Difficulty == EDifficulty::HARD_01)
	{
		print("DIFFICULTY - MEDIUM_01 (Difficulty Class)");
		m_Difficulty = EDifficulty::MEDIUM_01;

		// Save difficulty details to text file
		SaveDataToTextFile(Level, SectionNum, FString("MEDIUM_01"), TotalTime, TotalMovementTime, TotalInLightTime, SectionNum);
	}

	// If Hard_02 difficulty, set difficulty to Hard_01
	else if (m_Difficulty == EDifficulty::HARD_02)
	{
		print("DIFFICULTY - HARD_01 (Difficulty Class)");
		m_Difficulty = EDifficulty::HARD_01;

		// Save difficulty details to text file
		SaveDataToTextFile(Level, SectionNum, FString("HARD_01"), TotalTime, TotalMovementTime, TotalInLightTime, SectionNum);
	}

	// Else, Error messages
	else
	{
		print("ERROR SETTING DIFFICULTY IN EASYDIFFICULTY (DIFFICULTY CLASS)");
		m_Difficulty = EDifficulty::NONE;
	}
}

void Difficulty::PureEasyDifficulty(FString Level, FString SectionNum, FString TotalTime, FString TotalMovementTime, FString TotalInLightTime)
{
	// If Easy_01 or Easy_02, set difficulty to Easy_02
	if (m_Difficulty == EDifficulty::EASY_01 ||
		m_Difficulty == EDifficulty::EASY_02)
	{
		print("DIFFICULTY - EASY_02 (Difficulty Class)");
		m_Difficulty = EDifficulty::EASY_02;

		// Save difficulty details to text file
		SaveDataToTextFile(Level, SectionNum, FString("EASY_02"), TotalTime, TotalMovementTime, TotalInLightTime, SectionNum);
	}

	// Else if any other difficulty, set difficulty to Hard_01
	else if (m_Difficulty == EDifficulty::NONE ||
			 m_Difficulty == EDifficulty::HARD_01 ||
			 m_Difficulty == EDifficulty::HARD_02 ||
			 m_Difficulty == EDifficulty::MEDIUM_01 ||
			 m_Difficulty == EDifficulty::MEDIUM_02)
	{
		print("DIFFICULTY - EASY_01 (Difficulty Class)");
		m_Difficulty = EDifficulty::EASY_01;

		// Save difficulty details to text file
		SaveDataToTextFile(Level, SectionNum, FString("EASY_01"), TotalTime, TotalMovementTime, TotalInLightTime, SectionNum);
	}

	// Else, Error messages
	else
	{
		print("ERROR SETTING DIFFICULTY IN PUREEASYDIFFICULTY (DIFFICULTY CLASS)");
		m_Difficulty = EDifficulty::NONE;
	}
}

void Difficulty::MediumDifficulty(FString Level, FString SectionNum, FString TotalTime, FString TotalMovementTime, FString TotalInLightTime)
{
	// If no difficulty is set or Easy_01, Easy_02, Hard_01 or Hard_02, set difficulty to Medium_01
	if (m_Difficulty == EDifficulty::NONE ||
		m_Difficulty == EDifficulty::EASY_01 ||
		m_Difficulty == EDifficulty::EASY_02 ||
		m_Difficulty == EDifficulty::HARD_01 ||
		m_Difficulty == EDifficulty::HARD_02)
	{
		print("DIFFICULTY - MEDIUM_01 (Difficulty Class)");
		m_Difficulty = EDifficulty::MEDIUM_01;

		// Save difficulty details to text file
		SaveDataToTextFile(Level, SectionNum, FString("MEDIUM_01"), TotalTime, TotalMovementTime, TotalInLightTime, SectionNum);
	}

	else if (m_Difficulty == EDifficulty::MEDIUM_01 ||
			 m_Difficulty == EDifficulty::MEDIUM_02)
	{
		print("DIFFICULTY - MEDIUM_02 (Difficulty Class)");
		m_Difficulty = EDifficulty::MEDIUM_02;

		// Save difficulty details to text file
		SaveDataToTextFile(Level, SectionNum, FString("MEDIUM_02"), TotalTime, TotalMovementTime, TotalInLightTime, SectionNum);
	}

	// Else, Error messages
	else
	{
		print("ERROR SETTING DIFFICULTY IN MEDIUMDIFFICULTY (DIFFICULTY CLASS)");
		m_Difficulty = EDifficulty::NONE;
	}
}

void Difficulty::HardDifficulty(FString Level, FString SectionNum, FString TotalTime, FString TotalMovementTime, FString TotalInLightTime)
{
	// If no difficulty is set or Medium_02 difficulty, set difficulty to Hard_02
	if (m_Difficulty == EDifficulty::MEDIUM_02 ||
		m_Difficulty == EDifficulty::NONE)
	{
		print("DIFFICULTY - HARD_01 (Difficulty Class)");
		m_Difficulty = EDifficulty::HARD_01;

		// Save difficulty details to text file
		SaveDataToTextFile(Level, SectionNum, FString("HARD_01"), TotalTime, TotalMovementTime, TotalInLightTime, SectionNum);
	}

	// If Easy_01 or Easy_02 difficulty, set difficulty to Medium_01
	else if (m_Difficulty == EDifficulty::EASY_01 ||
			 m_Difficulty == EDifficulty::EASY_02)
	{
		print("DIFFICULTY - MEDIUM_01 (Difficulty Class)");
		m_Difficulty = EDifficulty::MEDIUM_01;

		// Save difficulty details to text file
		SaveDataToTextFile(Level, SectionNum, FString("MEDIUM_01"), TotalTime, TotalMovementTime, TotalInLightTime, SectionNum);
	}

	// If Medium_01 difficulty, set difficulty to Medium_02
	else if (m_Difficulty == EDifficulty::MEDIUM_01)
	{
		print("DIFFICULTY - MEDIUM_02 (Difficulty Class)");
		m_Difficulty = EDifficulty::MEDIUM_02;

		// Save difficulty details to text file
		SaveDataToTextFile(Level, SectionNum, FString("MEDIUM_02"), TotalTime, TotalMovementTime, TotalInLightTime, SectionNum);
	}

	else if (m_Difficulty == EDifficulty::HARD_01 ||
			 m_Difficulty == EDifficulty::HARD_02)
	{
		print("DIFFICULTY - HARD_02 (Difficulty Class)");
		m_Difficulty = EDifficulty::HARD_02;

		// Save difficulty details to text file
		SaveDataToTextFile(Level, SectionNum, FString("HARD_02"), TotalTime, TotalMovementTime, TotalInLightTime, SectionNum);
	}

	// Else, Error messages
	else
	{
		print("ERROR SETTING DIFFICULTY IN HARDDIFFICULTY (DIFFICULTY CLASS)");
		m_Difficulty = EDifficulty::NONE;
	}
}

void Difficulty::PureHardDifficulty(FString Level, FString SectionNum, FString TotalTime, FString TotalMovementTime, FString TotalInLightTime)
{
	// If Hard_01 or Hard_02, set difficulty to Hard_02
	if (m_Difficulty == EDifficulty::HARD_01 ||
		m_Difficulty == EDifficulty::HARD_02)
	{
		print("DIFFICULTY - HARD_02 (Difficulty Class)");
		m_Difficulty = EDifficulty::HARD_02;

		// Save difficulty details to text file
		SaveDataToTextFile(Level, SectionNum, FString("HARD_02"), TotalTime, TotalMovementTime, TotalInLightTime, SectionNum);
	}

	// Else if any other difficulty, set difficulty to Hard_01
	else if (m_Difficulty == EDifficulty::NONE		||
			 m_Difficulty == EDifficulty::EASY_01	||
			 m_Difficulty == EDifficulty::EASY_02	||
			 m_Difficulty == EDifficulty::MEDIUM_01	||
			 m_Difficulty == EDifficulty::MEDIUM_02)
	{
		print("DIFFICULTY - HARD_01 (Difficulty Class)");
		m_Difficulty = EDifficulty::HARD_01;

		// Save difficulty details to text file
		SaveDataToTextFile(Level, SectionNum, FString("HARD_01"), TotalTime, TotalMovementTime, TotalInLightTime, SectionNum);
	}

	// Else, Error messages
	else
	{
		print("ERROR SETTING DIFFICULTY IN PUREHARDDIFFICULTY (DIFFICULTY CLASS)");
		m_Difficulty = EDifficulty::NONE;
	}
}

Difficulty::~Difficulty()
{
}