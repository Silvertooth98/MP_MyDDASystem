// Fill out your copyright notice in the Description page of Project Settings.

#define print(text) if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.0, FColor::Green, text)
#define printf(text, fstring) if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.0, FColor::Yellow, FString::Printf(TEXT(text), fstring))

#include "DDATriggerBox.h"
#include "DrawDebugHelpers.h"
#include "Engine/GameEngine.h"
#include "MajorProjectCharacter.h"

ADDATriggerBox::ADDATriggerBox()
{
	OnActorBeginOverlap.AddDynamic(this, &ADDATriggerBox::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &ADDATriggerBox::OnOverLapEnd);
}

void ADDATriggerBox::BeginPlay()
{
	Super::BeginPlay();

	// DEBUG
	DrawDebugBox(GetWorld(), GetActorLocation(), GetComponentsBoundingBox().GetExtent(), FColor::Purple, true, 100, 0, 5);
	
	// Create link from GameInstance class pointer variable to the GameInstance
	GameInstance = Cast<UMajorProjectGameInstance>(GetGameInstance());
	// Link gamemode variable to the gamemode class
	Gamemode = (AMajorProjectGameMode*)GetWorld()->GetAuthGameMode();
	// Link character variable to the character class
	Character = Cast<AMajorProjectCharacter>(GetWorld()->GetFirstPlayerController()->GetCharacter());

	// Set the variable for the player character name by getting the name from the player character class
	m_playerCharacterName = Character->PlayerCharacterName;
}

void ADDATriggerBox::SaveDataToTextFile(FString Level, FString LevelSection, FString Difficulty,
										FString TotalTime, FString TotalMovementTime,
										FString TotalInLightTime, FString TextFileNumber)
{
	// Save difficulty details to text file
	m_textFile->SaveTxt(FString(Level + " - " + LevelSection) +
						FString("\r\nDifficulty Set to: " + Difficulty) +
						FString("\r\nTotal Time: " + TotalTime) +
						FString("\r\nTotal Movement Time: " + TotalMovementTime) +
						FString("\r\nTotal In Light Time: " + TotalInLightTime),
						FString("TextFiles/" + Level + "/Test" + TextFileNumber + ".txt"));
}

