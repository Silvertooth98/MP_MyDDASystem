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

void ADDATriggerBox::DifficultyFinializedSetup(bool S1, bool S2, bool S3)
{
//#####################################################################################################
							// SECTION 1 TRIGGER BOX
//#####################################################################################################
	// Check if player is within the first section trigger box
	if (S1)
	{
		print("SECTION 1");

		Character->m_section01 = true;
		Character->m_section02 = false;
		Character->m_section03 = false;

		// Check if easy difficulty
		if (m_difficulty == EDifficulty::EASY_01)
		{
			print("DIFFICULTY - EASY");

			// Step through the array and destroy all the actors
			for (int i = 0; i < m_s1EasyModeSetup.Num(); i++)
			{
				m_s1EasyModeSetup[i]->Destroy();
			}

			Character->SetDifficulty(Character->m_setDifficulty = ESetDifficulty::EASY_01);
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

			Character->SetDifficulty(Character->m_setDifficulty = ESetDifficulty::MEDIUM_01);
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

			Character->SetDifficulty(Character->m_setDifficulty = ESetDifficulty::HARD_01);
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

		Character->m_section01 = false;
		Character->m_section02 = true;
		Character->m_section03 = false;

		// Check if Easy 1 difficulty
		if (m_difficulty == EDifficulty::EASY_01)
		{
			print("DIFFICULTY - EASY_01");

			// Step through the array and destroy all the actors
			for (int i = 0; i < m_s2EasyMode1Setup.Num(); i++)
			{
				m_s2EasyMode1Setup[i]->Destroy();
			}

			Character->SetDifficulty(Character->m_setDifficulty = ESetDifficulty::EASY_01);
		}

		// Check if Easy 2 difficulty
		else if (m_difficulty == EDifficulty::EASY_02)
		{
			print("DIFFICULTY - EASY_02");

			// Step through the array and destroy all the actors
			for (int i = 0; i < m_s2EasyMode2Setup.Num(); i++)
			{
				m_s2EasyMode2Setup[i]->Destroy();
			}

			Character->SetDifficulty(Character->m_setDifficulty = ESetDifficulty::EASY_02);
		}

		// Check if Medium 1 difficulty
		else if (m_difficulty == EDifficulty::MEDIUM_01)
		{
			print("DIFFICULTY - MEDIUM_01");

			// Step through the array and destroy all the actors
			for (int i = 0; i < m_s2MediumMode1Setup.Num(); i++)
			{
				m_s2MediumMode1Setup[i]->Destroy();
			}

			Character->SetDifficulty(Character->m_setDifficulty = ESetDifficulty::MEDIUM_01);
		}
		
		// Check if Medium 2 difficulty
		else if (m_difficulty == EDifficulty::MEDIUM_02)
		{
			print("DIFFICULTY - MEDIUM_02");

			// Step through the array and destroy all the actors
			for (int i = 0; i < m_s2MediumMode2Setup.Num(); i++)
			{
				m_s2MediumMode2Setup[i]->Destroy();
			}

			Character->SetDifficulty(Character->m_setDifficulty = ESetDifficulty::MEDIUM_02);
		}

		// Check if Hard 1 difficulty
		else if (m_difficulty == EDifficulty::HARD_01)
		{
			print("DIFFICULTY - HARD_01");

			// Step through the array and destroy all the actors
			for (int i = 0; i < m_s2HardMode1Setup.Num(); i++)
			{
				m_s2HardMode1Setup[i]->Destroy();
			}

			Character->SetDifficulty(Character->m_setDifficulty = ESetDifficulty::HARD_01);
		}
		
		// Check if Hard 2 difficulty
		else if (m_difficulty == EDifficulty::HARD_02)
		{
			print("DIFFICULTY - HARD_02");

			// Step through the array and destroy all the actors
			for (int i = 0; i < m_s2HardMode2Setup.Num(); i++)
			{
				m_s2HardMode2Setup[i]->Destroy();
			}

			Character->SetDifficulty(Character->m_setDifficulty = ESetDifficulty::HARD_02);
		}
	}

//#####################################################################################################
							// SECTION 3 TRIGGER BOX
//#####################################################################################################
	// Check if player is within the third section trigger box
	else if (S3)
	{
		print("SECTION 3");

		Character->m_section01 = false;
		Character->m_section02 = false;
		Character->m_section03 = true;

		// Check if Easy 1 difficulty
		if (m_difficulty == EDifficulty::EASY_01)
		{
			print("DIFFICULTY - EASY_01");

			// Step through the array and destroy all the actors
			for (int i = 0; i < m_s3EasyMode1Setup.Num(); i++)
			{
				m_s3EasyMode1Setup[i]->Destroy();
			}

			Character->SetDifficulty(Character->m_setDifficulty = ESetDifficulty::EASY_01);
		}

		// Check if Easy 2 difficulty
		else if (m_difficulty == EDifficulty::EASY_02)
		{
			print("DIFFICULTY - EASY_02");

			// Step through the array and destroy all the actors
			for (int i = 0; i < m_s3EasyMode2Setup.Num(); i++)
			{
				m_s3EasyMode2Setup[i]->Destroy();
			}

			Character->SetDifficulty(Character->m_setDifficulty = ESetDifficulty::EASY_02);
		}

		// Check if Medium 1 difficulty
		else if (m_difficulty == EDifficulty::MEDIUM_01)
		{
			print("DIFFICULTY - MEDIUM_01");

			// Step through the array and destroy all the actors
			for (int i = 0; i < m_s3MediumMode1Setup.Num(); i++)
			{
				m_s3MediumMode1Setup[i]->Destroy();
			}

			Character->SetDifficulty(Character->m_setDifficulty = ESetDifficulty::MEDIUM_01);
		}

		// Check if Medium 2 difficulty
		else if (m_difficulty == EDifficulty::MEDIUM_02)
		{
			print("DIFFICULTY - MEDIUM_02");

			// Step through the array and destroy all the actors
			for (int i = 0; i < m_s3MediumMode2Setup.Num(); i++)
			{
				m_s3MediumMode2Setup[i]->Destroy();
			}

			Character->SetDifficulty(Character->m_setDifficulty = ESetDifficulty::MEDIUM_02);
		}

		// Check if Hard 1 difficulty
		else if (m_difficulty == EDifficulty::HARD_01)
		{
			print("DIFFICULTY - HARD_01");

			// Step through the array and destroy all the actors
			for (int i = 0; i < m_s3HardMode1Setup.Num(); i++)
			{
				m_s3HardMode1Setup[i]->Destroy();
			}

			Character->SetDifficulty(Character->m_setDifficulty = ESetDifficulty::HARD_01);
		}

		// Check if Hard 2 difficulty
		else if (m_difficulty == EDifficulty::HARD_02)
		{
			print("DIFFICULTY - HARD_02");

			// Step through the array and destroy all the actors
			for (int i = 0; i < m_s3HardMode2Setup.Num(); i++)
			{
				m_s3HardMode2Setup[i]->Destroy();
			}

			Character->SetDifficulty(Character->m_setDifficulty = ESetDifficulty::HARD_02);
		}
	}
}

void ADDATriggerBox::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
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
						if (Character->m_setDifficulty == ESetDifficulty::EASY_01)
						{
							print("DIFFICULTY - MEDIUM_01");
							m_difficulty = EDifficulty::MEDIUM_01;
						}

						// If Medium_01 difficulty, set difficulty to Medium_02
						else if (Character->m_setDifficulty == ESetDifficulty::MEDIUM_01)
						{
							print("DIFFICULTY - MEDIUM_02");
							m_difficulty = EDifficulty::MEDIUM_02;
						}

						// If Hard_01 difficulty, set difficulty to Hard_02
						else if (Character->m_setDifficulty == ESetDifficulty::HARD_01)
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
						if (Character->m_setDifficulty == ESetDifficulty::MEDIUM_01)
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
						if (Character->m_setDifficulty == ESetDifficulty::EASY_01)
						{
							print("DIFFICULTY - EASY_02");
							m_difficulty = EDifficulty::EASY_02;
						}

						// If Hard_01 difficulty, set difficulty to Medium_01
						else if (Character->m_setDifficulty == ESetDifficulty::HARD_01)
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
						if (Character->m_setDifficulty == ESetDifficulty::MEDIUM_01)
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
						if (Character->m_setDifficulty == ESetDifficulty::EASY_01)
						{
							print("DIFFICULTY - MEDIUM_01");
							m_difficulty = EDifficulty::MEDIUM_01;
						}

						// Else, if Hard_01 difficulty, set difficulty to Hard_02
						if (Character->m_setDifficulty == ESetDifficulty::HARD_01)
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
					if (Character->m_setDifficulty == ESetDifficulty::HARD_01)
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
					if (Character->m_setDifficulty == ESetDifficulty::MEDIUM_01)
					{
						print("DIFFICULTY - MEDIUM_02");
						m_difficulty = EDifficulty::MEDIUM_02;
					}

					// Else, set difficulty to Medium_01
					else if (Character->m_setDifficulty == ESetDifficulty::EASY_01 || 
							 Character->m_setDifficulty == ESetDifficulty::HARD_01)
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
					if (Character->m_setDifficulty == ESetDifficulty::HARD_01)
					{
						print("DIFFICULTY - HARD_02");
						m_difficulty = EDifficulty::HARD_02;
					}

					// If Easy_01 or Medium_01 difficulty, set difficulty to Hard_01
					else if (Character->m_setDifficulty == ESetDifficulty::EASY_01 || 
							 Character->m_setDifficulty == ESetDifficulty::MEDIUM_01)
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

//#####################################################################################################
							// SECTION 3 TRIGGER BOX
//#####################################################################################################

	// Check if the trigger box is the third one
	else if (OverlappedActor->GetName() == "DDATriggerBox_03")
	{
		// Check if the actor overlapping the trigger box is the FirstPersonCharacter
		if (OtherActor && OtherActor != this && OtherActor->GetName() == "FirstPersonCharacter")
		{
			// Get the current seconds spent in level
			m_intSeconds = Gamemode->GetSecondsInt();

			// Check if seconds is greater than or equal to 25
			if (m_intSeconds >= 25)
			{
				// Check if total movement time is greater than 20
				if (Character->GetTotalMovementTime() >= 20)
				{
					// Check if total time in sentry light is equal to 0
					if (Character->GetTotalInLightTime() == 0)
					{
						// If Easy_01 or Easy_02 difficulty, set difficulty to Medium_01
						if (Character->m_setDifficulty == ESetDifficulty::EASY_01 ||
							Character->m_setDifficulty == ESetDifficulty::EASY_02)
						{
							print("DIFFICULTY - MEDIUM_01");
							m_difficulty = EDifficulty::MEDIUM_01;
						}

						// If Medium_01 difficulty, set difficulty to Medium_02
						else if (Character->m_setDifficulty == ESetDifficulty::MEDIUM_01)
						{
							print("DIFFICULTY - MEDIUM_02");
							m_difficulty = EDifficulty::MEDIUM_02;
						}

						// If Merdium_02, Hard_01, or Hard_02 difficulty, set difficulty to Hard_02
						else if (Character->m_setDifficulty == ESetDifficulty::MEDIUM_02 ||
								 Character->m_setDifficulty == ESetDifficulty::HARD_01 ||
								 Character->m_setDifficulty == ESetDifficulty::HARD_02)
						{
							print("DIFFICULTY - HARD_02");
							m_difficulty = EDifficulty::HARD_02;
						}

						else
						{
							print("ERROR - NO SET DIFFICULTY FOUND");
						}
					}

					// Check if total time in sentry light is between 1-6
					else if (Character->GetTotalInLightTime() >= 1 && Character->GetTotalInLightTime() <= 6)
					{
						// If Medium_01 difficulty, set difficulty to Medium_02
						if (Character->m_setDifficulty == ESetDifficulty::MEDIUM_01)
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

					// Check if total time in sentry light is 7 or more
					else if (Character->GetTotalInLightTime() >= 7)
					{
						// If Easy_01 or Easy_02 difficulty, set difficulty to Easy_02
						if (Character->m_setDifficulty == ESetDifficulty::EASY_01 ||
							Character->m_setDifficulty == ESetDifficulty::EASY_02)
						{
							print("DIFFICULTY - EASY_02");
							m_difficulty = EDifficulty::EASY_02;
						}

						// If Medium_02, Hard_01, or Hard_02 difficulty, set difficulty to Medium_01
						else if (Character->m_setDifficulty == ESetDifficulty::MEDIUM_02 ||
								 Character->m_setDifficulty == ESetDifficulty::HARD_01 ||
								 Character->m_setDifficulty == ESetDifficulty::HARD_02)
						{
							print("DIFFICULTY - MEDIUM_01");
							m_difficulty = EDifficulty::MEDIUM_01;
						}

						// Else, set difficulty to Easy_01 (Else wil be if difficulty = Medium_01
						else
						{
							print("DIFFICULTY - EASY_01");
							m_difficulty = EDifficulty::EASY_01;
						}
					}
				}

				// Check if total movement time is equal to 17, 18, or 19
				else if (Character->GetTotalMovementTime() >= 17 && Character->GetTotalMovementTime() <= 19)
				{
					// If total in light equals 5 or less
					if (Character->GetTotalInLightTime() <= 5)
					{
						// If Medium_01 difficulty, set difficulty to Medium_02
						if (Character->m_setDifficulty == ESetDifficulty::MEDIUM_01 ||
							Character->m_setDifficulty == ESetDifficulty::MEDIUM_02)
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

					// Check if total in light time equals greater than or equal to 6
					else if (Character->GetTotalInLightTime() >= 6)
					{
						// If Easy_01 difficulty, set difficulty to Medium_01
						if (Character->m_setDifficulty == ESetDifficulty::EASY_01 ||
							Character->m_setDifficulty == ESetDifficulty::EASY_02)
						{
							print("DIFFICULTY - MEDIUM_01");
							m_difficulty = EDifficulty::MEDIUM_01;
						}

						// Else, if Hard_01 difficulty, set difficulty to Hard_02
						if (Character->m_setDifficulty == ESetDifficulty::HARD_01 ||
							Character->m_setDifficulty == ESetDifficulty::HARD_02)
						{
							print("DIFFICULTY - HARD_02");
							m_difficulty = EDifficulty::HARD_02;
						}

						// Else, set difficulty to Hard_01 (Medium_01 and Medium_02)
						else
						{
							print("DIFFICULTY - HARD_01");
							m_difficulty = EDifficulty::HARD_01;
						}
					}
				}

				// Check if total movement time is equal to or less than 16
				else if (Character->GetTotalMovementTime() <= 16)
				{
					// If Hard_01 or Hard_02 difficulty, set difficulty to Hard_02
					if (Character->m_setDifficulty == ESetDifficulty::HARD_01 ||
						Character->m_setDifficulty == ESetDifficulty::HARD_02)
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

			// If seconds equals less than 20
			else
			{
				// Check if total movement time is equal to or greater than the total time spent in the level - 2
				if (Character->GetTotalMovementTime() >= (m_intSeconds - 2))
				{
					// If Medium_01 difficulty, set difficulty to Medium_02
					if (Character->m_setDifficulty == ESetDifficulty::MEDIUM_01 ||
						Character->m_setDifficulty == ESetDifficulty::MEDIUM_02)
					{
						print("DIFFICULTY - MEDIUM_02");
						m_difficulty = EDifficulty::MEDIUM_02;
					}

					// Else if any other difficulty, set difficulty to Medium_01
					else if (Character->m_setDifficulty == ESetDifficulty::EASY_01 ||
							 Character->m_setDifficulty == ESetDifficulty::EASY_02 ||
							 Character->m_setDifficulty == ESetDifficulty::HARD_01 ||
							 Character->m_setDifficulty == ESetDifficulty::HARD_02)
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
					if (Character->m_setDifficulty == ESetDifficulty::HARD_01 ||
						Character->m_setDifficulty == ESetDifficulty::HARD_02)
					{
						print("DIFFICULTY - HARD_02");
						m_difficulty = EDifficulty::HARD_02;
					}

					// Else if any other difficulty, set difficulty to Hard_01
					else if (Character->m_setDifficulty == ESetDifficulty::EASY_01 ||
							 Character->m_setDifficulty == ESetDifficulty::EASY_02 ||
							 Character->m_setDifficulty == ESetDifficulty::MEDIUM_01 ||
							 Character->m_setDifficulty == ESetDifficulty::MEDIUM_02)
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
			DifficultyFinializedSetup(false, false, true);

			// Destroy the trigger box
			OverlappedActor->Destroy();
		}
	}
}

void ADDATriggerBox::OnOverLapEnd(AActor * OverlappedActor, AActor * OtherActor)
{
	if (OtherActor && OtherActor != this && OtherActor->GetName() == "FirstPersonCharacter")
	{
		printf("Actor Left = %s", *OverlappedActor->GetName());
		printf("Actor Overlapped = %s", *OtherActor->GetName());
	}
}
