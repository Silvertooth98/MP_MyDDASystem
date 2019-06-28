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

void ADDATriggerBox::DifficultyFinializedSetup(ESections section)
{
	//############################################################################################################################
												// LEVEL 01 SECTIONS
	//############################################################################################################################
	if (m_currentLevel == "Level_01")
	{
		switch (section)
		{
		//#####################################################################################################
									// SECTION 1 TRIGGER BOX
		//#####################################################################################################
		// Check if player is within the first section trigger box
		case ESections::SECTION_01:
			print("Switch case S1");
			// Set section enum in the character class to section_01
			Character->m_section = ESection::SECTION_01;

			switch (Character->m_CharDifficulty->GetStateEDiff())
			{
			case EDifficulty::EASY_01:
				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S1EasyModeSetup.Num(); i++)
				{
					m_L1S1EasyModeSetup[i]->Destroy();
				}
				break;

			case EDifficulty::MEDIUM_01:
				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S1MediumModeSetup.Num(); i++)
				{
					m_L1S1MediumModeSetup[i]->Destroy();
				}
				break;

			case EDifficulty::HARD_01:
				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S1HardModeSetup.Num(); i++)
				{
					m_L1S1HardModeSetup[i]->Destroy();
				}
				break;

			default:
				break;
			}
			break;

		//#####################################################################################################
									// SECTION 2 TRIGGER BOX
		//#####################################################################################################
		// Check if player is within the second section trigger box
		case ESections::SECTION_02:
			print("Switch case S2");
			// Set section enum in the character class to section_02
			Character->m_section = ESection::SECTION_02;

			switch (Character->m_CharDifficulty->GetStateEDiff())
			{
			case EDifficulty::EASY_01:
				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S2EasyMode1Setup.Num(); i++)
				{
					m_L1S2EasyMode1Setup[i]->Destroy();
				}
				break;

			case EDifficulty::EASY_02:
				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S2EasyMode2Setup.Num(); i++)
				{
					m_L1S2EasyMode2Setup[i]->Destroy();
				}
				break;

			case EDifficulty::MEDIUM_01:
				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S2MediumMode1Setup.Num(); i++)
				{
					m_L1S2MediumMode1Setup[i]->Destroy();
				}
				break;

			case EDifficulty::MEDIUM_02:
				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S2MediumMode2Setup.Num(); i++)
				{
					m_L1S2MediumMode2Setup[i]->Destroy();
				}

			case EDifficulty::HARD_01:
				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S2HardMode1Setup.Num(); i++)
				{
					m_L1S2HardMode1Setup[i]->Destroy();
				}
				break;

			case EDifficulty::HARD_02:
				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S2HardMode2Setup.Num(); i++)
				{
					m_L1S2HardMode2Setup[i]->Destroy();
				}
				break;

			default:
				break;
			}
			break;

		//#####################################################################################################
									// SECTION 3 TRIGGER BOX
		//#####################################################################################################
		// Check if player is within the third section trigger box
		case ESections::SECTION_03:
			print("Switch case S3");
			// Set section enum in the character class to section_03
			Character->m_section = ESection::SECTION_03;

			switch (Character->m_CharDifficulty->GetStateEDiff())
			{
			case EDifficulty::EASY_01:
				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S3EasyMode1Setup.Num(); i++)
				{
					m_L1S3EasyMode1Setup[i]->Destroy();
				}
				break;

			case EDifficulty::EASY_02:
				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S3EasyMode2Setup.Num(); i++)
				{
					m_L1S3EasyMode2Setup[i]->Destroy();
				}
				break;

			case EDifficulty::MEDIUM_01:
				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S3MediumMode1Setup.Num(); i++)
				{
					m_L1S3MediumMode1Setup[i]->Destroy();
				}
				break;

			case EDifficulty::MEDIUM_02:
				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S3MediumMode2Setup.Num(); i++)
				{
					m_L1S3MediumMode2Setup[i]->Destroy();
				}
				break;

			case EDifficulty::HARD_01:
				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S3HardMode1Setup.Num(); i++)
				{
					m_L1S3HardMode1Setup[i]->Destroy();
				}
				break;

			case EDifficulty::HARD_02:
				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S3HardMode2Setup.Num(); i++)
				{
					m_L1S3HardMode2Setup[i]->Destroy();
				}
				break;

			default:
				break;
			}
			break;

		//#####################################################################################################
									// SECTION 4 TRIGGER BOX
		//#####################################################################################################
		// Check if player is within the fourth section trigger box
		case ESections::SECTION_04:
			print("Switch case S4");
			// Set section enum in the character class to section_04
			Character->m_section = ESection::SECTION_04;

			switch (Character->m_CharDifficulty->GetStateEDiff())
			{
			case EDifficulty::EASY_01:
				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S4EasyMode1Setup.Num(); i++)
				{
					m_L1S4EasyMode1Setup[i]->Destroy();
				}
				break;

			case EDifficulty::EASY_02:
				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S4EasyMode2Setup.Num(); i++)
				{
					m_L1S4EasyMode2Setup[i]->Destroy();
				}
				break;

			case EDifficulty::MEDIUM_01:
				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S4MediumMode1Setup.Num(); i++)
				{
					m_L1S4MediumMode1Setup[i]->Destroy();
				}
				break;

			case EDifficulty::MEDIUM_02:
				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S4MediumMode2Setup.Num(); i++)
				{
					m_L1S4MediumMode2Setup[i]->Destroy();
				}
				break;

			case EDifficulty::HARD_01:
				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S4HardMode1Setup.Num(); i++)
				{
					m_L1S4HardMode1Setup[i]->Destroy();
				}
				break;

			case EDifficulty::HARD_02:
				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L1S4HardMode2Setup.Num(); i++)
				{
					m_L1S4HardMode2Setup[i]->Destroy();
				}
				break;

			default:
				break;
			}
			break;

		//#####################################################################################################
									// SECTION 5 TRIGGER BOX
		//#####################################################################################################
		// Check if player is within the last section trigger box
		case ESections::SECTION_05:
			print("Switch case S5");
			// Set section enum in the character class to section_05
			Character->m_section = ESection::SECTION_05;

			switch (Character->m_CharDifficulty->GetStateEDiff())
			{
			case EDifficulty::EASY_01:
				// Set the difficulty within the Game Instance Class, for initial difficulty within Level_02
				GameInstance->m_finalDifficulty = EFinalDifficulty::EASY_01;
				break;

			case EDifficulty::EASY_02:
				// Set the difficulty within the Game Instance Class, for initial difficulty within Level_02
				GameInstance->m_finalDifficulty = EFinalDifficulty::EASY_01;
				break;

			case EDifficulty::MEDIUM_01:
				// Set the difficulty within the Game Instance Class, for initial difficulty within Level_02
				GameInstance->m_finalDifficulty = EFinalDifficulty::MEDIUM_01;
				break;

			case EDifficulty::MEDIUM_02:
				// Set the difficulty within the Game Instance Class, for initial difficulty within Level_02
				GameInstance->m_finalDifficulty = EFinalDifficulty::MEDIUM_01;
				break;

			case EDifficulty::HARD_01:
				// Set the difficulty within the Game Instance Class, for initial difficulty within Level_02
				GameInstance->m_finalDifficulty = EFinalDifficulty::HARD_01;
				break;

			case EDifficulty::HARD_02:
				// Set the difficulty within the Game Instance Class, for initial difficulty within Level_02
				GameInstance->m_finalDifficulty = EFinalDifficulty::HARD_01;
				break;

			default:
				break;
			}
			break;

		default:
			print("Switch case S1 = false");
			break;
		}
	}

	//############################################################################################################################
												// LEVEL 02 SECTIONS
	//############################################################################################################################
	else if (m_currentLevel == "Level_02")
	{
		switch (section)
		{
		//#####################################################################################################
									// SECTION 1 TRIGGER BOX
		//#####################################################################################################
		// Check if player is within the first section trigger box
		case ESections::SECTION_01:
			print("Switch case S1");
			// Set section enum in the character class to section_01
			Character->m_section = ESection::SECTION_01;

			switch (GameInstance->GetDifficulty())
			{
			case EFinalDifficulty::EASY_01:
				Character->m_CharDifficulty->Update(EStates::EASY);
				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L2S1EasyModeSetup.Num(); i++)
				{
					m_L2S1EasyModeSetup[i]->Destroy();
				}
				break;

			case EFinalDifficulty::MEDIUM_01:
				Character->m_CharDifficulty->Update(EStates::MEDIUM);
				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L2S1MediumModeSetup.Num(); i++)
				{
					m_L2S1MediumModeSetup[i]->Destroy();
				}
				break;

			case EFinalDifficulty::HARD_01:
				Character->m_CharDifficulty->Update(EStates::HARD);
				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L2S1HardModeSetup.Num(); i++)
				{
					m_L2S1HardModeSetup[i]->Destroy();
				}
				break;

			default:
				break;
			}
			break;

		//#####################################################################################################
									// SECTION 2 TRIGGER BOX
		//#####################################################################################################
		// Check if player is within the second section trigger box
		case ESections::SECTION_02:
			print("Switch case S2");
			// Set section enum in the character class to section_02
			Character->m_section = ESection::SECTION_02;

			switch (Character->m_CharDifficulty->GetStateEDiff())
			{
			case EDifficulty::EASY_01:
				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L2S2EasyMode1Setup.Num(); i++)
				{
					m_L2S2EasyMode1Setup[i]->Destroy();
				}
				break;

			case EDifficulty::EASY_02:
				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L2S2EasyMode2Setup.Num(); i++)
				{
					m_L2S2EasyMode2Setup[i]->Destroy();
				}
				break;

			case EDifficulty::MEDIUM_01:
				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L2S2MediumMode1Setup.Num(); i++)
				{
					m_L2S2MediumMode1Setup[i]->Destroy();
				}
				break;

			case EDifficulty::MEDIUM_02:
				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L2S2MediumMode2Setup.Num(); i++)
				{
					m_L2S2MediumMode2Setup[i]->Destroy();
				}
				break;

			case EDifficulty::HARD_01:
				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L2S2HardMode1Setup.Num(); i++)
				{
					m_L2S2HardMode1Setup[i]->Destroy();
				}
				break;

			case EDifficulty::HARD_02:
				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L2S2HardMode2Setup.Num(); i++)
				{
					m_L2S2HardMode2Setup[i]->Destroy();
				}
				break;

			default:
				break;
			}
			break;

		//#####################################################################################################
									// SECTION 3 TRIGGER BOX
		//#####################################################################################################
		// Check if player is within the third section trigger box
		case ESections::SECTION_03:
			print("Switch case S3");
			// Set section enum in the character class to section_03
			Character->m_section = ESection::SECTION_03;

			switch (Character->m_CharDifficulty->GetStateEDiff())
			{
			case EDifficulty::EASY_01:
				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L2S3EasyMode1Setup.Num(); i++)
				{
					m_L2S3EasyMode1Setup[i]->Destroy();
				}
				break;

			case EDifficulty::EASY_02:
				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L2S3EasyMode2Setup.Num(); i++)
				{
					m_L2S3EasyMode2Setup[i]->Destroy();
				}
				break;

			case EDifficulty::MEDIUM_01:
				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L2S3MediumMode1Setup.Num(); i++)
				{
					m_L2S3MediumMode1Setup[i]->Destroy();
				}
				break;

			case EDifficulty::MEDIUM_02:
				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L2S3MediumMode2Setup.Num(); i++)
				{
					m_L2S3MediumMode2Setup[i]->Destroy();
				}
				break;

			case EDifficulty::HARD_01:
				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L2S3HardMode1Setup.Num(); i++)
				{
					m_L2S3HardMode1Setup[i]->Destroy();
				}
				break;

			case EDifficulty::HARD_02:
				// Step through the array and destroy all the actors
				for (int i = 0; i < m_L2S3HardMode2Setup.Num(); i++)
				{
					m_L2S3HardMode2Setup[i]->Destroy();
				}
				break;

			default:
				break;
			}
			break;

		//#####################################################################################################
									// SECTION 4 TRIGGER BOX
		//#####################################################################################################
		// Check if player is within the last section trigger box
		case ESections::SECTION_04:
			print("Switch case S4");
			print("END OF " + LEVEL02NAME);
			// Set section enum in the character class to section_04
			Character->m_section = ESection::SECTION_04;
			break;

		default:
			break;
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

	// Check if seconds is greater than or equal to time check
	if (m_intSeconds >= m_timeChk)
	{
		// Check if total movement time is greater than or equal to movement check 1
		if (Character->GetTotalMovementTime() >= m_mvmntChk01)
		{
			// Check if it's not the first trigger box (so either last one or one during level)
			if (!IsFirstTB)
			{
				// Check if total time in sentry light is less than or equal to in light check 1
				if (Character->GetTotalInLightTime() <= m_inLightChk01)
				{
					Character->m_CharDifficulty->Update(EStates::HARD);
				}

				// Check if total time in sentry light is between in light check 2 and 3
				else if (Character->GetTotalInLightTime() >= m_inLightChk02 && Character->GetTotalInLightTime() <= m_inLightChk03)
				{
					Character->m_CharDifficulty->Update(EStates::MEDIUM);
				}

				// Check if total time in sentry light is greater than or equal to in light check 4
				else if (Character->GetTotalInLightTime() >= m_inLightChk04)
				{
					Character->m_CharDifficulty->Update(EStates::EASY);
				}
			}
			// Else the trigger box is the first within the level
			else
			{
				Character->m_CharDifficulty->Update(EStates::EASY);
			}
		}

		// Check if total movement time is between movement check 2 and 3
		else if (Character->GetTotalMovementTime() >= m_mvmntChk02
				&& Character->GetTotalMovementTime() <= m_mvmntChk03)
		{
			// Check if it's not the first trigger box (so either last one or one during level)
			if (!IsFirstTB)
			{
				// Check if total time in sentry light is less than or equal to in light check 3
				if (Character->GetTotalInLightTime() <= m_inLightChk03)
				{
					Character->m_CharDifficulty->Update(EStates::MEDIUM);
				}

				// Check if total time in sentry light is greater than or equal to in light check 4
				else if (Character->GetTotalInLightTime() >= m_inLightChk04)
				{
					Character->m_CharDifficulty->Update(EStates::HARD);
				}
			}
			// Else the trigger box is the first within the level
			else
			{
				Character->m_CharDifficulty->Update(EStates::MEDIUM);
			}
		}

		// Check if total movement time is greater than or equal movement check 4
		else if (Character->GetTotalMovementTime() <= m_mvmntChk04)
		{
			Character->m_CharDifficulty->Update(EStates::HARD);
		}
	}

	// Else, seconds is less than time check
	else
	{
		// Check if total movement time is equal to movement check 5
		if (Character->GetTotalMovementTime() == m_mvmntChk05)
		{
			Character->m_CharDifficulty->Update(EStates::HARD);
		}

		// Check if it's not the first trigger box (so either last one or one during level)
		else if (!IsFirstTB)
		{
			// Check if total movement time equals movement check 5 - 1 or - 2
			if (Character->GetTotalMovementTime() == (m_mvmntChk05 - 1) || Character->GetTotalMovementTime() == (m_mvmntChk05 - 2))
			{
				// Set difficulty to Medium by using the SetDifficulty function within the difficulty class
				Character->m_CharDifficulty->Update(EStates::MEDIUM);
			}

			// Otherwise, set to hard mode
			else
			{
				// Set difficulty to Hard by using the SetDifficulty function within the difficulty class
				Character->m_CharDifficulty->Update(EStates::HARD);
			}
		}

		// Check if total movement time is equal to movement check - 1
		else if (Character->GetTotalMovementTime() == (m_mvmntChk05 - 1))
		{
			// Set difficulty to Medium by using the SetDifficulty function within the difficulty class
			Character->m_CharDifficulty->Update(EStates::MEDIUM);
		}

		// Otherwise, set to hard mode
		else
		{
			// Set difficulty to Hard by using the SetDifficulty function within the difficulty class
			Character->m_CharDifficulty->Update(EStates::HARD);
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
		if (m_currentLevel == LEVEL01NAME)
		{
			// Set level name FString (for saving data to text)
			m_levelName = LEVEL01NAME;

			//#####################################################################################################
										// SECTION 1 TRIGGER BOX
			//#####################################################################################################

			// Check if the trigger box is the first one
			if (OverlappedActor->GetName() == TRIGGERBOX01)
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
				// Save difficulty details onto text file
				Character->m_CharDifficulty->SaveDataToTextFile(m_levelName, m_sectionNum, FString(Character->m_CharDifficulty->GetStrDiff()),
											m_totalTime, m_movementTime, m_inLightTime, m_sectionNum);
				// Update character class difficulty here
				Character->Update();
				// Setup the difficulty within the level
				DifficultyFinializedSetup(ESections::SECTION_01);

				// Destroy the trigger box
				OverlappedActor->Destroy();
			}

			//#####################################################################################################
										// SECTION 2 TRIGGER BOX
			//#####################################################################################################

			// Check if the trigger box is the second one
			else if (OverlappedActor->GetName() == TRIGGERBOX02)
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
				// Save difficulty details onto text file
				Character->m_CharDifficulty->SaveDataToTextFile(m_levelName, m_sectionNum, FString(Character->m_CharDifficulty->GetStrDiff()),
											m_totalTime, m_movementTime, m_inLightTime, m_sectionNum);
				// Update character class difficulty here
				Character->Update();
				// Setup the difficulty within the level
				DifficultyFinializedSetup(ESections::SECTION_02);

				// Destroy the trigger box
				OverlappedActor->Destroy();
			}

			//#####################################################################################################
										// SECTION 3 TRIGGER BOX
			//#####################################################################################################

			// Check if the trigger box is the third one
			else if (OverlappedActor->GetName() == TRIGGERBOX03)
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
				// Save difficulty details onto text file
				Character->m_CharDifficulty->SaveDataToTextFile(m_levelName, m_sectionNum, FString(Character->m_CharDifficulty->GetStrDiff()),
											m_totalTime, m_movementTime, m_inLightTime, m_sectionNum);
				// Update character class difficulty here
				Character->Update();
				// Setup the difficulty within the level
				DifficultyFinializedSetup(ESections::SECTION_03);

				// Destroy the trigger box
				OverlappedActor->Destroy();
			}

			//#####################################################################################################
										// SECTION 4 TRIGGER BOX
			//#####################################################################################################

			// Check if the trigger box is the fourth one
			else if (OverlappedActor->GetName() == TRIGGERBOX04)
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
				// Save difficulty details onto text file
				Character->m_CharDifficulty->SaveDataToTextFile(m_levelName, m_sectionNum, FString(Character->m_CharDifficulty->GetStrDiff()),
											m_totalTime, m_movementTime, m_inLightTime, m_sectionNum);
				// Update character class difficulty here
				Character->Update();
				// Setup the difficulty within the level
				DifficultyFinializedSetup(ESections::SECTION_04);

				// Destroy the trigger box
				OverlappedActor->Destroy();
			}

			//#####################################################################################################
										// SECTION 5 TRIGGER BOX
			//#####################################################################################################

			// Check if the trigger box is the fifth and last one for level 1
			else if (OverlappedActor->GetName() == TRIGGERBOX05)
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
				// Save difficulty details onto text file
				Character->m_CharDifficulty->SaveDataToTextFile(m_levelName, m_sectionNum, FString(Character->m_CharDifficulty->GetStrDiff()),
											m_totalTime, m_movementTime, m_inLightTime, m_sectionNum);
				// Update character class difficulty here
				Character->Update();
				// Setup the difficulty within the level
				DifficultyFinializedSetup(ESections::SECTION_05);

				// Destroy the trigger box
				OverlappedActor->Destroy();
			}
		}

		//############################################################################################################################
													// LEVEL 02 TRIGGER BOXES
		//############################################################################################################################

		else if (m_currentLevel == LEVEL02NAME)
		{
			// Set level name FString (for saving data to text)
			m_levelName = LEVEL02NAME;

			//#####################################################################################################
										// SECTION 1 TRIGGER BOX
			//#####################################################################################################

			// Check if the trigger box is the first one
			if (OverlappedActor->GetName() == TRIGGERBOX01)
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

				// Setup the difficulty within the level
				DifficultyFinializedSetup(ESections::SECTION_01);
				// Save difficulty details onto text file
				Character->m_CharDifficulty->SaveDataToTextFile(m_levelName, m_sectionNum, FString(Character->m_CharDifficulty->GetStrDiff()),
											m_totalTime, m_movementTime, m_inLightTime, m_sectionNum);
				// Update character class difficulty here
				Character->Update();				

				// Destroy the trigger box
				OverlappedActor->Destroy();
			}

			//#####################################################################################################
										// SECTION 2 TRIGGER BOX
			//#####################################################################################################

			// Check if the trigger box is the first one
			if (OverlappedActor->GetName() == TRIGGERBOX02)
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
				// Save difficulty details onto text file
				Character->m_CharDifficulty->SaveDataToTextFile(m_levelName, m_sectionNum, FString(Character->m_CharDifficulty->GetStrDiff()),
											m_totalTime, m_movementTime, m_inLightTime, m_sectionNum);
				// Update character class difficulty here
				Character->Update();
				// Setup the difficulty within the level
				DifficultyFinializedSetup(ESections::SECTION_02);

				// Destroy the trigger box
				OverlappedActor->Destroy();
			}

			//#####################################################################################################
										// SECTION 3 TRIGGER BOX
			//#####################################################################################################

			// Check if the trigger box is the third one
			if (OverlappedActor->GetName() == TRIGGERBOX03)
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
				// Save difficulty details onto text file
				Character->m_CharDifficulty->SaveDataToTextFile(m_levelName, m_sectionNum, FString(Character->m_CharDifficulty->GetStrDiff()),
											m_totalTime, m_movementTime, m_inLightTime, m_sectionNum);
				// Update character class difficulty here
				Character->Update();
				// Setup the difficulty within the level
				DifficultyFinializedSetup(ESections::SECTION_03);

				// Destroy the trigger box
				OverlappedActor->Destroy();
			}

			//#####################################################################################################
										// SECTION 4 TRIGGER BOX (FINAL)
			//#####################################################################################################

			// Check if the trigger box is the fourth and final one
			if (OverlappedActor->GetName() == TRIGGERBOX04)
			{
				// Get the current seconds spent in level
				m_intSeconds = Gamemode->GetSecondsInt();
				// Set section number FString (for saving data to text)
				m_sectionNum = "04";

				// Set data values to check for difficulty changes
				m_timeChk = 53;						// Check current time against 53
				m_mvmntChk01 = 50;					// First Movement Check against 50
				m_mvmntChk02 = 47;					// Second Movement Check against 47
				m_mvmntChk03 = 49;					// Third Movement Check against 49
				m_mvmntChk04 = 46;					// Fourth Movement Check against 46
				m_mvmntChk05 = (m_intSeconds - 3);	// Fifth Movement Check against (current time - 3)
				m_inLightChk01 = 2;					// First In Light Check against 2
				m_inLightChk02 = 3;					// Second In Light Check against 3
				m_inLightChk03 = 5;					// Third In Light Check against 5
				m_inLightChk04 = 6;					// Fourth In Light Check against 6

				// Shift the difficulty based on data checks
				DifficultyShift(false, true);
				// Save difficulty details onto text file
				Character->m_CharDifficulty->SaveDataToTextFile(m_levelName, m_sectionNum, FString(Character->m_CharDifficulty->GetStrDiff()),
											m_totalTime, m_movementTime, m_inLightTime, m_sectionNum);
				// Update character class difficulty here
				Character->Update();
				// Setup the difficulty within the level
				DifficultyFinializedSetup(ESections::SECTION_04);

				// Destroy the trigger box
				OverlappedActor->Destroy();
			}
		}
	}

	else
	{
		print("ERROR - No level");
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