void ADDATriggerBox::DifficultyFinializedSetup(bool S1, bool S2, bool S3, bool S4, bool S5)
{
//############################################################################################################################
											// LEVEL 01 SECTIONS
//############################################################################################################################

	if (m_currentLevel == "Level_01")
	{
		// Set the total time variable to equal the current total time
		m_totalTime = FString::FromInt(Gamemode->GetSecondsInt());

		// Set the total movement time variable to equal the current total movement time
		m_movementTime = FString::FromInt(Character->GetTotalMovementTime());

		// Set the total in light time variable to equal the current total in light time
		m_inLightTime = FString::FromInt(Character->GetTotalInLightTime());

		//#####################################################################################################
									// SECTION 1 TRIGGER BOX
		//#####################################################################################################
		// Check if player is within the first section trigger box
		if (S1)
		{
			print("SECTION 1");

			// Set boolean for section01 in the character class to true and the other section booleans to false
			Character->m_section01 = true;
			Character->m_section02 = false;
			Character->m_section03 = false;
			Character->m_section04 = false;
			Character->m_section05 = false;

			// Check if easy difficulty
			if (Character->m_CharDDifficulty->GetDDifficulty() == EDDifficulty::EASY_01)
			{
				print("DIFFICULTY - EASY");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S1EasyModeSetup.Num(); i++)
				{
					m_L1S1EasyModeSetup[i]->Destroy();
				}

				// Set difficulty within the character class
				Character->SetDifficulty(ESetDifficulty::EASY_01);

				// Save difficulty details to text file
				SaveDataToTextFile(FString("Level_01"), FString("Section 01"),
								   FString("EASY_01"), m_totalTime, m_movementTime,
								   m_inLightTime, FString("01"));
			}

			// Check if medium difficulty
			else if (Character->m_CharDDifficulty->GetDDifficulty() == EDDifficulty::MEDIUM_01)
			{
				print("DIFFICULTY - MEDIUM");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S1MediumModeSetup.Num(); i++)
				{
					m_L1S1MediumModeSetup[i]->Destroy();
				}

				// Set difficulty within the character class
				Character->SetDifficulty(ESetDifficulty::MEDIUM_01);

				// Save difficulty details to text file
				SaveDataToTextFile(FString("Level_01"), FString("Section 01"),
								   FString("MEDIUM_01"), m_totalTime, m_movementTime,
								   m_inLightTime, FString("01"));
			}

			// Check if hard difficuly
			else if (Character->m_CharDDifficulty->GetDDifficulty() == EDDifficulty::HARD_01)
			{
				print("DIFFICULTY - HARD");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S1HardModeSetup.Num(); i++)
				{
					m_L1S1HardModeSetup[i]->Destroy();
				}

				// Set difficulty within the character class
				Character->SetDifficulty(ESetDifficulty::HARD_01);

				// Save difficulty details to text file
				SaveDataToTextFile(FString("Level_01"), FString("Section 01"),
								   FString("HARD_01"), m_totalTime, m_movementTime,
								   m_inLightTime, FString("01"));
			}

			else
			{
				print("ERROR - NO SET DIFFICULTY - Difficulty check function");
			}
		}

		//#####################################################################################################
									// SECTION 2 TRIGGER BOX
		//#####################################################################################################
		// Check if player is within the second section trigger box
		else if (S2)
		{
			print("SECTION 2");

			// Set boolean for section02 in the character class to true and the other section booleans to false
			Character->m_section01 = false;
			Character->m_section02 = true;
			Character->m_section03 = false;
			Character->m_section04 = false;
			Character->m_section05 = false;

			// Check if Easy 1 difficulty
			if (Character->m_CharDDifficulty->GetDDifficulty() == EDDifficulty::EASY_01)
			{
				print("DIFFICULTY - EASY_01");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S2EasyMode1Setup.Num(); i++)
				{
					m_L1S2EasyMode1Setup[i]->Destroy();
				}

				// Set difficulty within the character class
				Character->SetDifficulty(ESetDifficulty::EASY_01);

				// Save difficulty details to text file
				SaveDataToTextFile(FString("Level_01"), FString("Section 02"),
								   FString("EASY_01"), m_totalTime, m_movementTime,
								   m_inLightTime, FString("02"));
			}

			// Check if Easy 2 difficulty
			else if (Character->m_CharDDifficulty->GetDDifficulty() == EDDifficulty::EASY_02)
			{
				print("DIFFICULTY - EASY_02");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S2EasyMode2Setup.Num(); i++)
				{
					m_L1S2EasyMode2Setup[i]->Destroy();
				}

				// Set difficulty within the character class
				Character->SetDifficulty(ESetDifficulty::EASY_02);

				// Save difficulty details to text file
				SaveDataToTextFile(FString("Level_01"), FString("Section 02"),
								   FString("EASY_02"), m_totalTime, m_movementTime,
								   m_inLightTime, FString("02"));
			}

			// Check if Medium 1 difficulty
			else if (Character->m_CharDDifficulty->GetDDifficulty() == EDDifficulty::MEDIUM_01)
			{
				print("DIFFICULTY - MEDIUM_01");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S2MediumMode1Setup.Num(); i++)
				{
					m_L1S2MediumMode1Setup[i]->Destroy();
				}

				// Set difficulty within the character class
				Character->SetDifficulty(ESetDifficulty::MEDIUM_01);

				// Save difficulty details to text file
				SaveDataToTextFile(FString("Level_01"), FString("Section 02"),
								   FString("MEDIUM_01"), m_totalTime, m_movementTime,
								   m_inLightTime, FString("02"));
			}

			// Check if Medium 2 difficulty
			else if (Character->m_CharDDifficulty->GetDDifficulty() == EDDifficulty::MEDIUM_02)
			{
				print("DIFFICULTY - MEDIUM_02");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S2MediumMode2Setup.Num(); i++)
				{
					m_L1S2MediumMode2Setup[i]->Destroy();
				}

				// Set difficulty within the character class
				Character->SetDifficulty(ESetDifficulty::MEDIUM_02);

				// Save difficulty details to text file
				SaveDataToTextFile(FString("Level_01"), FString("Section 02"),
								   FString("MEDIUM_02"), m_totalTime, m_movementTime,
								   m_inLightTime, FString("02"));
			}

			// Check if Hard 1 difficulty
			else if (Character->m_CharDDifficulty->GetDDifficulty() == EDDifficulty::HARD_01)
			{
				print("DIFFICULTY - HARD_01");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S2HardMode1Setup.Num(); i++)
				{
					m_L1S2HardMode1Setup[i]->Destroy();
				}

				// Set difficulty within the character class
				Character->SetDifficulty(ESetDifficulty::HARD_01);

				// Save difficulty details to text file
				SaveDataToTextFile(FString("Level_01"), FString("Section 02"),
								   FString("HARD_01"), m_totalTime, m_movementTime,
								   m_inLightTime, FString("02"));
			}

			// Check if Hard 2 difficulty
			else if (Character->m_CharDDifficulty->GetDDifficulty() == EDDifficulty::HARD_02)
			{
				print("DIFFICULTY - HARD_02");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S2HardMode2Setup.Num(); i++)
				{
					m_L1S2HardMode2Setup[i]->Destroy();
				}

				// Set difficulty within the character class
				Character->SetDifficulty(ESetDifficulty::HARD_02);

				// Save difficulty details to text file
				SaveDataToTextFile(FString("Level_01"), FString("Section 02"),
								   FString("HARD_02"), m_totalTime, m_movementTime,
								   m_inLightTime, FString("02"));
			}
		}

		//#####################################################################################################
									// SECTION 3 TRIGGER BOX
		//#####################################################################################################
			// Check if player is within the third section trigger box
		else if (S3)
		{
			print("SECTION 3");

			// Set boolean for section03 in the character class to true and the other section booleans to false
			Character->m_section01 = false;
			Character->m_section02 = false;
			Character->m_section03 = true;
			Character->m_section04 = false;
			Character->m_section05 = false;

			// Check if Easy 1 difficulty
			if (Character->m_CharDDifficulty->GetDDifficulty() == EDDifficulty::EASY_01)
			{
				print("DIFFICULTY - EASY_01");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S3EasyMode1Setup.Num(); i++)
				{
					m_L1S3EasyMode1Setup[i]->Destroy();
				}

				// Set difficulty within the character class
				Character->SetDifficulty(ESetDifficulty::EASY_01);

				// Save difficulty details to text file
				SaveDataToTextFile(FString("Level_01"), FString("Section 03"),
								   FString("EASY_01"), m_totalTime, m_movementTime,
								   m_inLightTime, FString("03"));
			}

			// Check if Easy 2 difficulty
			else if (Character->m_CharDDifficulty->GetDDifficulty() == EDDifficulty::EASY_02)
			{
				print("DIFFICULTY - EASY_02");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S3EasyMode2Setup.Num(); i++)
				{
					m_L1S3EasyMode2Setup[i]->Destroy();
				}

				// Set difficulty within the character class
				Character->SetDifficulty(ESetDifficulty::EASY_02);

				// Save difficulty details to text file
				SaveDataToTextFile(FString("Level_01"), FString("Section 03"),
								   FString("EASY_02"), m_totalTime, m_movementTime,
								   m_inLightTime, FString("03"));
			}

			// Check if Medium 1 difficulty
			else if (Character->m_CharDDifficulty->GetDDifficulty() == EDDifficulty::MEDIUM_01)
			{
				print("DIFFICULTY - MEDIUM_01");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S3MediumMode1Setup.Num(); i++)
				{
					m_L1S3MediumMode1Setup[i]->Destroy();
				}

				// Set difficulty within the character class
				Character->SetDifficulty(ESetDifficulty::MEDIUM_01);

				// Save difficulty details to text file
				SaveDataToTextFile(FString("Level_01"), FString("Section 03"),
								   FString("MEDIUM_01"), m_totalTime, m_movementTime,
								   m_inLightTime, FString("03"));
			}

			// Check if Medium 2 difficulty
			else if (Character->m_CharDDifficulty->GetDDifficulty() == EDDifficulty::MEDIUM_02)
			{
				print("DIFFICULTY - MEDIUM_02");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S3MediumMode2Setup.Num(); i++)
				{
					m_L1S3MediumMode2Setup[i]->Destroy();
				}

				// Set difficulty within the character class
				Character->SetDifficulty(ESetDifficulty::MEDIUM_02);

				// Save difficulty details to text file
				SaveDataToTextFile(FString("Level_01"), FString("Section 03"),
								   FString("MEDIUM_02"), m_totalTime, m_movementTime,
								   m_inLightTime, FString("03"));
			}

			// Check if Hard 1 difficulty
			else if (Character->m_CharDDifficulty->GetDDifficulty() == EDDifficulty::HARD_01)
			{
				print("DIFFICULTY - HARD_01");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S3HardMode1Setup.Num(); i++)
				{
					m_L1S3HardMode1Setup[i]->Destroy();
				}

				// Set difficulty within the character class
				Character->SetDifficulty(ESetDifficulty::HARD_01);

				// Save difficulty details to text file
				SaveDataToTextFile(FString("Level_01"), FString("Section 03"),
								   FString("HARD_01"), m_totalTime, m_movementTime,
								   m_inLightTime, FString("03"));
			}

			// Check if Hard 2 difficulty
			else if (Character->m_CharDDifficulty->GetDDifficulty() == EDDifficulty::HARD_02)
			{
				print("DIFFICULTY - HARD_02");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S3HardMode2Setup.Num(); i++)
				{
					m_L1S3HardMode2Setup[i]->Destroy();
				}

				// Set difficulty within the character class
				Character->SetDifficulty(ESetDifficulty::HARD_02);

				// Save difficulty details to text file
				SaveDataToTextFile(FString("Level_01"), FString("Section 03"),
								   FString("HARD_02"), m_totalTime, m_movementTime,
								   m_inLightTime, FString("03"));
			}
		}

		//#####################################################################################################
									// SECTION 4 TRIGGER BOX
		//#####################################################################################################
			// Check if player is within the fourth section trigger box
		else if (S4)
		{
			print("SECTION 4");

			// Set boolean for section04 in the character class to true and the other section booleans to false
			Character->m_section01 = false;
			Character->m_section02 = false;
			Character->m_section03 = false;
			Character->m_section04 = true;
			Character->m_section05 = false;

			// Check if Easy 1 difficulty
			if (Character->m_CharDDifficulty->GetDDifficulty() == EDDifficulty::EASY_01)
			{
				print("DIFFICULTY - EASY_01");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S4EasyMode1Setup.Num(); i++)
				{
					m_L1S4EasyMode1Setup[i]->Destroy();
				}

				// Set difficulty within the character class
				Character->SetDifficulty(ESetDifficulty::EASY_01);

				// Save difficulty details to text file
				SaveDataToTextFile(FString("Level_01"), FString("Section 04"),
								   FString("EASY_01"), m_totalTime, m_movementTime,
								   m_inLightTime, FString("04"));
			}

			// Check if Easy 2 difficulty
			else if (Character->m_CharDDifficulty->GetDDifficulty() == EDDifficulty::EASY_02)
			{
				print("DIFFICULTY - EASY_02");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S4EasyMode2Setup.Num(); i++)
				{
					m_L1S4EasyMode2Setup[i]->Destroy();
				}

				// Set difficulty within the character class
				Character->SetDifficulty(ESetDifficulty::EASY_02);

				// Save difficulty details to text file
				SaveDataToTextFile(FString("Level_01"), FString("Section 04"),
								   FString("EASY_02"), m_totalTime, m_movementTime,
								   m_inLightTime, FString("04"));
			}

			// Check if Medium 1 difficulty
			else if (Character->m_CharDDifficulty->GetDDifficulty() == EDDifficulty::MEDIUM_01)
			{
				print("DIFFICULTY - MEDIUM_01");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S4MediumMode1Setup.Num(); i++)
				{
					m_L1S4MediumMode1Setup[i]->Destroy();
				}

				// Set difficulty within the character class
				Character->SetDifficulty(ESetDifficulty::MEDIUM_01);

				// Save difficulty details to text file
				SaveDataToTextFile(FString("Level_01"), FString("Section 04"),
								   FString("MEDIUM_01"), m_totalTime, m_movementTime,
								   m_inLightTime, FString("04"));
			}

			// Check if Medium 2 difficulty
			else if (Character->m_CharDDifficulty->GetDDifficulty() == EDDifficulty::MEDIUM_02)
			{
				print("DIFFICULTY - MEDIUM_02");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S4MediumMode2Setup.Num(); i++)
				{
					m_L1S4MediumMode2Setup[i]->Destroy();
				}

				// Set difficulty within the character class
				Character->SetDifficulty(ESetDifficulty::MEDIUM_02);

				// Save difficulty details to text file
				SaveDataToTextFile(FString("Level_01"), FString("Section 04"),
								   FString("MEDIUM_02"), m_totalTime, m_movementTime,
								   m_inLightTime, FString("04"));
			}

			// Check if Hard 1 difficulty
			else if (Character->m_CharDDifficulty->GetDDifficulty() == EDDifficulty::HARD_01)
			{
				print("DIFFICULTY - HARD_01");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S4HardMode1Setup.Num(); i++)
				{
					m_L1S4HardMode1Setup[i]->Destroy();
				}

				// Set difficulty within the character class
				Character->SetDifficulty(ESetDifficulty::HARD_01);

				// Save difficulty details to text file
				SaveDataToTextFile(FString("Level_01"), FString("Section 04"),
								   FString("HARD_01"), m_totalTime, m_movementTime,
								   m_inLightTime, FString("04"));
			}

			// Check if Hard 2 difficulty
			else if (Character->m_CharDDifficulty->GetDDifficulty() == EDDifficulty::HARD_02)
			{
				print("DIFFICULTY - HARD_02");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S4HardMode2Setup.Num(); i++)
				{
					m_L1S4HardMode2Setup[i]->Destroy();
				}

				// Set difficulty within the character class
				Character->SetDifficulty(ESetDifficulty::HARD_02);

				// Save difficulty details to text file
				SaveDataToTextFile(FString("Level_01"), FString("Section 04"),
								   FString("HARD_02"), m_totalTime, m_movementTime,
								   m_inLightTime, FString("04"));
			}
		}

		//#####################################################################################################
									// SECTION 5 TRIGGER BOX
		//#####################################################################################################
		// Check if player is within the fifth and final section trigger box
		else if (S5)
		{
			print("SECTION 5");

			// Set boolean for section05 in the character class to true and the other section booleans to false
			Character->m_section01 = false;
			Character->m_section02 = false;
			Character->m_section03 = false;
			Character->m_section04 = false;
			Character->m_section05 = true;

			// Check if Easy 1 difficulty
			if (Character->m_CharDDifficulty->GetDDifficulty() == EDDifficulty::EASY_01)
			{
				print("DIFFICULTY - EASY_01");

				// Set the difficulty within the Game Instance Class, for initial difficulty within Level_02
				GameInstance->m_finalDifficulty = EFinalDifficulty::EASY_01;

				// Save difficulty details to text file
				SaveDataToTextFile(FString("Level_01"), FString("Section 05"),
								   FString("EASY_01"), m_totalTime, m_movementTime,
								   m_inLightTime, FString("05"));
			}

			// Check if Medium 1 difficulty
			else if (Character->m_CharDDifficulty->GetDDifficulty() == EDDifficulty::MEDIUM_01)
			{
				print("DIFFICULTY - MEDIUM_01");

				// Set the difficulty within the Game Instance Class, for initial difficulty within Level_02
				GameInstance->m_finalDifficulty = EFinalDifficulty::MEDIUM_01;

				// Save difficulty details to text file
				SaveDataToTextFile(FString("Level_01"), FString("Section 05"),
								   FString("MEDIUM_01"), m_totalTime, m_movementTime,
								   m_inLightTime, FString("05"));
			}

			// Check if Hard 1 difficulty
			else if (Character->m_CharDDifficulty->GetDDifficulty() == EDDifficulty::HARD_01)
			{
				print("DIFFICULTY - HARD_01");

				// Set the difficulty within the Game Instance Class, for initial difficulty within Level_02
				GameInstance->m_finalDifficulty = EFinalDifficulty::HARD_01;

				// Save difficulty details to text file
				SaveDataToTextFile(FString("Level_01"), FString("Section 05"),
								   FString("HARD_01"), m_totalTime, m_movementTime,
								   m_inLightTime, FString("05"));
			}

			// Print error message if difficulty equals anything other than Easy_01, Medium_01 or Hard_01
			else
			{
				print("DIFFICULTY - ERROR SETTING FINAL DIFFICULTY");
			}
		}
	}
	
