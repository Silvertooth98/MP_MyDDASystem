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

	DrawDebugBox(GetWorld(), GetActorLocation(), GetComponentsBoundingBox().GetExtent(), FColor::Purple, true, 100, 0, 5);

	// Link gamemode variable to the gamemode class
	Gamemode = (AMajorProjectGameMode*)GetWorld()->GetAuthGameMode();
	// Link character variable to the character class
	Character = Cast<AMajorProjectCharacter>(GetWorld()->GetFirstPlayerController()->GetCharacter());
}

EDifficulty ADDATriggerBox::GetEDifficulty()
{
	// Check if difficulty is set to Easy_01 within the character class
	if (Character->m_isEasy1Difficulty)
	{
		// Set m_difficulty enum variable to Easy_01
		m_difficulty = EDifficulty::EASY_01;
	}
	// Check if difficulty is set to Easy_02 within the character class
	else if (Character->m_isEasy2Difficulty)
	{
		// Set m_difficulty enum variable to Easy_02
		m_difficulty = EDifficulty::EASY_02;
	}

	// Check if difficulty is set to Medium_01 within the character class
	else if (Character->m_isMedium1Difficulty)
	{
		// Set m_difficulty enum variable to Medium_01
		m_difficulty = EDifficulty::MEDIUM_01;
	}
	// Check if difficulty is set to Medium_02 within the character class
	else if (Character->m_isMedium2Difficulty)
	{
		// Set m_difficulty enum variable to Medium_02
		m_difficulty = EDifficulty::MEDIUM_02;
	}

	// Check if difficulty is set to Hard_01 within the character class
	else if (Character->m_isHard1Difficulty)
	{
		// Set m_difficulty enum variable to Hard_01
		m_difficulty = EDifficulty::HARD_01;
	}
	// Check if difficulty is set to Hard_02 within the character class
	else if (Character->m_isHard2Difficulty)
	{
		// Set m_difficulty enum variable to Hard_02
		m_difficulty = EDifficulty::HARD_02;
	}

	// Else, print error message
	else
	{
		print("ERROR - NOT DIFFICULTY SET IN CHAR");
	}

	// Return enum variable for difficulty
	return m_difficulty;
}

