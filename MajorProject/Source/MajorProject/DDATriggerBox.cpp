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
	m_playerCharName = Character->PlayerCharacterName;
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

			// COULD CHANGE INTO AN ENUM
			// Set boolean for section01 in the character class to true and the other section booleans to false
			Character->m_section01 = true;
			Character->m_section02 = false;
			Character->m_section03 = false;
			Character->m_section04 = false;
			Character->m_section05 = false;

			// Check if easy difficulty
			if (Character->m_CharDifficulty->GetDifficulty() == EDifficulty::EASY_01)
			{
				print("DIFFICULTY - EASY");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S1EasyModeSetup.Num(); i++)
				{
					m_L1S1EasyModeSetup[i]->Destroy();
				}
			}

			// Check if medium difficulty
			else if (Character->m_CharDifficulty->GetDifficulty() == EDifficulty::MEDIUM_01)
			{
				print("DIFFICULTY - MEDIUM");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S1MediumModeSetup.Num(); i++)
				{
					m_L1S1MediumModeSetup[i]->Destroy();
				}
			}

			// Check if hard difficuly
			else if (Character->m_CharDifficulty->GetDifficulty() == EDifficulty::HARD_01)
			{
				print("DIFFICULTY - HARD");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S1HardModeSetup.Num(); i++)
				{
					m_L1S1HardModeSetup[i]->Destroy();
				}
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
			if (Character->m_CharDifficulty->GetDifficulty() == EDifficulty::EASY_01)
			{
				print("DIFFICULTY - EASY_01");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S2EasyMode1Setup.Num(); i++)
				{
					m_L1S2EasyMode1Setup[i]->Destroy();
				}
			}

			// Check if Easy 2 difficulty
			else if (Character->m_CharDifficulty->GetDifficulty() == EDifficulty::EASY_02)
			{
				print("DIFFICULTY - EASY_02");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S2EasyMode2Setup.Num(); i++)
				{
					m_L1S2EasyMode2Setup[i]->Destroy();
				}
			}

			// Check if Medium 1 difficulty
			if (Character->m_CharDifficulty->GetDifficulty() == EDifficulty::MEDIUM_01)
			{
				print("DIFFICULTY - MEDIUM_01");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S2MediumMode1Setup.Num(); i++)
				{
					m_L1S2MediumMode1Setup[i]->Destroy();
				}
			}

			// Check if Medium 2 difficulty
			else if (Character->m_CharDifficulty->GetDifficulty() == EDifficulty::MEDIUM_02)
			{
				print("DIFFICULTY - MEDIUM_02");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S2MediumMode2Setup.Num(); i++)
				{
					m_L1S2MediumMode2Setup[i]->Destroy();
				}
			}

			// Check if Hard 1 difficulty
			else if (Character->m_CharDifficulty->GetDifficulty() == EDifficulty::HARD_01)
			{
				print("DIFFICULTY - HARD_01");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S2HardMode1Setup.Num(); i++)
				{
					m_L1S2HardMode1Setup[i]->Destroy();
				}
			}

			// Check if Hard 2 difficulty
			else if (Character->m_CharDifficulty->GetDifficulty() == EDifficulty::HARD_02)
			{
				print("DIFFICULTY - HARD_02");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S2HardMode2Setup.Num(); i++)
				{
					m_L1S2HardMode2Setup[i]->Destroy();
				}
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
			if (Character->m_CharDifficulty->GetDifficulty() == EDifficulty::EASY_01)
			{
				print("DIFFICULTY - EASY_01");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S3EasyMode1Setup.Num(); i++)
				{
					m_L1S3EasyMode1Setup[i]->Destroy();
				}
			}

			// Check if Easy 2 difficulty
			else if (Character->m_CharDifficulty->GetDifficulty() == EDifficulty::EASY_02)
			{
				print("DIFFICULTY - EASY_02");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S3EasyMode2Setup.Num(); i++)
				{
					m_L1S3EasyMode2Setup[i]->Destroy();
				}
			}

			// Check if Medium 1 difficulty
			else if (Character->m_CharDifficulty->GetDifficulty() == EDifficulty::MEDIUM_01)
			{
				print("DIFFICULTY - MEDIUM_01");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S3MediumMode1Setup.Num(); i++)
				{
					m_L1S3MediumMode1Setup[i]->Destroy();
				}
			}

			// Check if Medium 2 difficulty
			else if (Character->m_CharDifficulty->GetDifficulty() == EDifficulty::MEDIUM_02)
			{
				print("DIFFICULTY - MEDIUM_02");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S3MediumMode2Setup.Num(); i++)
				{
					m_L1S3MediumMode2Setup[i]->Destroy();
				}
			}

			// Check if Hard 1 difficulty
			else if (Character->m_CharDifficulty->GetDifficulty() == EDifficulty::HARD_01)
			{
				print("DIFFICULTY - HARD_01");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S3HardMode1Setup.Num(); i++)
				{
					m_L1S3HardMode1Setup[i]->Destroy();
				}
			}

			// Check if Hard 2 difficulty
			else if (Character->m_CharDifficulty->GetDifficulty() == EDifficulty::HARD_02)
			{
				print("DIFFICULTY - HARD_02");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S3HardMode2Setup.Num(); i++)
				{
					m_L1S3HardMode2Setup[i]->Destroy();
				}
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
			if (Character->m_CharDifficulty->GetDifficulty() == EDifficulty::EASY_01)
			{
				print("DIFFICULTY - EASY_01");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S4EasyMode1Setup.Num(); i++)
				{
					m_L1S4EasyMode1Setup[i]->Destroy();
				}
			}

			// Check if Easy 2 difficulty
			else if (Character->m_CharDifficulty->GetDifficulty() == EDifficulty::EASY_02)
			{
				print("DIFFICULTY - EASY_02");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S4EasyMode2Setup.Num(); i++)
				{
					m_L1S4EasyMode2Setup[i]->Destroy();
				}
			}

			// Check if Medium 1 difficulty
			else if (Character->m_CharDifficulty->GetDifficulty() == EDifficulty::MEDIUM_01)
			{
				print("DIFFICULTY - MEDIUM_01");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S4MediumMode1Setup.Num(); i++)
				{
					m_L1S4MediumMode1Setup[i]->Destroy();
				}
			}

			// Check if Medium 2 difficulty
			else if (Character->m_CharDifficulty->GetDifficulty() == EDifficulty::MEDIUM_02)
			{
				print("DIFFICULTY - MEDIUM_02");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S4MediumMode2Setup.Num(); i++)
				{
					m_L1S4MediumMode2Setup[i]->Destroy();
				}
			}

			// Check if Hard 1 difficulty
			else if (Character->m_CharDifficulty->GetDifficulty() == EDifficulty::HARD_01)
			{
				print("DIFFICULTY - HARD_01");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S4HardMode1Setup.Num(); i++)
				{
					m_L1S4HardMode1Setup[i]->Destroy();
				}
			}

			// Check if Hard 2 difficulty
			else if (Character->m_CharDifficulty->GetDifficulty() == EDifficulty::HARD_02)
			{
				print("DIFFICULTY - HARD_02");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S4HardMode2Setup.Num(); i++)
				{
					m_L1S4HardMode2Setup[i]->Destroy();
				}
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
			if (Character->m_CharDifficulty->GetDifficulty() == EDifficulty::EASY_01)
			{
				print("DIFFICULTY - EASY_01");

				// Set the difficulty within the Game Instance Class, for initial difficulty within Level_02
				GameInstance->m_finalDifficulty = EFinalDifficulty::EASY_01;
			}

			// Check if Medium 1 difficulty
			else if (Character->m_CharDifficulty->GetDifficulty() == EDifficulty::MEDIUM_01)
			{
				print("DIFFICULTY - MEDIUM_01");

				// Set the difficulty within the Game Instance Class, for initial difficulty within Level_02
				GameInstance->m_finalDifficulty = EFinalDifficulty::MEDIUM_01;
			}

			// Check if Hard 1 difficulty
			else if (Character->m_CharDifficulty->GetDifficulty() == EDifficulty::HARD_01)
			{
				print("DIFFICULTY - HARD_01");

				// Set the difficulty within the Game Instance Class, for initial difficulty within Level_02
				GameInstance->m_finalDifficulty = EFinalDifficulty::HARD_01;
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
			if (Character->m_CharDifficulty->GetDifficulty() == EDifficulty::EASY_01)
			{
				print("DIFFICULTY - EASY");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L2S1EasyModeSetup.Num(); i++)
				{
					m_L2S1EasyModeSetup[i]->Destroy();
				}
			}

			// Check if medium difficulty
			else if (Character->m_CharDifficulty->GetDifficulty() == EDifficulty::MEDIUM_01)
			{
				print("DIFFICULTY - MEDIUM");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L2S1MediumModeSetup.Num(); i++)
				{
					m_L2S1MediumModeSetup[i]->Destroy();
				}
			}

			// Check if hard difficuly
			else if (Character->m_CharDifficulty->GetDifficulty() == EDifficulty::HARD_01)
			{
				print("DIFFICULTY - HARD");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L2S1HardModeSetup.Num(); i++)
				{
					m_L2S1HardModeSetup[i]->Destroy();
				}
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
			if (Character->m_CharDifficulty->GetDifficulty() == EDifficulty::EASY_01)
			{
				print("DIFFICULTY - EASY_01");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L2S2EasyMode1Setup.Num(); i++)
				{
					m_L2S2EasyMode1Setup[i]->Destroy();
				}
			}

			// Check if Easy 2 difficulty
			else if (Character->m_CharDifficulty->GetDifficulty() == EDifficulty::EASY_02)
			{
				print("DIFFICULTY - EASY_02");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L2S2EasyMode2Setup.Num(); i++)
				{
					m_L2S2EasyMode2Setup[i]->Destroy();
				}
			}

			// Check if Medium 1 difficulty
			else if (Character->m_CharDifficulty->GetDifficulty() == EDifficulty::MEDIUM_01)
			{
				print("DIFFICULTY - MEDIUM_01");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L2S2MediumMode1Setup.Num(); i++)
				{
					m_L2S2MediumMode1Setup[i]->Destroy();
				}
			}

			// Check if Medium 2 difficulty
			else if (Character->m_CharDifficulty->GetDifficulty() == EDifficulty::MEDIUM_02)
			{
				print("DIFFICULTY - MEDIUM_02");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L2S2MediumMode2Setup.Num(); i++)
				{
					m_L2S2MediumMode2Setup[i]->Destroy();
				}
			}

			// Check if Hard 1 difficulty
			else if (Character->m_CharDifficulty->GetDifficulty() == EDifficulty::HARD_01)
			{
				print("DIFFICULTY - HARD_01");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L2S2HardMode1Setup.Num(); i++)
				{
					m_L2S2HardMode1Setup[i]->Destroy();
				}
			}

			// Check if Hard 2 difficulty
			else if (Character->m_CharDifficulty->GetDifficulty() == EDifficulty::HARD_02)
			{
				print("DIFFICULTY - HARD_02");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L2S2HardMode2Setup.Num(); i++)
				{
					m_L2S2HardMode2Setup[i]->Destroy();
				}
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
			if (Character->m_CharDifficulty->GetDifficulty() == EDifficulty::EASY_01)
			{
				print("DIFFICULTY - EASY_01");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L2S3EasyMode1Setup.Num(); i++)
				{
					m_L2S3EasyMode1Setup[i]->Destroy();
				}
			}

			// Check if Easy 2 difficulty
			else if (Character->m_CharDifficulty->GetDifficulty() == EDifficulty::EASY_02)
			{
				print("DIFFICULTY - EASY_02");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L2S3EasyMode2Setup.Num(); i++)
				{
					m_L2S3EasyMode2Setup[i]->Destroy();
				}
			}

			// Check if Medium 1 difficulty
			else if (Character->m_CharDifficulty->GetDifficulty() == EDifficulty::MEDIUM_01)
			{
				print("DIFFICULTY - MEDIUM_01");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L2S3MediumMode1Setup.Num(); i++)
				{
					m_L2S3MediumMode1Setup[i]->Destroy();
				}
			}

			// Check if Medium 2 difficulty
			else if (Character->m_CharDifficulty->GetDifficulty() == EDifficulty::MEDIUM_02)
			{
				print("DIFFICULTY - MEDIUM_02");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L2S3MediumMode2Setup.Num(); i++)
				{
					m_L2S3MediumMode2Setup[i]->Destroy();
				}
			}

			// Check if Hard 1 difficulty
			else if (Character->m_CharDifficulty->GetDifficulty() == EDifficulty::HARD_01)
			{
				print("DIFFICULTY - HARD_01");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L2S3HardMode1Setup.Num(); i++)
				{
					m_L2S3HardMode1Setup[i]->Destroy();
				}
			}

			// Check if Hard 2 difficulty
			else if (Character->m_CharDifficulty->GetDifficulty() == EDifficulty::HARD_02)
			{
				print("DIFFICULTY - HARD_02");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L2S3HardMode2Setup.Num(); i++)
				{
					m_L2S3HardMode2Setup[i]->Destroy();
				}
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
			if (Character->m_CharDifficulty->GetDifficulty() == EDifficulty::EASY_01)
			{
				print("DIFFICULTY - EASY_01");

				// Set difficulty within the character class
				Character->SetDifficulty(ESetDifficulty::EASY_01);

				// Save difficulty details to text file
				Character->m_CharDifficulty->SaveDataToTextFile(FString("Level_02"), FString("Section 04"),
								   FString("EASY_01"), m_totalTime, m_movementTime,
								   m_inLightTime, FString("04"));
			}

			// Check if Easy 2 difficulty
			else if (Character->m_CharDifficulty->GetDifficulty() == EDifficulty::EASY_02)
			{
				print("DIFFICULTY - EASY_02");

				// Set difficulty within the character class
				Character->SetDifficulty(ESetDifficulty::EASY_02);

				// Save difficulty details to text file
				Character->m_CharDifficulty->SaveDataToTextFile(FString("Level_02"), FString("Section 04"),
								   FString("EASY_02"), m_totalTime, m_movementTime,
								   m_inLightTime, FString("04"));
			}

			// Check if Medium 1 difficulty
			else if (Character->m_CharDifficulty->GetDifficulty() == EDifficulty::MEDIUM_01)
			{
				print("DIFFICULTY - MEDIUM_01");

				// Set difficulty within the character class
				Character->SetDifficulty(ESetDifficulty::MEDIUM_01);

				// Save difficulty details to text file
				Character->m_CharDifficulty->SaveDataToTextFile(FString("Level_02"), FString("Section 04"),
								   FString("MEDIUM_01"), m_totalTime, m_movementTime,
								   m_inLightTime, FString("04"));
			}

			// Check if Medium 2 difficulty
			else if (Character->m_CharDifficulty->GetDifficulty() == EDifficulty::MEDIUM_02)
			{
				print("DIFFICULTY - MEDIUM_02");

				// Set difficulty within the character class
				Character->SetDifficulty(ESetDifficulty::MEDIUM_02);

				// Save difficulty details to text file
				Character->m_CharDifficulty->SaveDataToTextFile(FString("Level_02"), FString("Section 04"),
								   FString("MEDIUM_02"), m_totalTime, m_movementTime,
								   m_inLightTime, FString("04"));
			}

			// Check if Hard 1 difficulty
			else if (Character->m_CharDifficulty->GetDifficulty() == EDifficulty::HARD_01)
			{
				print("DIFFICULTY - HARD_01");

				// Set difficulty within the character class
				Character->SetDifficulty(ESetDifficulty::HARD_01);

				// Save difficulty details to text file
				Character->m_CharDifficulty->SaveDataToTextFile(FString("Level_02"), FString("Section 04"),
								   FString("HARD_01"), m_totalTime, m_movementTime,
								   m_inLightTime, FString("04"));
			}

			// Check if Hard 2 difficulty
			else if (Character->m_CharDifficulty->GetDifficulty() == EDifficulty::HARD_02)
			{
				print("DIFFICULTY - HARD_02");

				// Set difficulty within the character class
				Character->SetDifficulty(ESetDifficulty::HARD_02);

				// Save difficulty details to text file
				Character->m_CharDifficulty->SaveDataToTextFile(FString("Level_02"), FString("Section 04"),
								   FString("HARD_02"), m_totalTime, m_movementTime,
								   m_inLightTime, FString("04"));
			}
		}
	}
}