//############################################################################################################################
											// LEVEL 02 SECTIONS
//############################################################################################################################

	else if (m_currentLevel == "Level_02")
	{
		// Set the total time variable to equal the current total time
		m_totalTime = FString::FromInt(Gamemode->GetSecondsInt());

		// Set the total movement time variable to equal the current total movement time
		m_movementTime = FString::FromInt(Character->GetTotalMovementTime());

		// Set the total in light time variable to equal the current total in light time
		m_inLightTime = FString::FromInt(Character->GetTotalInLightTime());

		//#####################################################################################################
									// SECTION 1 TRIGGER BOX
		//#####################################################################################################
		// Check if player is within the first section trigger box
		if (S1)
		{
			print("SECTION 1");

			// Set boolean for section01 in the character class to true and the other section booleans to false
			Character->m_section01 = true;
			Character->m_section02 = false;
			Character->m_section03 = false;
			Character->m_section04 = false;
			Character->m_section05 = false;

			// Check if easy difficulty
			if (Character->m_CharDDifficulty->GetDDifficulty() == EDDifficulty::EASY_01)
			{
				print("DIFFICULTY - EASY");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L2S1EasyModeSetup.Num(); i++)
				{
					m_L2S1EasyModeSetup[i]->Destroy();
				}

				// Set difficulty within the character class
				Character->SetDifficulty(ESetDifficulty::EASY_01);

				// Save difficulty details to text file
				SaveDataToTextFile(FString("Level_02"), FString("Section 01"),
								   FString("EASY_01"), m_totalTime, m_movementTime,
								   m_inLightTime, FString("01"));
			}

			// Check if medium difficulty
			else if (Character->m_CharDDifficulty->GetDDifficulty() == EDDifficulty::MEDIUM_01)
			{
				print("DIFFICULTY - MEDIUM");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L2S1MediumModeSetup.Num(); i++)
				{
					m_L2S1MediumModeSetup[i]->Destroy();
				}
				// Set difficulty within the character class
				Character->SetDifficulty(ESetDifficulty::MEDIUM_01);

				// Save difficulty details to text file
				SaveDataToTextFile(FString("Level_02"), FString("Section 01"),
								   FString("MEDIUM_01"), m_totalTime, m_movementTime,
								   m_inLightTime, FString("01"));
			}

			// Check if hard difficuly
			else if (Character->m_CharDDifficulty->GetDDifficulty() == EDDifficulty::HARD_01)
			{
				print("DIFFICULTY - HARD");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L2S1HardModeSetup.Num(); i++)
				{
					m_L2S1HardModeSetup[i]->Destroy();
				}

				// Set difficulty within the character class
				Character->SetDifficulty(ESetDifficulty::HARD_01);

				// Save difficulty details to text file
				SaveDataToTextFile(FString("Level_02"), FString("Section 01"),
								   FString("HARD_01"), m_totalTime, m_movementTime,
								   m_inLightTime, FString("01"));
			}

			else
			{
				print("ERROR - NO SET DIFFICULTY - Difficulty check function");
			}
		}

		//#####################################################################################################
									// SECTION 2 TRIGGER BOX
		//#####################################################################################################
		// Check if player is within the second section trigger box
		else if (S2)
		{
			print("SECTION 2");

			// Set boolean for section02 in the character class to true and the other section booleans to false
			Character->m_section01 = false;
			Character->m_section02 = true;
			Character->m_section03 = false;
			Character->m_section04 = false;
			Character->m_section05 = false;

			// Check if Easy 1 difficulty
			if (Character->m_CharDDifficulty->GetDDifficulty() == EDDifficulty::EASY_01)
			{
				print("DIFFICULTY - EASY_01");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L2S2EasyMode1Setup.Num(); i++)
				{
					m_L2S2EasyMode1Setup[i]->Destroy();
				}

				// Set difficulty within the character class
				Character->SetDifficulty(ESetDifficulty::EASY_01);

				// Save difficulty details to text file
				SaveDataToTextFile(FString("Level_02"), FString("Section 02"),
								   FString("EASY_01"), m_totalTime, m_movementTime,
								   m_inLightTime, FString("02"));
			}

			// Check if Easy 2 difficulty
			else if (Character->m_CharDDifficulty->GetDDifficulty() == EDDifficulty::EASY_02)
			{
				print("DIFFICULTY - EASY_02");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L2S2EasyMode2Setup.Num(); i++)
				{
					m_L2S2EasyMode2Setup[i]->Destroy();
				}

				// Set difficulty within the character class
				Character->SetDifficulty(ESetDifficulty::EASY_02);

				// Save difficulty details to text file
				SaveDataToTextFile(FString("Level_02"), FString("Section 02"),
								   FString("EASY_02"), m_totalTime, m_movementTime,
								   m_inLightTime, FString("02"));
			}

			// Check if Medium 1 difficulty
			else if (Character->m_CharDDifficulty->GetDDifficulty() == EDDifficulty::MEDIUM_01)
			{
				print("DIFFICULTY - MEDIUM_01");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L2S2MediumMode1Setup.Num(); i++)
				{
					m_L2S2MediumMode1Setup[i]->Destroy();
				}

				// Set difficulty within the character class
				Character->SetDifficulty(ESetDifficulty::MEDIUM_01);

				// Save difficulty details to text file
				SaveDataToTextFile(FString("Level_02"), FString("Section 02"),
								   FString("MEDIUM_01"), m_totalTime, m_movementTime,
								   m_inLightTime, FString("02"));
			}

			// Check if Medium 2 difficulty
			else if (Character->m_CharDDifficulty->GetDDifficulty() == EDDifficulty::MEDIUM_02)
			{
				print("DIFFICULTY - MEDIUM_02");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L2S2MediumMode2Setup.Num(); i++)
				{
					m_L2S2MediumMode2Setup[i]->Destroy();
				}

				// Set difficulty within the character class
				Character->SetDifficulty(ESetDifficulty::MEDIUM_02);

				// Save difficulty details to text file
				SaveDataToTextFile(FString("Level_02"), FString("Section 02"),
								   FString("MEDIUM_02"), m_totalTime, m_movementTime,
								   m_inLightTime, FString("02"));
			}

			// Check if Hard 1 difficulty
			else if (Character->m_CharDDifficulty->GetDDifficulty() == EDDifficulty::HARD_01)
			{
				print("DIFFICULTY - HARD_01");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L2S2HardMode1Setup.Num(); i++)
				{
					m_L2S2HardMode1Setup[i]->Destroy();
				}

				// Set difficulty within the character class
				Character->SetDifficulty(ESetDifficulty::HARD_01);

				// Save difficulty details to text file
				SaveDataToTextFile(FString("Level_02"), FString("Section 02"),
								   FString("HARD_01"), m_totalTime, m_movementTime,
								   m_inLightTime, FString("02"));
			}

			// Check if Hard 2 difficulty
			else if (Character->m_CharDDifficulty->GetDDifficulty() == EDDifficulty::HARD_02)
			{
				print("DIFFICULTY - HARD_02");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L2S2HardMode2Setup.Num(); i++)
				{
					m_L2S2HardMode2Setup[i]->Destroy();
				}

				// Set difficulty within the character class
				Character->SetDifficulty(ESetDifficulty::HARD_02);

				// Save difficulty details to text file
				SaveDataToTextFile(FString("Level_02"), FString("Section 02"),
								   FString("HARD_02"), m_totalTime, m_movementTime,
								   m_inLightTime, FString("02"));
			}
		}

		//#####################################################################################################
									// SECTION 3 TRIGGER BOX
		//#####################################################################################################
		// Check if player is within the third section trigger box
		else if (S3)
		{
			print("SECTION 3");

			// Set boolean for section03 in the character class to true and the other section booleans to false
			Character->m_section01 = false;
			Character->m_section02 = false;
			Character->m_section03 = true;
			Character->m_section04 = false;
			Character->m_section05 = false;

			// Check if Easy 1 difficulty
			if (Character->m_CharDDifficulty->GetDDifficulty() == EDDifficulty::EASY_01)
			{
				print("DIFFICULTY - EASY_01");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L2S3EasyMode1Setup.Num(); i++)
				{
					m_L2S3EasyMode1Setup[i]->Destroy();
				}

				// Set difficulty within the character class
				Character->SetDifficulty(ESetDifficulty::EASY_01);

				// Save difficulty details to text file
				SaveDataToTextFile(FString("Level_02"), FString("Section 03"),
								   FString("EASY_01"), m_totalTime, m_movementTime,
								   m_inLightTime, FString("03"));
			}

			// Check if Easy 2 difficulty
			else if (Character->m_CharDDifficulty->GetDDifficulty() == EDDifficulty::EASY_02)
			{
				print("DIFFICULTY - EASY_02");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L2S3EasyMode2Setup.Num(); i++)
				{
					m_L2S3EasyMode2Setup[i]->Destroy();
				}

				// Set difficulty within the character class
				Character->SetDifficulty(ESetDifficulty::EASY_02);

				// Save difficulty details to text file
				SaveDataToTextFile(FString("Level_02"), FString("Section 03"),
								   FString("EASY_02"), m_totalTime, m_movementTime,
								   m_inLightTime, FString("03"));
			}

			// Check if Medium 1 difficulty
			else if (Character->m_CharDDifficulty->GetDDifficulty() == EDDifficulty::MEDIUM_01)
			{
				print("DIFFICULTY - MEDIUM_01");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L2S3MediumMode1Setup.Num(); i++)
				{
					m_L2S3MediumMode1Setup[i]->Destroy();
				}

				// Set difficulty within the character class
				Character->SetDifficulty(ESetDifficulty::MEDIUM_01);

				// Save difficulty details to text file
				SaveDataToTextFile(FString("Level_02"), FString("Section 03"),
								   FString("MEDIUM_01"), m_totalTime, m_movementTime,
								   m_inLightTime, FString("03"));
			}

			// Check if Medium 2 difficulty
			else if (Character->m_CharDDifficulty->GetDDifficulty() == EDDifficulty::MEDIUM_02)
			{
				print("DIFFICULTY - MEDIUM_02");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L2S3MediumMode2Setup.Num(); i++)
				{
					m_L2S3MediumMode2Setup[i]->Destroy();
				}

				// Set difficulty within the character class
				Character->SetDifficulty(ESetDifficulty::MEDIUM_02);

				// Save difficulty details to text file
				SaveDataToTextFile(FString("Level_02"), FString("Section 03"),
								   FString("MEDIUM_02"), m_totalTime, m_movementTime,
								   m_inLightTime, FString("03"));
			}

			// Check if Hard 1 difficulty
			else if (Character->m_CharDDifficulty->GetDDifficulty() == EDDifficulty::HARD_01)
			{
				print("DIFFICULTY - HARD_01");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L2S3HardMode1Setup.Num(); i++)
				{
					m_L2S3HardMode1Setup[i]->Destroy();
				}

				// Set difficulty within the character class
				Character->SetDifficulty(ESetDifficulty::HARD_01);

				// Save difficulty details to text file
				SaveDataToTextFile(FString("Level_02"), FString("Section 03"),
								   FString("HARD_01"), m_totalTime, m_movementTime,
								   m_inLightTime, FString("03"));
			}

			// Check if Hard 2 difficulty
			else if (Character->m_CharDDifficulty->GetDDifficulty() == EDDifficulty::HARD_02)
			{
				print("DIFFICULTY - HARD_02");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L2S3HardMode2Setup.Num(); i++)
				{
					m_L2S3HardMode2Setup[i]->Destroy();
				}

				// Set difficulty within the character class
				Character->SetDifficulty(ESetDifficulty::HARD_02);

				// Save difficulty details to text file
				SaveDataToTextFile(FString("Level_02"), FString("Section 03"),
								   FString("HARD_02"), m_totalTime, m_movementTime,
								   m_inLightTime, FString("03"));
			}
		}

		//#####################################################################################################
									// SECTION 4 TRIGGER BOX
		//#####################################################################################################
		// Check if player is within the fourth and final section trigger box
		else if (S4)
		{
			print("FINAL TRIGGERBOX");

			// Set boolean for section04 in the character class to true and the other section booleans to false
			Character->m_section01 = false;
			Character->m_section02 = false;
			Character->m_section03 = false;
			Character->m_section04 = true;
			Character->m_section05 = false;

			// Check if Easy 1 difficulty
			if (Character->m_CharDDifficulty->GetDDifficulty() == EDDifficulty::EASY_01)
			{
				print("DIFFICULTY - EASY_01");

				// Set difficulty within the character class
				Character->SetDifficulty(ESetDifficulty::EASY_01);

				// Save difficulty details to text file
				SaveDataToTextFile(FString("Level_02"), FString("Section 04"),
								   FString("EASY_01"), m_totalTime, m_movementTime,
								   m_inLightTime, FString("04"));
			}

			// Check if Easy 2 difficulty
			else if (Character->m_CharDDifficulty->GetDDifficulty() == EDDifficulty::EASY_02)
			{
				print("DIFFICULTY - EASY_02");

				// Set difficulty within the character class
				Character->SetDifficulty(ESetDifficulty::EASY_02);

				// Save difficulty details to text file
				SaveDataToTextFile(FString("Level_02"), FString("Section 04"),
								   FString("EASY_02"), m_totalTime, m_movementTime,
								   m_inLightTime, FString("04"));
			}

			// Check if Medium 1 difficulty
			else if (Character->m_CharDDifficulty->GetDDifficulty() == EDDifficulty::MEDIUM_01)
			{
				print("DIFFICULTY - MEDIUM_01");

				// Set difficulty within the character class
				Character->SetDifficulty(ESetDifficulty::MEDIUM_01);

				// Save difficulty details to text file
				SaveDataToTextFile(FString("Level_02"), FString("Section 04"),
								   FString("MEDIUM_01"), m_totalTime, m_movementTime,
								   m_inLightTime, FString("04"));
			}

			// Check if Medium 2 difficulty
			else if (Character->m_CharDDifficulty->GetDDifficulty() == EDDifficulty::MEDIUM_02)
			{
				print("DIFFICULTY - MEDIUM_02");

				// Set difficulty within the character class
				Character->SetDifficulty(ESetDifficulty::MEDIUM_02);

				// Save difficulty details to text file
				SaveDataToTextFile(FString("Level_02"), FString("Section 04"),
								   FString("MEDIUM_02"), m_totalTime, m_movementTime,
								   m_inLightTime, FString("04"));
			}

			// Check if Hard 1 difficulty
			else if (Character->m_CharDDifficulty->GetDDifficulty() == EDDifficulty::HARD_01)
			{
				print("DIFFICULTY - HARD_01");

				// Set difficulty within the character class
				Character->SetDifficulty(ESetDifficulty::HARD_01);

				// Save difficulty details to text file
				SaveDataToTextFile(FString("Level_02"), FString("Section 04"),
								   FString("HARD_01"), m_totalTime, m_movementTime,
								   m_inLightTime, FString("04"));
			}

			// Check if Hard 2 difficulty
			else if (Character->m_CharDDifficulty->GetDDifficulty() == EDDifficulty::HARD_02)
			{
				print("DIFFICULTY - HARD_02");

				// Set difficulty within the character class
				Character->SetDifficulty(ESetDifficulty::HARD_02);

				// Save difficulty details to text file
				SaveDataToTextFile(FString("Level_02"), FString("Section 04"),
								   FString("HARD_02"), m_totalTime, m_movementTime,
								   m_inLightTime, FString("04"));
			}
		}
	}
}

