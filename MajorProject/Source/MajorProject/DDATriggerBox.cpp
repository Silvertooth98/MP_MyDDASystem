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

void ADDATriggerBox::DifficultySetup(bool Easy, bool Medium, bool Hard)
{
	m_easyDifficulty = Easy;
	m_mediumDifficulty = Medium;
	m_hardDifficulty = Hard;
}

void ADDATriggerBox::DifficultyFinializedSetup(bool S1, bool S2, bool S3)
{
	// Check if player is within the first section trigger box
	if (S1)
	{
		print("SECTION 1");

		// Check if easy difficulty
		if (m_easyDifficulty)
		{
			print("DIFFICULTY - EASY");

			// Step through the array and destroy all the actors
			for (int i = 0; i < m_s1EasyModeSetup.Num(); i++)
			{
				m_s1EasyModeSetup[i]->Destroy();
			}

			m_lastDifficultySetting = "EASY";

			Character->m_isEasyDifficulty = true;
			Character->m_isMediumDifficulty = false;
			Character->m_isHardDifficulty = false;
		}
		// Check if medium difficulty
		else if (m_mediumDifficulty)
		{
			print("DIFFICULTY - MEDIUM");

			// Step through the array and destroy all the actors
			for (int i = 0; i < m_s1MediumModeSetup.Num(); i++)
			{
				m_s1MediumModeSetup[i]->Destroy();
			}

			m_lastDifficultySetting = "MEDIUM";

			Character->m_isEasyDifficulty = false;
			Character->m_isMediumDifficulty = true;
			Character->m_isHardDifficulty = false;
		}
		// Check if hard difficuly
		else if (m_hardDifficulty)
		{
			print("DIFFICULTY - HARD");

			// Step through the array and destroy all the actors
			for (int i = 0; i < m_s1HardModeSetup.Num(); i++)
			{
				m_s1HardModeSetup[i]->Destroy();
			}

			m_lastDifficultySetting = "HARD";

			Character->m_isEasyDifficulty = false;
			Character->m_isMediumDifficulty = false;
			Character->m_isHardDifficulty = true;
		}
	}

	// Check if player is within the second section trigger box
	else if (S2)
	{
		print("SECTION 2");

		// Check if easy difficulty
		if (m_easyDifficulty)
		{
			print("DIFFICULTY - EASY");

			// Step through the array and destroy all the actors
			for (int i = 0; i < m_s2EasyModeSetup.Num(); i++)
			{
				m_s2EasyModeSetup[i]->Destroy();
			}

			m_lastDifficultySetting = "EASY";
		}
		// Check if medium difficulty
		else if (m_mediumDifficulty)
		{
			print("DIFFICULTY - MEDIUM");

			// Step through the array and destroy all the actors
			for (int i = 0; i < m_s2MediumModeSetup.Num(); i++)
			{
				m_s2MediumModeSetup[i]->Destroy();
			}

			m_lastDifficultySetting = "MEDIUM";
		}
		// Check if hard difficuly
		else if (m_hardDifficulty)
		{
			print("DIFFICULTY - HARD");

			// Step through the array and destroy all the actors
			for (int i = 0; i < m_s2HardModeSetup.Num(); i++)
			{
				m_s2HardModeSetup[i]->Destroy();
			}

			m_lastDifficultySetting = "HARD";
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
					DifficultySetup(true);
				}
				// Medium Setting
				// Check if total movement time is equal to 3, 4, or 5
				else if (Character->GetTotalMovementTime() >= 3 && Character->GetTotalMovementTime() <= 5)
				{
					DifficultySetup(false, true);
				}
				// Hard Setting
				// Check if total movement time is equal to 0, 1, or 2
				else if (Character->GetTotalMovementTime() <= 2)
				{
					DifficultySetup(false, false, true);
				}
			}
			// If seconds equals less than 5
			else
			{
				// Medium Setting
				// Check if total movement time is equal to the total time spent in the level
				if (Character->GetTotalMovementTime() == m_intSeconds)
				{
					DifficultySetup(false, true);
				}
				// Hard Setting
				// Otherwise, set to hard mode
				else
				{
					DifficultySetup(false, false, true);
				}
			}

			// Setup the difficulty within the level
			DifficultyFinializedSetup(true);

			GEngine->AddOnScreenDebugMessage(-1, 5.0, FColor::Green, m_lastDifficultySetting);

			// Destroy the trigger box
			OverlappedActor->Destroy();

			//m_setDifficulty = true;
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
			//GEngine->AddOnScreenDebugMessage(-1, 5.0, FColor::Green, TEXT("LD: " + m_lastDifficultySetting));

			// Get the current seconds spent in level
			m_intSeconds = Gamemode->GetSecondsInt();

			// Check if seconds is greater than or equal to 5
			if (m_intSeconds >= 10)
			{
				// Easy Setting
				// Check if total movement time is greater than 12
				if (Character->GetTotalMovementTime() > 12)
				{
					// Check if total time in sentry light is equal to 0
					if (Character->GetTotalInLightTime() == 0)
					{
						// Check last difficulty setting
						if (Character->m_isEasyDifficulty)
						{
							print("DIFFICULTY - MEDIUM");

							DifficultySetup(false, true);
						}
						else if (Character->m_isMediumDifficulty || Character->m_isHardDifficulty)
						{
							print("DIFFICULTY - HARD");

							DifficultySetup(false, false, true);
						}
						else
						{
							print("NO SET DIFFICULTY FOUND");
						}
					}
					// Check if total time in sentry light is 1, 2, 3, or 4
					else if (Character->GetTotalInLightTime() >= 1 && Character->GetTotalInLightTime() <= 4)
					{
						print("DIFFICULTY - MEDIUM");

						DifficultySetup(false, true);
					}
					// Check if total time in sentry light is 5 or more
					else if (Character->GetTotalInLightTime() >= 5)
					{
						print("IN LIGHT 5+ SECONDS");

						// Check last difficulty setting
						if (Character->m_isEasyDifficulty || Character->m_isMediumDifficulty)
						{
							DifficultySetup(true);
						}
						else if (Character->m_isHardDifficulty)
						{
							DifficultySetup(false, true);
						}
					}
				}
				// Medium Setting
				// Check if total movement time is equal to 9, 10, 11
				else if (Character->GetTotalMovementTime() >= 9 && Character->GetTotalMovementTime() <= 11)
				{
					DifficultySetup(false, true);
				}
				// Hard Setting
				// Check if total movement time is equal to 6, 7, or 8
				else if (Character->GetTotalMovementTime() >= 6 && Character->GetTotalMovementTime() <= 8)
				{
					DifficultySetup(false, false, true);
				}
			}
			// If seconds equals less than 10
			else
			{
				// Medium Setting
				// Check if total movement time is equal to the total time spent in the level
				if (Character->GetTotalMovementTime() == m_intSeconds)
				{
					DifficultySetup(false, true);
				}
				// Hard Setting
				// Otherwise, set to hard mode
				else
				{
					DifficultySetup(false, false, true);
				}
			}

			// Setup the difficulty within the level
			DifficultyFinializedSetup(false, true);

			// Destroy the trigger box
			OverlappedActor->Destroy();

			//m_setDifficulty = true;
		}
	}
}

void ADDATriggerBox::OnOverLapEnd(AActor * OverlappedActor, AActor * OtherActor)
{
	if (OtherActor && (OtherActor != this) && (OverlappedActor->GetName() == "FirstPersonCharacter"))
	{
		printf("Actor Left = %s", *OverlappedActor->GetName());
		printf("Actor Overlapped = %s", *OtherActor->GetName());
		//m_setDifficulty = false;
	}
}