void ADDATriggerBox::DifficultyFinializedSetup(bool S1, bool S2, bool S3)
{
//#####################################################################################################
							// SECTION 1 TRIGGER BOX
//#####################################################################################################
	// Check if player is within the first section trigger box
	if (S1)
	{
		print("SECTION 1");

		// Check if easy difficulty
		if (m_difficulty == EDifficulty::EASY_01)
		{
			print("DIFFICULTY - EASY");

			// Step through the array and destroy all the actors
			for (int i = 0; i < m_s1EasyModeSetup.Num(); i++)
			{
				m_s1EasyModeSetup[i]->Destroy();
			}

			Character->m_isEasy1Difficulty = true;
			Character->m_isEasy2Difficulty = false;

			Character->m_isMedium1Difficulty = false;
			Character->m_isMedium2Difficulty = false;

			Character->m_isHard1Difficulty = false;
			Character->m_isHard2Difficulty = false;
		}

		// Check if medium difficulty
		else if (m_difficulty == EDifficulty::MEDIUM_01)
		{
			print("DIFFICULTY - MEDIUM");

			// Step through the array and destroy all the actors
			for (int i = 0; i < m_s1MediumModeSetup.Num(); i++)
			{
				m_s1MediumModeSetup[i]->Destroy();
			}

			Character->m_isEasy1Difficulty = false;
			Character->m_isEasy2Difficulty = false;

			Character->m_isMedium1Difficulty = true;
			Character->m_isMedium2Difficulty = false;

			Character->m_isHard1Difficulty = false;
			Character->m_isHard2Difficulty = false;
		}

		// Check if hard difficuly
		else if (m_difficulty == EDifficulty::HARD_01)
		{
			print("DIFFICULTY - HARD");

			// Step through the array and destroy all the actors
			for (int i = 0; i < m_s1HardModeSetup.Num(); i++)
			{
				m_s1HardModeSetup[i]->Destroy();
			}

			Character->m_isEasy1Difficulty = false;
			Character->m_isEasy2Difficulty = false;

			Character->m_isMedium1Difficulty = false;
			Character->m_isMedium2Difficulty = false;

			Character->m_isHard1Difficulty = true;
			Character->m_isHard2Difficulty = false;
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

		// Check if Easy 1 difficulty
		if (m_difficulty == EDifficulty::EASY_01)
		{
			print("DIFFICULTY - EASY_01");

			// Step through the array and destroy all the actors
			for (int i = 0; i < m_s2EasyModeSetup.Num(); i++)
			{
				m_s2EasyModeSetup[i]->Destroy();
			}

			Character->m_isEasy1Difficulty = true;
			Character->m_isEasy2Difficulty = false;

			Character->m_isMedium1Difficulty = false;
			Character->m_isMedium2Difficulty = false;

			Character->m_isHard1Difficulty = false;
			Character->m_isHard2Difficulty = false;
		}

		// Check if Easy 2 difficulty
		else if (m_difficulty == EDifficulty::EASY_02)
		{
			print("DIFFICULTY - EASY_02");

			// Step through the array and destroy all the actors
			for (int i = 0; i < m_s2EasyModeSetup.Num(); i++)
			{
				m_s2EasyModeSetup[i]->Destroy();
			}

			Character->m_isEasy1Difficulty = false;
			Character->m_isEasy2Difficulty = true;

			Character->m_isMedium1Difficulty = false;
			Character->m_isMedium2Difficulty = false;

			Character->m_isHard1Difficulty = false;
			Character->m_isHard2Difficulty = false;
		}

		// Check if Medium 1 difficulty
		else if (m_difficulty == EDifficulty::MEDIUM_01)
		{
			print("DIFFICULTY - MEDIUM_01");

			// Step through the array and destroy all the actors
			for (int i = 0; i < m_s2MediumModeSetup.Num(); i++)
			{
				m_s2MediumModeSetup[i]->Destroy();
			}

			Character->m_isEasy1Difficulty = false;
			Character->m_isEasy2Difficulty = false;

			Character->m_isMedium1Difficulty = true;
			Character->m_isMedium2Difficulty = false;

			Character->m_isHard1Difficulty = false;
			Character->m_isHard2Difficulty = false;
		}
		
		// Check if Medium 2 difficulty
		else if (m_difficulty == EDifficulty::MEDIUM_02)
		{
			print("DIFFICULTY - MEDIUM_02");

			// Step through the array and destroy all the actors
			for (int i = 0; i < m_s2MediumModeSetup.Num(); i++)
			{
				m_s2MediumModeSetup[i]->Destroy();
			}

			Character->m_isEasy1Difficulty = false;
			Character->m_isEasy2Difficulty = false;

			Character->m_isMedium1Difficulty = false;
			Character->m_isMedium2Difficulty = true;

			Character->m_isHard1Difficulty = false;
			Character->m_isHard2Difficulty = false;
		}

		// Check if Hard 1 difficulty
		else if (m_difficulty == EDifficulty::HARD_01)
		{
			print("DIFFICULTY - HARD_01");

			// Step through the array and destroy all the actors
			for (int i = 0; i < m_s2HardModeSetup.Num(); i++)
			{
				m_s2HardModeSetup[i]->Destroy();
			}

			Character->m_isEasy1Difficulty = false;
			Character->m_isEasy2Difficulty = false;

			Character->m_isMedium1Difficulty = false;
			Character->m_isMedium2Difficulty = false;

			Character->m_isHard1Difficulty = true;
			Character->m_isHard2Difficulty = false;
		}
		
		// Check if Hard 2 difficulty
		else if (m_difficulty == EDifficulty::HARD_02)
		{
			print("DIFFICULTY - HARD_02");

			// Step through the array and destroy all the actors
			for (int i = 0; i < m_s2HardModeSetup.Num(); i++)
			{
				m_s2HardModeSetup[i]->Destroy();
			}

			Character->m_isEasy1Difficulty = false;
			Character->m_isEasy2Difficulty = false;

			Character->m_isMedium1Difficulty = false;
			Character->m_isMedium2Difficulty = false;

			Character->m_isHard1Difficulty = false;
			Character->m_isHard2Difficulty = true;
		}
	}
}

void ADDATriggerBox::OnOverlapBegin(AActor * OverlappedActor, AActor * OtherActor)
{
	Gamemode->GetElapedTime(true, false);

//#####################################################################################################
							// SECTION 1 TRIGGER BOX
//#####################################################################################################
	
// Check if the trigger box is the first one
	if (OverlappedActor->GetName() == "DDATriggerBox_01")
	{
		// Check if the actor overlapping the trigger box is the FirstPersonCharacter
		if (OtherActor && OtherActor != this && OtherActor->GetName() == "FirstPersonCharacter")
		{
			// Do the checks for the total time and set the difficult etc etc
			// Spawn a certain amount of enemies based on the above

			// Get the current seconds spent in level
			m_intSeconds = Gamemode->GetSecondsInt();

			// Check if seconds is greater than or equal to 5
			if (m_intSeconds >= 5)
			{
				// Easy Setting
				// Check if total movement time is greater than 5
				if (Character->GetTotalMovementTime() > 5)
				{
					m_difficulty = EDifficulty::EASY_01;
				}

				// Medium Setting
				// Check if total movement time is equal to 3, 4, or 5
				else if (Character->GetTotalMovementTime() >= 3 && Character->GetTotalMovementTime() <= 5)
				{
					m_difficulty = EDifficulty::MEDIUM_01;
				}

				// Hard Setting
				// Check if total movement time is equal to 0, 1, or 2
				else if (Character->GetTotalMovementTime() <= 2)
				{
					m_difficulty = EDifficulty::HARD_01;
				}
			}
			// If seconds equals less than 5
			else
			{
				// Medium Setting
				// Check if total movement time is equal to the total time spent in the level
				if (Character->GetTotalMovementTime() == m_intSeconds)
				{
					m_difficulty = EDifficulty::MEDIUM_01;
				}

				// Hard Setting
				// Otherwise, set to hard mode
				else
				{
					m_difficulty = EDifficulty::HARD_01;
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
		// Check if the actor overlapping the trigger box is the FirstPersonCharacter
		if (OtherActor && OtherActor != this && OtherActor->GetName() == "FirstPersonCharacter")
		{
			// Get the current seconds spent in level
			m_intSeconds = Gamemode->GetSecondsInt();

			// Get the current difficulty setting
			//sm_difficulty = GetEDifficulty();

			// Check if seconds is greater than or equal to 15
			if (m_intSeconds >= 15)
			{
				// Check if total movement time is greater than 13
				if (Character->GetTotalMovementTime() >= 13)
				{
					// Check if total time in sentry light is equal to 0
					if (Character->GetTotalInLightTime() == 0)
					{
						// If Easy_01 difficulty, set difficulty to Medium_01
						if (GetEDifficulty() == EDifficulty::EASY_01)
						{
							print("DIFFICULTY - MEDIUM_01");
							m_difficulty = EDifficulty::MEDIUM_01;
						}

						// If Medium_01 difficulty, set difficulty to Medium_02
						else if (GetEDifficulty() == EDifficulty::MEDIUM_01)
						{
							print("DIFFICULTY - MEDIUM_02");
							m_difficulty = EDifficulty::MEDIUM_02;
						}

						// If Hard_01 difficulty, set difficulty to Hard_02
						else if (GetEDifficulty() == EDifficulty::HARD_01)
						{
							print("DIFFICULTY - HARD_02");
							m_difficulty = EDifficulty::HARD_02;
						}

						else
						{
							print("ERROR - NO SET DIFFICULTY FOUND");
						}
					}

					// Check if total time in sentry light is 1, 2, 3, or 4
					else if (Character->GetTotalInLightTime() >= 1 && Character->GetTotalInLightTime() <= 4)
					{
						// If Medium_01 difficulty, set difficulty to Medium_02
						if (GetEDifficulty() == EDifficulty::MEDIUM_01)
						{
							print("DIFFICULTY - MEDIUM_02");
							m_difficulty = EDifficulty::MEDIUM_02;
						}

						// Else, set difficulty to Medium_01
						else
						{
							print("DIFFICULTY - MEDIUM_01");
							m_difficulty = EDifficulty::MEDIUM_01;
						}
					}

					// Check if total time in sentry light is 5 or more
					else if (Character->GetTotalInLightTime() >= 5)
					{
						// If Easy_01 difficulty, set difficulty to Easy_02
						if (GetEDifficulty() == EDifficulty::EASY_01)
						{
							print("DIFFICULTY - EASY_02");
							m_difficulty = EDifficulty::EASY_02;
						}

						// If Hard_01 difficulty, set difficulty to Medium_01
						else if (GetEDifficulty() == EDifficulty::HARD_01)
						{
							print("DIFFICULTY - MEDIUM_01");
							m_difficulty = EDifficulty::MEDIUM_01;
						}

						// Else, set difficulty to Easy_01
						else
						{
							print("DIFFICULTY - EASY_01");
							m_difficulty = EDifficulty::EASY_01;
						}
					}
				}

				// Check if total movement time is equal to 9, 10, 11, or 12
				else if (Character->GetTotalMovementTime() >= 9 && Character->GetTotalMovementTime() <= 12)
				{
					// If total in light equals 3 or less
					if (Character->GetTotalInLightTime() <= 3)
					{
						// If Medium_01 difficulty, set difficulty to Medium_02
						if (GetEDifficulty() == EDifficulty::MEDIUM_01)
						{
							print("DIFFICULTY - MEDIUM_02");
							m_difficulty = EDifficulty::MEDIUM_02;
						}

						// Else, set difficulty to Medium_01
						else
						{
							print("DIFFICULTY - MEDIUM_01");
							m_difficulty = EDifficulty::MEDIUM_01;
						}
					}

					// Check if total in light time equals greater than or equal to 4
					else if (Character->GetTotalInLightTime() >= 4)
					{
						// If Easy_01 difficulty, set difficulty to Medium_01
						if (GetEDifficulty() == EDifficulty::EASY_01)
						{
							print("DIFFICULTY - MEDIUM_01");
							m_difficulty = EDifficulty::MEDIUM_01;
						}

						// Else, if Hard_01 difficulty, set difficulty to Hard_02
						if (GetEDifficulty() == EDifficulty::HARD_02)
						{
							print("DIFFICULTY - HARD_02");
							m_difficulty = EDifficulty::HARD_02;
						}

						// Else, set difficulty to Hard_01
						else
						{
							print("DIFFICULTY - HARD_01");
							m_difficulty = EDifficulty::HARD_01;
						}
					}
				}

				// Check if total movement time is equal to or less than 8
				else if (Character->GetTotalMovementTime() <= 8)
				{
					// If Hard_01 difficulty, set difficulty to Hard_02
					if (GetEDifficulty() == EDifficulty::HARD_01)
					{
						print("DIFFICULTY - HARD_02");
						m_difficulty = EDifficulty::HARD_02;
					}

					// Else, set difficulty to Hard_01
					else
					{
						print("DIFFICULTY - HARD_01");
						m_difficulty = EDifficulty::HARD_01;
					}
				}
			}

			// If seconds equals less than 15
			else
			{
				// Check if total movement time is equal to the total time spent in the level
				if (Character->GetTotalMovementTime() == m_intSeconds)
				{
					// If Medium_01 difficulty, set difficulty to Medium_02
					if (GetEDifficulty() == EDifficulty::MEDIUM_01)
					{
						print("DIFFICULTY - MEDIUM_02");
						m_difficulty = EDifficulty::MEDIUM_02;
					}

					// Else, set difficulty to Medium_01
					else if (GetEDifficulty() == EDifficulty::EASY_01 || GetEDifficulty() == EDifficulty::HARD_01)
					{
						print("DIFFICULTY - MEDIUM_01");
						m_difficulty = EDifficulty::MEDIUM_01;
					}

					// Else, print ERROR message
					else
					{
						print("ERROR - NO SET DIFFICULTY");
					}
				}

				// Otherwise, set to hard mode
				else
				{
					// If Hard_01 difficulty, set difficulty to Hard_02
					if (GetEDifficulty() == EDifficulty::HARD_01)
					{
						print("DIFFICULTY - HARD_02");
						m_difficulty = EDifficulty::HARD_02;
					}

					// If Easy_01 or Medium_01 difficulty, set difficulty to Hard_01
					else if (GetEDifficulty() == EDifficulty::EASY_01 || GetEDifficulty() == EDifficulty::MEDIUM_01)
					{
						print("DIFFICULTY - HARD_01");
						m_difficulty = EDifficulty::HARD_01;
					}

					// Else, print ERROR message
					else
					{
						print("ERROR - NO SET DIFFICULTY FOUND");
					}
				}
			}

			// Setup the difficulty within the level
			DifficultyFinializedSetup(false, true);

			// Destroy the trigger box
			OverlappedActor->Destroy();
		}
	}
}

void ADDATriggerBox::OnOverLapEnd(AActor * OverlappedActor, AActor * OtherActor)
{
	if (OtherActor && (OtherActor != this) && (OverlappedActor->GetName() == "FirstPersonCharacter"))
	{
		printf("Actor Left = %s", *OverlappedActor->GetName());
		printf("Actor Overlapped = %s", *OtherActor->GetName());
	}
}