void ADDATriggerBox::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	Gamemode->GetElapsedTime();

	// Get the current level name and set it into the FString variable "m_currentLevel"
	m_currentLevel = Gamemode->GetLevelName();

	print("Level Name: " + m_currentLevel);

	/*if (m_currentLevel == "Level_01")
	{
		if (OverlappedActor->GetName() == "DDATriggerBox_01")
		{
			if (OtherActor && OtherActor != this && OtherActor->GetName() == m_playerCharacterName)
			{
				const int m_L1SecondsCheck = 5;
				const int m_L1EasyMovementCheck = 5;
				const int m_L1MediumMovementCheck01 = 3;
				const int m_L1MediumMovementCheck02 = 5;
				const int m_L1HardMovementCheck = 2;
				
				print(FString::FromInt(m_L1SecondsCheck));
			}
		}
		else
		{
			if (OtherActor && OtherActor != this && OtherActor->GetName() == m_playerCharacterName)
			{
				const int m_L1SecondsCheck = 10;
				const int m_L1EasyMovementCheck = 8;
				const int m_L1MediumMovementCheck01 = 5;
				const int m_L1MediumMovementCheck02 = 7;
				const int m_L1HardMovementCheck = 4;

				print(FString::FromInt(m_L1SecondsCheck));
			}
		}
	}*/

