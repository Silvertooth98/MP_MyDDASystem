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
	//OnActorEndOverlap.AddDynamic(this, &ADDATriggerBox::OnOverLapEnd);
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

void ADDATriggerBox::SetDataChecks(int time, int movement01, int movement02, int movement03, int movement04,
								   int movement05, int inLight01, int inLight02, int inLight03, int inLight04)
{
	m_timeChk = time;
	m_mvmntChk01 = movement01;
	m_mvmntChk02 = movement02;
	m_mvmntChk03 = movement03;
	m_mvmntChk04 = movement04;
	m_mvmntChk05 = movement05;
	m_inLightChk01 = inLight01;
	m_inLightChk02 = inLight02;
	m_inLightChk03 = inLight03;
	m_inLightChk04 = inLight04;
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
			case EDifficulty::EASY_02:
				// Set the difficulty within the Game Instance Class, for initial difficulty within Level_02
				GameInstance->m_finalDifficulty = EFinalDifficulty::EASY_01;
				break;
				
			case EDifficulty::MEDIUM_01:
			case EDifficulty::MEDIUM_02:
				// Set the difficulty within the Game Instance Class, for initial difficulty within Level_02
				GameInstance->m_finalDifficulty = EFinalDifficulty::MEDIUM_01;
				break;

			case EDifficulty::HARD_01:
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

void ADDATriggerBox::DifficultyShift(bool IsFirstTB)
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
			// Check if it's not the first trigger box
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

		// Check if it's not the first trigger box
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
				SetDataChecks(5, 5, 3, 4, 2, m_intSeconds);

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
				SetDataChecks(15, 13, 9, 12, 8, (m_intSeconds - 1), 0, 1, 3, 4);

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
				SetDataChecks(25, 20, 17, 19, 16, (m_intSeconds - 2), 1, 2, 5, 6);

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
				SetDataChecks(45, 38, 36, 37, 35, (m_intSeconds - 3), 2, 3, 6, 7);

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
				SetDataChecks(50, 43, 40, 42, 39, (m_intSeconds - 4), 3, 4, 7, 8);

				// Shift the difficulty based on data checks
				DifficultyShift();
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
				SetDataChecks(17, 16, 14, 15, 13, (m_intSeconds - 1), 0, 1, 3, 4);

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
				SetDataChecks(30, 28, 26, 27, 25, (m_intSeconds - 2), 1, 2, 4, 5);

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
				SetDataChecks(53, 50, 47, 49, 46, (m_intSeconds - 3), 2, 3, 5, 6);

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
		}
	}

	else
	{
		print("ERROR - No level");
	}
}

//void ADDATriggerBox::OnOverLapEnd(AActor * OverlappedActor, AActor * OtherActor)
//{
//	// Check if the actor exiting the trigger box is the same as the FString variable holding the character name
//	if (OtherActor && OtherActor != this && OtherActor->GetName() == m_playerCharName)
//	{
//		printf("Actor Left = %s", *OverlappedActor->GetName());
//		printf("Actor Overlapped = %s", *OtherActor->GetName());
//	}
//}