void ADDATriggerBox::DifficultyShift(bool IsFirstTB, bool IsLastTB)
{
	// Get the current seconds spent in level
	m_intSeconds = Gamemode->GetSecondsInt();

	// Set the total time variable to equal the current total time
	m_totalTime = FString::FromInt(m_intSeconds);

	// Set the total movement time variable to equal the current total movement time
	m_movementTime = FString::FromInt(Character->GetTotalMovementTime());

	// Set the total in light time variable to equal the current total in light time
	m_inLightTime = FString::FromInt(Character->GetTotalInLightTime());

	// If the trigger box is a first or last within the level
	if (IsFirstTB || IsLastTB)
	{
		// Check if seconds is greater than or equal to 5
		if (m_intSeconds >= m_timeChk)
		{
			// Check if total movement time is greater than 5
			if (Character->GetTotalMovementTime() > m_mvmntChk01)
			{
				if (IsLastTB)
				{
					// Check if total time in sentry light is between 0-3
					if (Character->GetTotalInLightTime() <= m_inLightChk01)
					{
						// Set final difficulty to Hard by using the Set Exact Difficulty function within the difficulty class
						Character->m_CharDifficulty->SetExactDifficulty(false, false, true, m_levelName,
													m_sectionNum, m_totalTime, m_movementTime, m_inLightTime);
					}

					// Check if total time in sentry light is between 4-7
					else if (Character->GetTotalInLightTime() >= m_inLightChk02 && Character->GetTotalInLightTime() <= m_inLightChk03)
					{
						// Set final difficulty to Medium by using the Set Exact Difficulty function within the difficulty class
						Character->m_CharDifficulty->SetExactDifficulty(false, true, false, m_levelName,
													m_sectionNum, m_totalTime, m_movementTime, m_inLightTime);
					}

					// Check if total time in sentry light is 8 or more
					else if (Character->GetTotalInLightTime() >= m_inLightChk04)
					{
						// Set final difficulty to Easy by using the Set Exact Difficulty function within the difficulty class
						Character->m_CharDifficulty->SetExactDifficulty(true, false, false, m_levelName,
													m_sectionNum, m_totalTime, m_movementTime, m_inLightTime);
					}
				}

				else
				{
					// Set difficulty to Easy by using the Set Exact Difficulty function within the difficulty class
					Character->m_CharDifficulty->SetExactDifficulty(true, false, false, m_levelName,
												m_sectionNum, m_totalTime, m_movementTime, m_inLightTime);
				}
			}

			// Check if total movement time is equal to 3, 4, or 5
			else if (Character->GetTotalMovementTime() >= m_mvmntChk02
				  && Character->GetTotalMovementTime() <= m_mvmntChk03)
			{
				if (IsLastTB)
				{
					// If total in light equals 7 or less
					if (Character->GetTotalInLightTime() <= m_inLightChk03)
					{
						// Set final difficulty to Medium by using the Final Difficulty function within the difficulty class
						Character->m_CharDifficulty->SetExactDifficulty(false, true, false, m_levelName,
													m_sectionNum, m_totalTime, m_movementTime, m_inLightTime);
					}

					// Check if total in light time equals greater than or equal to 8
					else if (Character->GetTotalInLightTime() >= m_inLightChk04)
					{
						// Set final difficulty to Hard by using the Final Difficulty function within the difficulty class
						Character->m_CharDifficulty->SetExactDifficulty(false, false, true, m_levelName,
													m_sectionNum, m_totalTime, m_movementTime, m_inLightTime);
					}
				}
				
				else
				{
					// Set starting difficulty to Medium by using the Set Exact Difficulty function within the difficulty class
					Character->m_CharDifficulty->SetExactDifficulty(false, true, false, m_levelName,
												m_sectionNum, m_totalTime, m_movementTime, m_inLightTime);
				}
			}

			// Check if total movement time is equal to 0, 1, or 2
			else if (Character->GetTotalMovementTime() <= m_mvmntChk04)
			{
				// Set starting difficulty to Hard by using the Set Exact Difficulty function within the difficulty class
				Character->m_CharDifficulty->SetExactDifficulty(false, false, true, m_levelName,
											m_sectionNum, m_totalTime, m_movementTime, m_inLightTime);
			}
		}

		// If seconds equals less than 5
		else
		{
			// Check if total movement time is equal to the total time spent in the level
			if (Character->GetTotalMovementTime() == m_mvmntChk05)
			{
				// Set starting difficulty to Hard by using the Set Exact Difficulty function within the difficulty class
				Character->m_CharDifficulty->SetExactDifficulty(false, false, true, m_levelName,
											m_sectionNum, m_totalTime, m_movementTime, m_inLightTime);
			}

			else if (IsLastTB)
			{
				// Else, check if total movement time equals total time - 5 or - 6
				if (Character->GetTotalMovementTime() == (m_mvmntChk05 - 1) || Character->GetTotalMovementTime() == (m_mvmntChk05 - 2))
				{
					// Set final difficulty to Hard by using the Final Difficulty function within the difficulty class
					Character->m_CharDifficulty->SetExactDifficulty(false, true, false, m_levelName,
												m_sectionNum, m_totalTime, m_movementTime, m_inLightTime);
				}

				// Otherwise, set to hard mode
				else
				{
					// Set starting difficulty to Hard by using the Set Exact Difficulty function within the difficulty class
					Character->m_CharDifficulty->SetExactDifficulty(false, false, true, m_levelName,
												m_sectionNum, m_totalTime, m_movementTime, m_inLightTime);
				}
			}

			// Check if total movement time is equal to the total time - 1
			else if (Character->GetTotalMovementTime() == (m_mvmntChk05 - 1))
			{
				// Set starting difficulty to Medium by using the Set Exact Difficulty function within the difficulty class
				Character->m_CharDifficulty->SetExactDifficulty(false, true, false, m_levelName,
											m_sectionNum, m_totalTime, m_movementTime, m_inLightTime);
			}

			// Otherwise, set to hard mode
			else
			{
				// Set starting difficulty to Hard by using the Set Exact Difficulty function within the difficulty class
				Character->m_CharDifficulty->SetExactDifficulty(false, false, true, m_levelName,
											m_sectionNum, m_totalTime, m_movementTime, m_inLightTime);
			}
		}
	}

	// Else, if the trigger box is not either a first or last trigger box within the level
	else
	{
		// Check if seconds is greater than or equal to 15
		if (m_intSeconds >= m_timeChk)
		{
			// Check if total movement time is greater than 13
			if (Character->GetTotalMovementTime() >= m_mvmntChk01)
			{
				// Check if total time in sentry light is equal to 0
				if (Character->GetTotalInLightTime() == m_inLightChk01)
				{
					// Make difficulty harder by calling the Hard Difficulty function within the difficulty class
					Character->m_CharDifficulty->HardDifficulty(m_levelName, m_sectionNum, m_totalTime, m_movementTime, m_inLightTime);
				}

				// Check if total time in sentry light is 1, 2 or 3
				else if (Character->GetTotalInLightTime() >= m_inLightChk02 && Character->GetTotalInLightTime() <= m_inLightChk03)
				{
					// Make difficulty medium by calling the Medium Difficulty function within the difficulty class
					Character->m_CharDifficulty->MediumDifficulty(m_levelName, m_sectionNum, m_totalTime, m_movementTime, m_inLightTime);
				}

				// Check if total time in sentry light is 4 or more
				else if (Character->GetTotalInLightTime() >= m_inLightChk04)
				{
					// Make difficulty easier by calling the Easy Difficulty function within the difficulty class
					Character->m_CharDifficulty->EasyDifficulty(m_levelName, m_sectionNum, m_totalTime, m_movementTime, m_inLightTime);
				}
			}

			// Check if total movement time is equal to 9, 10, 11, or 12
			else if (Character->GetTotalMovementTime() >= m_mvmntChk02 && Character->GetTotalMovementTime() <= m_mvmntChk03)
			{
				// If total in light equals 2 or less
				if (Character->GetTotalInLightTime() <= m_inLightChk03)
				{
					// Make difficulty medium by calling the Medium Difficulty function within the difficulty class
					Character->m_CharDifficulty->MediumDifficulty(m_levelName, m_sectionNum, m_totalTime, m_movementTime, m_inLightTime);
				}

				// Check if total in light time equals greater than or equal to 3
				else if (Character->GetTotalInLightTime() >= m_inLightChk04)
				{
					// Make difficulty harder by calling the Hard Difficulty function within the difficulty class
					Character->m_CharDifficulty->HardDifficulty(m_levelName, m_sectionNum, m_totalTime, m_movementTime, m_inLightTime);
				}
			}

			// Check if total movement time is equal to or less than 8
			else if (Character->GetTotalMovementTime() <= m_mvmntChk04)
			{
				// Make difficulty harder by calling the Hard Difficulty function within the difficulty class
				Character->m_CharDifficulty->HardDifficulty(m_levelName, m_sectionNum, m_totalTime, m_movementTime, m_inLightTime);
			}
		}

		// If seconds equals less than 15
		else
		{
			// Check if total movement time is greater than or equal to the total time - 1
			if (Character->GetTotalMovementTime() >= m_mvmntChk05)
			{
				print("movement >= total - 1");

				// If Hard_01 or Hard_02 difficulty, set difficulty to Hard_02
				// Otherwise, difficulty will be set to Hard_01 regardless of current difficulty
				Character->m_CharDifficulty->PureHardDifficulty(m_levelName, m_sectionNum, m_totalTime, m_movementTime, m_inLightTime);
			}

			// Else, check if total movement time equals total time - 2 or - 3
			else if (Character->GetTotalMovementTime() == (m_mvmntChk05 - 1) || Character->GetTotalMovementTime() == (m_mvmntChk05 - 2))
			{
				// Make difficulty medium by calling the Medium Difficulty function within the difficulty class
				Character->m_CharDifficulty->MediumDifficulty(m_levelName, m_sectionNum, m_totalTime, m_movementTime, m_inLightTime);
			}

			// Otherwise, set to hard mode
			else
			{
				// If Hard_01 or Hard_02 difficulty, set difficulty to Hard_02
				// Otherwise, difficulty will be set to Hard_01 regardless of current difficulty
				Character->m_CharDifficulty->PureHardDifficulty(m_levelName, m_sectionNum, m_totalTime, m_movementTime, m_inLightTime);
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

	// Check if the actor overlapping the trigger box is the same as the FString variable holding the character name
	if (OtherActor && OtherActor != this && OtherActor->GetName() == m_playerCharName)
	{
		//############################################################################################################################
												// LEVEL 01 TRIGGER BOXES
		//############################################################################################################################
		if (m_currentLevel == "Level_01")
		{
			// Set level name FString (for saving data to text)
			m_levelName = "Level_01";

			//#####################################################################################################
										// SECTION 1 TRIGGER BOX
			//#####################################################################################################

			// Check if the trigger box is the first one
			if (OverlappedActor->GetName() == "DDATriggerBox_01")
			{
				// Get the current seconds spent in level
				m_intSeconds = Gamemode->GetSecondsInt();

				// Set section number FString (for saving data to text)
				m_sectionNum = "01";

				// Set data values to check for difficulty changes
				m_timeChk = 5;						// Check current time against 5
				m_mvmntChk01 = 5;					// First Movement Check against 5
				m_mvmntChk02 = 3;					// Second Movement Check against 3
				m_mvmntChk03 = 4;					// Third Movement Check against 4
				m_mvmntChk04 = 2;					// Fourth Movement Check against 2
				m_mvmntChk05 = m_intSeconds;		// Fifth Movement Check against current time

				// Check the data for changing the difficulty
				DifficultyShift(true);		

				// Update character class difficulty here
				Character->Update();

				// Setup the difficulty within the level
				DifficultyFinializedSetup(true);

				// Destroy the trigger box
				OverlappedActor->Destroy();
			}

			//#####################################################################################################
										// SECTION 2 TRIGGER BOX
			//#####################################################################################################

			// Check if the trigger box is the second one
			else if (OverlappedActor->GetName() == "DDATriggerBox_02")
			{
				// Get the current seconds spent in level
				m_intSeconds = Gamemode->GetSecondsInt();

				// Set section number (for saving data to text)
				m_sectionNum = "02";

				// Set data values to check for difficulty changes
				m_timeChk = 15;						// Check current time against 15
				m_mvmntChk01 = 13;					// First Movement Check against 13
				m_mvmntChk02 = 9;					// Second Movement Check against 9
				m_mvmntChk03 = 12;					// Third Movement Check against 12
				m_mvmntChk04 = 8;					// Fourth Movement Check against 8
				m_mvmntChk05 = (m_intSeconds - 1);	// Fifth Movement Check against (current time - 1)
				m_inLightChk01 = 0;					// First In Light Check against 0
				m_inLightChk02 = 1;					// Second In Light Check against 1
				m_inLightChk03 = 3;					// Third In Light Check against 3
				m_inLightChk04 = 4;					// Fourth In Light Check against 4

				// Check the data for changing the difficulty
				DifficultyShift();

				// Update character class difficulty here
				Character->Update();

				// Setup the difficulty within the level
				DifficultyFinializedSetup(false, true);

				// Destroy the trigger box
				OverlappedActor->Destroy();
			}

			//#####################################################################################################
										// SECTION 3 TRIGGER BOX
			//#####################################################################################################

			// Check if the trigger box is the third one
			else if (OverlappedActor->GetName() == "DDATriggerBox_03")
			{
				// Get the current seconds spent in level
				m_intSeconds = Gamemode->GetSecondsInt();

				// Set section number FString (for saving data to text)
				m_sectionNum = "03";

				// Set data values to check for difficulty changes
				m_timeChk = 25;						// Check current time against 25
				m_mvmntChk01 = 20;					// First Movement Check against 20
				m_mvmntChk02 = 17;					// Second Movement Check against 17
				m_mvmntChk03 = 19;					// Third Movement Check against 19
				m_mvmntChk04 = 16;					// Fourth Movement Check against 16
				m_mvmntChk05 = (m_intSeconds - 2);	// Fifth Movement Check against (current time - 2)
				m_inLightChk01 = 1;					// First In Light Check against 1
				m_inLightChk02 = 2;					// Second In Light Check against 2
				m_inLightChk03 = 5;					// Third In Light Check against 5
				m_inLightChk04 = 6;					// Fourth In Light Check against 6

				// Shift the difficulty based on data checks
				DifficultyShift();

				// Update character class difficulty here
				Character->Update();

				// Setup the difficulty within the level
				DifficultyFinializedSetup(false, false, true);

				// Destroy the trigger box
				OverlappedActor->Destroy();
			}

			//#####################################################################################################
										// SECTION 4 TRIGGER BOX
			//#####################################################################################################

			// Check if the trigger box is the fourth one
			else if (OverlappedActor->GetName() == "DDATriggerBox_04")
			{
				// Get the current seconds spent in level
				m_intSeconds = Gamemode->GetSecondsInt();

				// Set section number FString (for saving data to text)
				m_sectionNum = "04";

				// Set data values to check for difficulty changes
				m_timeChk = 45;						// Check current time against 45
				m_mvmntChk01 = 38;					// First Movement Check against 38
				m_mvmntChk02 = 36;					// Second Movement Check against 36
				m_mvmntChk03 = 37;					// Third Movement Check against 37
				m_mvmntChk04 = 35;					// Fourth Movement Check against 35
				m_mvmntChk05 = (m_intSeconds - 3);	// Fifth Movement Check against (current time - 3)
				m_inLightChk01 = 2;					// First In Light Check against 2
				m_inLightChk02 = 3;					// Second In Light Check against 3
				m_inLightChk03 = 6;					// Third In Light Check against 6
				m_inLightChk04 = 7;					// Fourth In Light Check against 7

				// Shift the difficulty based on data checks
				DifficultyShift();

				// Update character class difficulty here
				Character->Update();

				// Setup the difficulty within the level
				DifficultyFinializedSetup(false, false, false, true);

				// Destroy the trigger box
				OverlappedActor->Destroy();
			}

			//#####################################################################################################
										// SECTION 5 TRIGGER BOX
			//#####################################################################################################

			// Check if the trigger box is the fifth and last one for level 1
			else if (OverlappedActor->GetName() == "DDATriggerBox_05")
			{
				// Get the current seconds spent in level
				m_intSeconds = Gamemode->GetSecondsInt();
				
				// Set section number FString (for saving data to text)
				m_sectionNum = "05";

				// Set data values to check for difficulty changes
				m_timeChk = 50;						// Check current time against 50
				m_mvmntChk01 = 43;					// First Movement Check against 43
				m_mvmntChk02 = 40;					// Second Movement Check against 40
				m_mvmntChk03 = 42;					// Third Movement Check against 42
				m_mvmntChk04 = 39;					// Fourth Movement Check against 39
				m_mvmntChk05 = (m_intSeconds - 4);	// Fifth Movement Check against (current time - 4)
				m_inLightChk01 = 3;					// First In Light Check against 3
				m_inLightChk02 = 4;					// Second In Light Check against 4
				m_inLightChk03 = 7;					// Third In Light Check against 7
				m_inLightChk04 = 8;					// Fourth In Light Check against 8

				// Shift the difficulty based on data checks
				DifficultyShift(false, true);

				// Update character class difficulty here
				Character->Update();

				// Setup the difficulty within the level
				DifficultyFinializedSetup(false, false, false, false, true);

				// Destroy the trigger box
				OverlappedActor->Destroy();
			}
		}

		//############################################################################################################################
													// LEVEL 02 TRIGGER BOXES
		//############################################################################################################################

		else if (m_currentLevel == "Level_02")
		{
			// Set level name FString (for saving data to text)
			m_levelName = "Level_02";

			//#####################################################################################################
										// SECTION 1 TRIGGER BOX
			//#####################################################################################################

			// Check if the trigger box is the first one
			if (OverlappedActor->GetName() == "DDATriggerBox_01")
			{
				// Get the current seconds spent in level
				m_intSeconds = Gamemode->GetSecondsInt();

				// Set the total time variable to equal the current total time
				m_totalTime = FString::FromInt(m_intSeconds);

				// Set the total movement time variable to equal the current total movement time
				m_movementTime = FString::FromInt(Character->GetTotalMovementTime());

				// Set the total in light time variable to equal the current total in light time
				m_inLightTime = FString::FromInt(Character->GetTotalInLightTime());

				// Set section number FString (for saving data to text)
				m_sectionNum = "01";

				// If Easy_01 at the end of Level_01, set difficulty to Easy_01
				if (GameInstance->GetDifficulty() == EFinalDifficulty::EASY_01)
				{
					// Set starting difficulty to Easy by using the Starting Difficulty function within the difficulty class
					Character->m_CharDifficulty->SetExactDifficulty(true, false, false, m_levelName,
												m_sectionNum, m_totalTime, m_movementTime, m_inLightTime);
				}

				// If Medium_01 at the end of Level_01, set difficulty to Medium_01
				else if (GameInstance->GetDifficulty() == EFinalDifficulty::MEDIUM_01)
				{
					// Set starting difficulty to Medium by using the Starting Difficulty function within the difficulty class
					Character->m_CharDifficulty->SetExactDifficulty(false, true, false, m_levelName,
												m_sectionNum, m_totalTime, m_movementTime, m_inLightTime);
				}

				// If Hard_01 at the end of Level_01, set difficulty to Hard_01
				else if (GameInstance->GetDifficulty() == EFinalDifficulty::HARD_01)
				{
					// Set starting difficulty to Hard by using the Starting Difficulty function within the difficulty class
					Character->m_CharDifficulty->SetExactDifficulty(false, false, true, m_levelName,
												m_sectionNum, m_totalTime, m_movementTime, m_inLightTime);
				}

				// Else, print ERROR message
				else
				{
					print("ERROR GETTING LAST SET DIFFICULTY");
				}

				// Update character class difficulty here
				Character->Update();

				// Setup the difficulty within the level
				DifficultyFinializedSetup(true);

				// Destroy the trigger box
				OverlappedActor->Destroy();
			}

			//#####################################################################################################
										// SECTION 2 TRIGGER BOX
			//#####################################################################################################

			// Check if the trigger box is the first one
			if (OverlappedActor->GetName() == "DDATriggerBox_02")
			{
				// Get the current seconds spent in level
				m_intSeconds = Gamemode->GetSecondsInt();

				// Set section number FString (for saving data to text)
				m_sectionNum = "02";

				// Set data values to check for difficulty changes
				m_timeChk = 17;						// Check current time against 17
				m_mvmntChk01 = 16;					// First Movement Check against 16
				m_mvmntChk02 = 14;					// Second Movement Check against 14
				m_mvmntChk03 = 15;					// Third Movement Check against 15
				m_mvmntChk04 = 13;					// Fourth Movement Check against 13
				m_mvmntChk05 = (m_intSeconds - 1);	// Fifth Movement Check against (current time - 1)
				m_inLightChk01 = 0;					// First In Light Check against 0
				m_inLightChk02 = 1;					// Second In Light Check against 1
				m_inLightChk03 = 3;					// Third In Light Check against 3
				m_inLightChk04 = 4;					// Fourth In Light Check against 4

				// Shift the difficulty based on data checks
				DifficultyShift();

				// Update character class difficulty here
				Character->Update();

				// Setup the difficulty within the level
				DifficultyFinializedSetup(false, true);

				// Destroy the trigger box
				OverlappedActor->Destroy();
			}

			//#####################################################################################################
										// SECTION 3 TRIGGER BOX
			//#####################################################################################################

			// Check if the trigger box is the third one
			if (OverlappedActor->GetName() == "DDATriggerBox_03")
			{
				// Get the current seconds spent in level
				m_intSeconds = Gamemode->GetSecondsInt();

				// Set section number FString (for saving data to text)
				m_sectionNum = "03";

				// Set data values to check for difficulty changes
				m_timeChk = 30;						// Check current time against 30
				m_mvmntChk01 = 28;					// First Movement Check against 28
				m_mvmntChk02 = 26;					// Second Movement Check against 26
				m_mvmntChk03 = 27;					// Third Movement Check against 27
				m_mvmntChk04 = 25;					// Fourth Movement Check against 25
				m_mvmntChk05 = (m_intSeconds - 2);	// Fifth Movement Check against (current time - 2)
				m_inLightChk01 = 1;					// First In Light Check against 1
				m_inLightChk02 = 2;					// Second In Light Check against 2
				m_inLightChk03 = 4;					// Third In Light Check against 4
				m_inLightChk04 = 5;					// Fourth In Light Check against 5

				// Shift the difficulty based on data checks
				DifficultyShift();

				// Update character class difficulty here
				Character->Update();

				// Setup the difficulty within the level
				DifficultyFinializedSetup(false, false, true);

				// Destroy the trigger box
				OverlappedActor->Destroy();
			}

			//#####################################################################################################
										// SECTION 4 TRIGGER BOX (FINAL)
			//#####################################################################################################

			// Check if the trigger box is the fourth and final one
			if (OverlappedActor->GetName() == "DDATriggerBox_04")
			{
				// Get the current seconds spent in level
				m_intSeconds = Gamemode->GetSecondsInt();

				// Set section number FString (for saving data to text)
				m_sectionNum = "04";

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
							Character->m_CharDifficulty->HardDifficulty(m_levelName, m_sectionNum, m_totalTime, m_movementTime, m_inLightTime);
						}

						// Check if total time in sentry light is 3, 4 or 5
						else if (Character->GetTotalInLightTime() >= 3 && Character->GetTotalInLightTime() <= 5)
						{
							// Make difficulty medium by calling the Medium Difficulty function within the difficulty class
							Character->m_CharDifficulty->MediumDifficulty(m_levelName, m_sectionNum, m_totalTime, m_movementTime, m_inLightTime);
						}

						// Check if total time in sentry light is greater than or equal to 6
						else if (Character->GetTotalInLightTime() >= 6)
						{
							// Make difficulty easier by calling the Easy Difficulty function within the difficulty class
							Character->m_CharDifficulty->EasyDifficulty(m_levelName, m_sectionNum, m_totalTime, m_movementTime, m_inLightTime);
						}
					}

					// Check if total movement time is equal to 47, 48 or 49
					else if (Character->GetTotalMovementTime() >= 47 && Character->GetTotalMovementTime() <= 49)
					{
						// If total in light is less than or equal to 4
						if (Character->GetTotalInLightTime() <= 4)
						{
							// Make difficulty medium by calling the Medium Difficulty function within the difficulty class
							Character->m_CharDifficulty->MediumDifficulty(m_levelName, m_sectionNum, m_totalTime, m_movementTime, m_inLightTime);
						}

						// Check if total in light time is greater than or equal to 5
						else if (Character->GetTotalInLightTime() >= 5)
						{
							// Make difficulty harder by calling the Hard Difficulty function within the difficulty class
							Character->m_CharDifficulty->HardDifficulty(m_levelName, m_sectionNum, m_totalTime, m_movementTime, m_inLightTime);
						}
					}

					// Check if total movement time is less than or equal to 46
					else if (Character->GetTotalMovementTime() <= 46)
					{
						// Make difficulty harder by calling the Hard Difficulty function within the difficulty class
						Character->m_CharDifficulty->HardDifficulty(m_levelName, m_sectionNum, m_totalTime, m_movementTime, m_inLightTime);
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
						Character->m_CharDifficulty->PureHardDifficulty(m_levelName, m_sectionNum, m_totalTime, m_movementTime, m_inLightTime);
					}

					// Else, check if total movement time equals total time - 4 or - 5
					else if (Character->GetTotalMovementTime() == (m_intSeconds - 4) || Character->GetTotalMovementTime() == (m_intSeconds - 5))
					{
						print("Movement = total - 4 or - 5");

						// Make difficulty medium by calling the Medium Difficulty function within the difficulty class
						Character->m_CharDifficulty->MediumDifficulty(m_levelName, m_sectionNum, m_totalTime, m_movementTime, m_inLightTime);
					}

					// Otherwise, set to hard mode
					else
					{
						// If Hard_01 or Hard_02 difficulty, set difficulty to Hard_02
						// Otherwise, difficulty will be set to Hard_01 regardless of current difficulty
						Character->m_CharDifficulty->PureHardDifficulty(m_levelName, m_sectionNum, m_totalTime, m_movementTime, m_inLightTime);
					}
				}

				// Shift the difficulty based on data checks
				//DifficultyShift();

				// Update character class difficulty here
				Character->Update();

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
	if (OtherActor && OtherActor != this && OtherActor->GetName() == m_playerCharName)
	{
		printf("Actor Left = %s", *OverlappedActor->GetName());
		printf("Actor Overlapped = %s", *OtherActor->GetName());
	}
}