//############################################################################################################################
											// LEVEL 01 TRIGGER BOXES
//############################################################################################################################

	if (m_currentLevel == "Level_01")
	{
	//#####################################################################################################
								// SECTION 1 TRIGGER BOX
	//#####################################################################################################

		// Check if the trigger box is the first one
		if (OverlappedActor->GetName() == "DDATriggerBox_01")
		{
			// Check if the actor overlapping the trigger box is the same as the FString variable holding the character name
			if (OtherActor && OtherActor != this && OtherActor->GetName() == m_playerCharacterName)
			{
				// Get the current seconds spent in level
				m_intSeconds = Gamemode->GetSecondsInt();

				// Check if seconds is greater than or equal to 5
				if (m_intSeconds >= 5)
				{
					// Check if total movement time is greater than 5
					if (Character->GetTotalMovementTime() > 5)
					{
						// Set starting difficulty to Easy by using the Starting Difficulty function within the difficulty class
						Character->m_CharDDifficulty->StartingDifficulty(true);
					}

					// Check if total movement time is equal to 3, 4, or 5
					else if (Character->GetTotalMovementTime() >= 3
						  && Character->GetTotalMovementTime() <= 5)
					{
						// Set starting difficulty to Medium by using the Starting Difficulty function within the difficulty class
						Character->m_CharDDifficulty->StartingDifficulty(false, true);
					}

					// Check if total movement time is equal to 0, 1, or 2
					else if (Character->GetTotalMovementTime() <= 2)
					{
						// Set starting difficulty to Hard by using the Starting Difficulty function within the difficulty class
						Character->m_CharDDifficulty->StartingDifficulty(false, false, true);
					}
				}
				// If seconds equals less than 5
				else
				{
					// Check if total movement time is equal to the total time spent in the level
					if (Character->GetTotalMovementTime() == m_intSeconds)
					{
						// Set starting difficulty to Hard by using the Starting Difficulty function within the difficulty class
						Character->m_CharDDifficulty->StartingDifficulty(false, false, true);
					}

					// Check if total movement time is equal to the total time - 1
					else if (Character->GetTotalMovementTime() == (m_intSeconds - 1))
					{
						// Set starting difficulty to Medium by using the Starting Difficulty function within the difficulty class
						Character->m_CharDDifficulty->StartingDifficulty(false, true);
					}

					// Otherwise, set to hard mode
					else
					{
						// Set starting difficulty to Hard by using the Starting Difficulty function within the difficulty class
						Character->m_CharDDifficulty->StartingDifficulty(false, false, true);
					}
				}

				// Setup the difficulty within the level
				DifficultyFinializedSetup(true);

				// Destroy the trigger box
				OverlappedActor->Destroy();
			}
		}

	//#####################################################################################################
								// SECTION 2 TRIGGER BOX
	//#####################################################################################################

		// Check if the trigger box is the second one
		else if (OverlappedActor->GetName() == "DDATriggerBox_02")
		{
			// Check if the actor overlapping the trigger box is the same as the FString variable holding the character name
			if (OtherActor && OtherActor != this && OtherActor->GetName() == m_playerCharacterName)
			{
				// Get the current seconds spent in level
				m_intSeconds = Gamemode->GetSecondsInt();

				// Check if seconds is greater than or equal to 15
				if (m_intSeconds >= 15)
				{
					// Check if total movement time is greater than 13
					if (Character->GetTotalMovementTime() >= 13)
					{
						// Check if total time in sentry light is equal to 0
						if (Character->GetTotalInLightTime() == 0)
						{
							// Make difficulty harder by calling the Hard Difficulty function within the difficulty class
							Character->m_CharDDifficulty->HardDifficulty();
						}

						// Check if total time in sentry light is 1, 2 or 3
						else if (Character->GetTotalInLightTime() >= 1 && Character->GetTotalInLightTime() <= 3)
						{
							// Make difficulty medium by calling the Medium Difficulty function within the difficulty class
							Character->m_CharDDifficulty->MediumDifficulty();
						}

						// Check if total time in sentry light is 4 or more
						else if (Character->GetTotalInLightTime() >= 4)
						{
							// Make difficulty easier by calling the Easy Difficulty function within the difficulty class
							Character->m_CharDDifficulty->EasyDifficulty();
						}
					}

					// Check if total movement time is equal to 9, 10, 11, or 12
					else if (Character->GetTotalMovementTime() >= 9 && Character->GetTotalMovementTime() <= 12)
					{
						// If total in light equals 2 or less
						if (Character->GetTotalInLightTime() <= 2)
						{
							// Make difficulty medium by calling the Medium Difficulty function within the difficulty class
							Character->m_CharDDifficulty->MediumDifficulty();
						}

						// Check if total in light time equals greater than or equal to 3
						else if (Character->GetTotalInLightTime() >= 3)
						{
							// Make difficulty harder by calling the Hard Difficulty function within the difficulty class
							Character->m_CharDDifficulty->HardDifficulty();
						}
					}

					// Check if total movement time is equal to or less than 8
					else if (Character->GetTotalMovementTime() <= 8)
					{
						// Make difficulty harder by calling the Hard Difficulty function within the difficulty class
						Character->m_CharDDifficulty->HardDifficulty();
					}
				}

				// If seconds equals less than 15
				else
				{
					// Check if total movement time is greater than or equal to the total time - 1
					if (Character->GetTotalMovementTime() >= (m_intSeconds - 1))
					{
						print("movement >= total - 1");

						// If Hard_01 or Hard_02 difficulty, set difficulty to Hard_02
						// Otherwise, difficulty will be set to Hard_01 regardless of current difficulty
						Character->m_CharDDifficulty->PureHardDifficulty();
					}

					// Else, check if total movement time equals total time - 2 or - 3
					else if (Character->GetTotalMovementTime() == (m_intSeconds - 2) || Character->GetTotalMovementTime() == (m_intSeconds - 3))
					{
						// Make difficulty medium by calling the Medium Difficulty function within the difficulty class
						Character->m_CharDDifficulty->MediumDifficulty();
					}

					// Otherwise, set to hard mode
					else
					{
						// If Hard_01 or Hard_02 difficulty, set difficulty to Hard_02
						// Otherwise, difficulty will be set to Hard_01 regardless of current difficulty
						Character->m_CharDDifficulty->PureHardDifficulty();
					}
				}

				// Setup the difficulty within the level
				DifficultyFinializedSetup(false, true);

				// Destroy the trigger box
				OverlappedActor->Destroy();
			}
		}

	//#####################################################################################################
								// SECTION 3 TRIGGER BOX
	//#####################################################################################################

		// Check if the trigger box is the third one
		else if (OverlappedActor->GetName() == "DDATriggerBox_03")
		{
			// Check if the actor overlapping the trigger box is the same as the FString variable holding the character name
			if (OtherActor && OtherActor != this && OtherActor->GetName() == m_playerCharacterName)
			{
				// Get the current seconds spent in level
				m_intSeconds = Gamemode->GetSecondsInt();

				// Check if seconds is greater than or equal to 25
				if (m_intSeconds >= 25)
				{
					// Check if total movement time is greater than 20
					if (Character->GetTotalMovementTime() >= 20)
					{
						// Check if total time in sentry light is less than or equal to 1
						if (Character->GetTotalInLightTime() <= 1)
						{
							// Make difficulty harder by calling the Hard Difficulty function within the difficulty class
							Character->m_CharDDifficulty->HardDifficulty();
						}

						// Check if total time in sentry light is between 2-5
						else if (Character->GetTotalInLightTime() >= 2 && Character->GetTotalInLightTime() <= 5)
						{
							// Make difficulty medium by calling the Medium Difficulty function within the difficulty class
							Character->m_CharDDifficulty->MediumDifficulty();
						}

						// Check if total time in sentry light is 6 or more
						else if (Character->GetTotalInLightTime() >= 6)
						{
							// Make difficulty easier by calling the Easy Difficulty function within the difficulty class
							Character->m_CharDDifficulty->EasyDifficulty();
						}
					}

					// Check if total movement time is equal to 17, 18, or 19
					else if (Character->GetTotalMovementTime() >= 17 && Character->GetTotalMovementTime() <= 19)
					{
						// If total in light equals 6 or less
						if (Character->GetTotalInLightTime() <= 6)
						{
							// Make difficulty medium by calling the Medium Difficulty function within the difficulty class
							Character->m_CharDDifficulty->MediumDifficulty();
						}

						// Check if total in light time equals greater than or equal to 7
						else if (Character->GetTotalInLightTime() >= 7)
						{
							// Make difficulty harder by calling the Hard Difficulty function within the difficulty class
							Character->m_CharDDifficulty->HardDifficulty();
						}
					}

					// Check if total movement time is equal to or less than 16
					else if (Character->GetTotalMovementTime() <= 16)
					{
						// Make difficulty harder by calling the Hard Difficulty function within the difficulty class
						Character->m_CharDDifficulty->HardDifficulty();
					}
				}

				// If seconds equals less than 20
				else
				{
					// Check if total movement time is equal to or greater than the total time - 2
					if (Character->GetTotalMovementTime() >= (m_intSeconds - 2))
					{
						// If Hard_01 or Hard_02 difficulty, set difficulty to Hard_02
						// Otherwise, difficulty will be set to Hard_01 regardless of current difficulty
						Character->m_CharDDifficulty->PureHardDifficulty();
					}

					// Else, check if total movement time equals total time - 3 or - 4
					else if (Character->GetTotalMovementTime() == (m_intSeconds - 3) || Character->GetTotalMovementTime() == (m_intSeconds - 4))
					{
						// Make difficulty medium by calling the Medium Difficulty function within the difficulty class
						Character->m_CharDDifficulty->MediumDifficulty();
					}

					// Otherwise, set to hard mode
					else
					{
						// If Hard_01 or Hard_02 difficulty, set difficulty to Hard_02
						// Otherwise, difficulty will be set to Hard_01 regardless of current difficulty
						Character->m_CharDDifficulty->PureHardDifficulty();
					}
				}

				// Setup the difficulty within the level
				DifficultyFinializedSetup(false, false, true);

				// Destroy the trigger box
				OverlappedActor->Destroy();
			}
		}

	//#####################################################################################################
								// SECTION 4 TRIGGER BOX
	//#####################################################################################################

		// Check if the trigger box is the fourth one
		else if (OverlappedActor->GetName() == "DDATriggerBox_04")
		{
			// Check if the actor overlapping the trigger box is the same as the FString variable holding the character name
			if (OtherActor && OtherActor != this && OtherActor->GetName() == m_playerCharacterName)
			{
				// Get the current seconds spent in level
				m_intSeconds = Gamemode->GetSecondsInt();

				// Check if seconds is greater than or equal to 45
				if (m_intSeconds >= 45)
				{
					// Check if total movement time is greater than 38
					if (Character->GetTotalMovementTime() >= 38)
					{
						// Check if total time in sentry light is less than or equal to 2
						if (Character->GetTotalInLightTime() <= 2)
						{
							// Make difficulty harder by calling the Hard Difficulty function within the difficulty class
							Character->m_CharDDifficulty->HardDifficulty();
						}

						// Check if total time in sentry light is between 3-6
						else if (Character->GetTotalInLightTime() >= 3 && Character->GetTotalInLightTime() <= 6)
						{
							// Make difficulty medium by calling the Medium Difficulty function within the difficulty class
							Character->m_CharDDifficulty->MediumDifficulty();
						}

						// Check if total time in sentry light is 7 or more
						else if (Character->GetTotalInLightTime() >= 7)
						{
							// Make difficulty easier by calling the Easy Difficulty function within the difficulty class
							Character->m_CharDDifficulty->EasyDifficulty();
						}
					}

					// Check if total movement time is equal to 36, or 37
					else if (Character->GetTotalMovementTime() >= 36 && Character->GetTotalMovementTime() <= 37)
					{
						// If total in light equals 6 or less
						if (Character->GetTotalInLightTime() <= 6)
						{
							// Make difficulty medium by calling the Medium Difficulty function within the difficulty class
							Character->m_CharDDifficulty->MediumDifficulty();
						}

						// Check if total in light time equals greater than or equal to 7
						else if (Character->GetTotalInLightTime() >= 7)
						{
							// Make difficulty harder by calling the Hard Difficulty function within the difficulty class
							Character->m_CharDDifficulty->HardDifficulty();
						}
					}

					// Check if total movement time is equal to or less than 35
					else if (Character->GetTotalMovementTime() <= 35)
					{
						// If Hard_01 or Hard_02 difficulty, set difficulty to Hard_02
						// Otherwise, difficulty will be set to Hard_01 regardless of current difficulty
						Character->m_CharDDifficulty->PureHardDifficulty();
					}
				}

				// If seconds equals less than 45
				else
				{
					// Check if total movement time is greater than or equal to the total time - 3
					if (Character->GetTotalMovementTime() >= (m_intSeconds - 3))
					{
						// If Hard_01 or Hard_02 difficulty, set difficulty to Hard_02
						// Otherwise, difficulty will be set to Hard_01 regardless of current difficulty
						Character->m_CharDDifficulty->PureHardDifficulty();
					}

					// Else, check if total movement time equals total time - 4 or - 5
					else if (Character->GetTotalMovementTime() == (m_intSeconds - 4) || Character->GetTotalMovementTime() >= (m_intSeconds - 5))
					{
						// Make difficulty medium by calling the Medium Difficulty function within the difficulty class
						Character->m_CharDDifficulty->MediumDifficulty();
					}

					// Otherwise, set to hard mode
					else
					{
						// If Hard_01 or Hard_02 difficulty, set difficulty to Hard_02
						// Otherwise, difficulty will be set to Hard_01 regardless of current difficulty
						Character->m_CharDDifficulty->PureHardDifficulty();
					}
				}

				// Setup the difficulty within the level
				DifficultyFinializedSetup(false, false, false, true);

				// Destroy the trigger box
				OverlappedActor->Destroy();
			}
		}

	//#####################################################################################################
								// SECTION 5 TRIGGER BOX
	//#####################################################################################################

		// Check if the trigger box is the fifth and last one for level 1
		else if (OverlappedActor->GetName() == "DDATriggerBox_05")
		{
			// Check if the actor overlapping the trigger box is the same as the FString variable holding the character name
			if (OtherActor && OtherActor != this && OtherActor->GetName() == m_playerCharacterName)
			{
				// Get the current seconds spent in level
				m_intSeconds = Gamemode->GetSecondsInt();

				// Check if seconds is greater than or equal to 50
				if (m_intSeconds >= 50)
				{
					// Check if total movement time is greater than 43
					if (Character->GetTotalMovementTime() >= 43)
					{
						// Check if total time in sentry light is between 0-3
						if (Character->GetTotalInLightTime() >= 3)
						{
							// Set final difficulty to Hard by using the Final Difficulty function within the difficulty class
							Character->m_CharDDifficulty->FinalDifficulty(false, false, true);
						}

						// Check if total time in sentry light is between 4-7
						else if (Character->GetTotalInLightTime() >= 4 && Character->GetTotalInLightTime() <= 7)
						{
							// Set final difficulty to Medium by using the Final Difficulty function within the difficulty class
							Character->m_CharDDifficulty->FinalDifficulty(false, true);
						}

						// Check if total time in sentry light is 8 or more
						else if (Character->GetTotalInLightTime() >= 8)
						{
							// Set final difficulty to Easy by using the Final Difficulty function within the difficulty class
							Character->m_CharDDifficulty->FinalDifficulty(true);
						}
					}

					// Check if total movement time is equal to 40, 41, or 42
					else if (Character->GetTotalMovementTime() >= 40 && Character->GetTotalMovementTime() <= 42)
					{
						// If total in light equals 7 or less
						if (Character->GetTotalInLightTime() <= 7)
						{
							// Set final difficulty to Medium by using the Final Difficulty function within the difficulty class
							Character->m_CharDDifficulty->FinalDifficulty(false, true);
						}

						// Check if total in light time equals greater than or equal to 8
						else if (Character->GetTotalInLightTime() >= 8)
						{
							// Set final difficulty to Hard by using the Final Difficulty function within the difficulty class
							Character->m_CharDDifficulty->FinalDifficulty(false, false, true);
						}
					}

					// Check if total movement time is equal to or less than 39
					else if (Character->GetTotalMovementTime() <= 39)
					{
						// Set final difficulty to Hard by using the Final Difficulty function within the difficulty class
						Character->m_CharDDifficulty->FinalDifficulty(false, false, true);
					}
				}

				// If seconds equals less than 45
				else
				{
					// Check if total movement time is greater than or equal to the total time - 4
					if (Character->GetTotalMovementTime() >= (m_intSeconds - 4))
					{
						// Set final difficulty to Hard by using the Final Difficulty function within the difficulty class
						Character->m_CharDDifficulty->FinalDifficulty(false, false, true);
					}

					// Else, check if total movement time equals total time - 5 or - 6
					else if (Character->GetTotalMovementTime() == (m_intSeconds - 5) || Character->GetTotalMovementTime() == (m_intSeconds - 6))
					{
						// Set final difficulty to Hard by using the Final Difficulty function within the difficulty class
						Character->m_CharDDifficulty->FinalDifficulty(false, true);
					}

					// Otherwise, set to hard mode
					else
					{
						// Set final difficulty to Hard by using the Final Difficulty function within the difficulty class
						Character->m_CharDDifficulty->FinalDifficulty(false, false, true);
					}
				}

				// Setup the difficulty within the level
				DifficultyFinializedSetup(false, false, false, false, true);

				// Destroy the trigger box
				OverlappedActor->Destroy();
			}
		}
	}

//############################################################################################################################
											// LEVEL 02 TRIGGER BOXES
//############################################################################################################################

	else if (m_currentLevel == "Level_02")
	{
	//#####################################################################################################
								// SECTION 1 TRIGGER BOX
	//#####################################################################################################

		// Check if the trigger box is the first one
		if (OverlappedActor->GetName() == "DDATriggerBox_01")
		{
			// Check if the actor overlapping the trigger box is the same as the FString variable holding the character name
			if (OtherActor && OtherActor != this && OtherActor->GetName() == m_playerCharacterName)
			{
				// If Easy_01 at the end of Level_01, set difficulty to Easy_01
				if (GameInstance->GetDifficulty() == EFinalDifficulty::EASY_01)
				{
					// Set starting difficulty to Easy by using the Starting Difficulty function within the difficulty class
					Character->m_CharDDifficulty->StartingDifficulty(true);
				}
				
				// If Medium_01 at the end of Level_01, set difficulty to Medium_01
				else if (GameInstance->GetDifficulty() == EFinalDifficulty::MEDIUM_01)
				{
					// Set starting difficulty to Medium by using the Starting Difficulty function within the difficulty class
					Character->m_CharDDifficulty->StartingDifficulty(false, true);
				}

				// If Hard_01 at the end of Level_01, set difficulty to Hard_01
				else if (GameInstance->GetDifficulty() == EFinalDifficulty::HARD_01)
				{
					// Set starting difficulty to Hard by using the Starting Difficulty function within the difficulty class
					Character->m_CharDDifficulty->StartingDifficulty(false, false, true);
				}

				// Else, print ERROR message
				else
				{
					print("ERROR GETTING LAST SET DIFFICULTY");
				}

				// Setup the difficulty within the level
				DifficultyFinializedSetup(true);

				// Destroy the trigger box
				OverlappedActor->Destroy();
			}
		}

	//#####################################################################################################
								// SECTION 2 TRIGGER BOX
	//#####################################################################################################

		// Check if the trigger box is the first one
		if (OverlappedActor->GetName() == "DDATriggerBox_02")
		{
			// Check if the actor overlapping the trigger box is the same as the FString variable holding the character name
			if (OtherActor && OtherActor != this && OtherActor->GetName() == m_playerCharacterName)
			{
				// Get the current seconds spent in level
				m_intSeconds = Gamemode->GetSecondsInt();

				// Check if seconds is greater than or equal to 17
				if (m_intSeconds >= 17)
				{
					// Check if total movement time is greater than 16
					if (Character->GetTotalMovementTime() >= 16)
					{
						// Check if total time in sentry light is equal to 0
						if (Character->GetTotalInLightTime() == 0)
						{
							// Make difficulty harder by calling the Hard Difficulty function within the difficulty class
							Character->m_CharDDifficulty->HardDifficulty();
						}

						// Check if total time in sentry light is 1, 2 or 3
						else if (Character->GetTotalInLightTime() >= 1 && Character->GetTotalInLightTime() <= 3)
						{
							// Make difficulty medium by calling the Medium Difficulty function within the difficulty class
							Character->m_CharDDifficulty->MediumDifficulty();
						}

						// Check if total time in sentry light is 4 or more
						else if (Character->GetTotalInLightTime() >= 4)
						{
							// Make difficulty easier by calling the Easy Difficulty function within the difficulty class
							Character->m_CharDDifficulty->EasyDifficulty();
						}
					}

					// Check if total movement time is equal to 14, or 15
					else if (Character->GetTotalMovementTime() == 14 && Character->GetTotalMovementTime() == 15)
					{
						// If total in light equals 2 or less
						if (Character->GetTotalInLightTime() <= 2)
						{
							// Make difficulty medium by calling the Medium Difficulty function within the difficulty class
							Character->m_CharDDifficulty->MediumDifficulty();
						}

						// Check if total in light time equals greater than or equal to 3
						else if (Character->GetTotalInLightTime() >= 3)
						{
							// Make difficulty harder by calling the Hard Difficulty function within the difficulty class
							Character->m_CharDDifficulty->HardDifficulty();
						}
					}

					// Check if total movement time is equal to or less than 13
					else if (Character->GetTotalMovementTime() <= 13)
					{
						// Make difficulty harder by calling the Hard Difficulty function within the difficulty class
						Character->m_CharDDifficulty->HardDifficulty();
					}
				}

				// If seconds equals less than 17
				else
				{
					// Check if total movement time is greater than or equal to the total time - 1
					if (Character->GetTotalMovementTime() >= (m_intSeconds - 1))
					{
						print("movement >= total - 1");

						// If Hard_01 or Hard_02 difficulty, set difficulty to Hard_02
						// Otherwise, difficulty will be set to Hard_01 regardless of current difficulty
						Character->m_CharDDifficulty->PureHardDifficulty();
					}

					// Else, check if total movement time equals total time - 2 or - 3
					else if (Character->GetTotalMovementTime() == (m_intSeconds - 2) || Character->GetTotalMovementTime() == (m_intSeconds - 3))
					{
						print("Movement = total - 2 or - 3");

						// Make difficulty medium by calling the Medium Difficulty function within the difficulty class
						Character->m_CharDDifficulty->MediumDifficulty();
					}

					// Otherwise, set to hard mode
					else
					{
						// If Hard_01 or Hard_02 difficulty, set difficulty to Hard_02
						// Otherwise, difficulty will be set to Hard_01 regardless of current difficulty
						Character->m_CharDDifficulty->PureHardDifficulty();
					}
				}

				// Setup the difficulty within the level
				DifficultyFinializedSetup(false, true);

				// Destroy the trigger box
				OverlappedActor->Destroy();
			}
		}

	//#####################################################################################################
								// SECTION 3 TRIGGER BOX
	//#####################################################################################################

		// Check if the trigger box is the third one
		if (OverlappedActor->GetName() == "DDATriggerBox_03")
		{
			// Check if the actor overlapping the trigger box is the same as the FString variable holding the character name
			if (OtherActor && OtherActor != this && OtherActor->GetName() == m_playerCharacterName)
			{
				// Get the current seconds spent in level
				m_intSeconds = Gamemode->GetSecondsInt();

				// Check if seconds is greater than or equal to 30
				if (m_intSeconds >= 30)
				{
					// Check if total movement time is greater than 28
					if (Character->GetTotalMovementTime() >= 28)
					{
						// Check if total time in sentry light is less than or equal to 1
						if (Character->GetTotalInLightTime() <= 1)
						{
							// Make difficulty harder by calling the Hard Difficulty function within the difficulty class
							Character->m_CharDDifficulty->HardDifficulty();
						}

						// Check if total time in sentry light is 2, 3 or 4
						else if (Character->GetTotalInLightTime() >= 2 && Character->GetTotalInLightTime() <= 4)
						{
							// Make difficulty medium by calling the Medium Difficulty function within the difficulty class
							Character->m_CharDDifficulty->MediumDifficulty();
						}

						// Check if total time in sentry light is greater than or equal to 5
						else if (Character->GetTotalInLightTime() >= 5)
						{
							// Make difficulty easier by calling the Easy Difficulty function within the difficulty class
							Character->m_CharDDifficulty->EasyDifficulty();
						}
					}

					// Check if total movement time is equal to 26 or 27
					else if (Character->GetTotalMovementTime() == 26 && Character->GetTotalMovementTime() == 27)
					{
						// If total in light is less than or equal to 3
						if (Character->GetTotalInLightTime() <= 3)
						{
							// Make difficulty medium by calling the Medium Difficulty function within the difficulty class
							Character->m_CharDDifficulty->MediumDifficulty();
						}

						// Check if total in light time is greater than or equal to 4
						else if (Character->GetTotalInLightTime() >= 4)
						{
							// Make difficulty harder by calling the Hard Difficulty function within the difficulty class
							Character->m_CharDDifficulty->HardDifficulty();
						}
					}

					// Check if total movement time is less than or equal to 25
					else if (Character->GetTotalMovementTime() <= 25)
					{
						// Make difficulty harder by calling the Hard Difficulty function within the difficulty class
						Character->m_CharDDifficulty->HardDifficulty();
					}
				}

				// If seconds equals less than 30
				else
				{
					// Check if total movement time is greater than or equal to the total time - 2
					if (Character->GetTotalMovementTime() >= (m_intSeconds - 2))
					{
						print("movement >= total - 2");

						// If Hard_01 or Hard_02 difficulty, set difficulty to Hard_02
						// Otherwise, difficulty will be set to Hard_01 regardless of current difficulty
						Character->m_CharDDifficulty->PureHardDifficulty();
					}

					// Else, check if total movement time equals total time - 3 or - 4
					else if (Character->GetTotalMovementTime() == (m_intSeconds - 3) || Character->GetTotalMovementTime() == (m_intSeconds - 4))
					{
						print("Movement = total - 3 or - 4");

						// Make difficulty medium by calling the Medium Difficulty function within the difficulty class
						Character->m_CharDDifficulty->MediumDifficulty();
					}

					// Otherwise, set to hard mode
					else
					{
						// If Hard_01 or Hard_02 difficulty, set difficulty to Hard_02
						// Otherwise, difficulty will be set to Hard_01 regardless of current difficulty
						Character->m_CharDDifficulty->PureHardDifficulty();
					}
				}

				// Setup the difficulty within the level
				DifficultyFinializedSetup(false, false, true);

				// Destroy the trigger box
				OverlappedActor->Destroy();
			}
		}

	//#####################################################################################################
								// SECTION 4 TRIGGER BOX (FINAL)
	//#####################################################################################################

		// Check if the trigger box is the fourth and final one
		if (OverlappedActor->GetName() == "DDATriggerBox_04")
		{
			// Check if the actor overlapping the trigger box is the same as the FString variable holding the character name
			if (OtherActor && OtherActor != this && OtherActor->GetName() == m_playerCharacterName)
			{
				// Get the current seconds spent in level
				m_intSeconds = Gamemode->GetSecondsInt();

				// Check if seconds is greater than or equal to 53
				if (m_intSeconds >= 53)
				{
					// Check if total movement time is greater than 50
					if (Character->GetTotalMovementTime() >= 50)
					{
						// Check if total time in sentry light is less than or equal to 2
						if (Character->GetTotalInLightTime() <= 2)
						{
							// Make difficulty harder by calling the Hard Difficulty function within the difficulty class
							Character->m_CharDDifficulty->HardDifficulty();
						}

						// Check if total time in sentry light is 3, 4 or 5
						else if (Character->GetTotalInLightTime() >= 3 && Character->GetTotalInLightTime() <= 5)
						{
							// Make difficulty medium by calling the Medium Difficulty function within the difficulty class
							Character->m_CharDDifficulty->MediumDifficulty();
						}

						// Check if total time in sentry light is greater than or equal to 6
						else if (Character->GetTotalInLightTime() >= 6)
						{
							// Make difficulty easier by calling the Easy Difficulty function within the difficulty class
							Character->m_CharDDifficulty->EasyDifficulty();
						}
					}

					// Check if total movement time is equal to 47, 48 or 49
					else if (Character->GetTotalMovementTime() >= 47 && Character->GetTotalMovementTime() <= 49)
					{
						// If total in light is less than or equal to 4
						if (Character->GetTotalInLightTime() <= 4)
						{
							// Make difficulty medium by calling the Medium Difficulty function within the difficulty class
							Character->m_CharDDifficulty->MediumDifficulty();
						}

						// Check if total in light time is greater than or equal to 5
						else if (Character->GetTotalInLightTime() >= 5)
						{
							// Make difficulty harder by calling the Hard Difficulty function within the difficulty class
							Character->m_CharDDifficulty->HardDifficulty();
						}
					}

					// Check if total movement time is less than or equal to 46
					else if (Character->GetTotalMovementTime() <= 46)
					{
						// Make difficulty harder by calling the Hard Difficulty function within the difficulty class
						Character->m_CharDDifficulty->HardDifficulty();
					}
				}

				// If seconds equals less than 50
				else
				{
					// Check if total movement time is greater than or equal to the total time - 3
					if (Character->GetTotalMovementTime() >= (m_intSeconds - 3))
					{
						print("movement >= total - 3");

						// If Hard_01 or Hard_02 difficulty, set difficulty to Hard_02
						// Otherwise, difficulty will be set to Hard_01 regardless of current difficulty
						Character->m_CharDDifficulty->PureHardDifficulty();
					}

					// Else, check if total movement time equals total time - 4 or - 5
					else if (Character->GetTotalMovementTime() == (m_intSeconds - 4) || Character->GetTotalMovementTime() == (m_intSeconds - 5))
					{
						print("Movement = total - 4 or - 5");

						// Make difficulty medium by calling the Medium Difficulty function within the difficulty class
						Character->m_CharDDifficulty->MediumDifficulty();
					}

					// Otherwise, set to hard mode
					else
					{
						// If Hard_01 or Hard_02 difficulty, set difficulty to Hard_02
						// Otherwise, difficulty will be set to Hard_01 regardless of current difficulty
						Character->m_CharDDifficulty->PureHardDifficulty();
					}
				}

				// Setup the difficulty within the level
				DifficultyFinializedSetup(false, false, false, true);

				// Destroy the trigger box
				OverlappedActor->Destroy();
			}
		}
	}

	else
	{
		print("No level");
	}
}

void ADDATriggerBox::OnOverLapEnd(AActor * OverlappedActor, AActor * OtherActor)
{
	// Check if the actor exiting the trigger box is the same as the FString variable holding the character name
	if (OtherActor && OtherActor != this && OtherActor->GetName() == m_playerCharacterName)
	{
		printf("Actor Left = %s", *OverlappedActor->GetName());
		printf("Actor Overlapped = %s", *OtherActor->GetName());
	}
}