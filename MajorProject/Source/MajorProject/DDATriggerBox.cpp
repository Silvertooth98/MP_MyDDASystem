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

void ADDATriggerBox::OnOverlapBegin(AActor * OverlappedActor, AActor * OtherActor)
{
	Gamemode->GetElapedTime(true, false);

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
					m_easyDifficulty = true;
					m_mediumDifficulty = false;
					m_hardDifficulty = false;
				}
				// Medium Setting
				// Check if total movement time is equal to 3, 4, or 5
				else if (Character->GetTotalMovementTime() >= 3 && Character->GetTotalMovementTime() <= 5)
				{
					m_easyDifficulty = false;
					m_mediumDifficulty = true;
					m_hardDifficulty = false;
				}
				// Hard Setting
				// Check if total movement time is equal to 0, 1, or 2
				else if (Character->GetTotalMovementTime() <= 2)
				{
					m_easyDifficulty = false;
					m_mediumDifficulty = false;
					m_hardDifficulty = true;
				}
			}
			// If seconds equals less than 5
			else
			{
				// Medium Setting
				// Check if total movement time is equal to the total time spent in the level
				if (Character->GetTotalMovementTime() == m_intSeconds)
				{
					m_easyDifficulty = false;
					m_mediumDifficulty = true;
					m_hardDifficulty = false;
				}
				// Hard Setting
				// Otherwise, set to hard mode
				else
				{
					m_easyDifficulty = false;
					m_mediumDifficulty = false;
					m_hardDifficulty = true;
				}
			}

			// Check if easy difficulty
			if (m_easyDifficulty)
			{
				print("DIFFICULTY - EASY");

				// Step through the array and destroy all the actors
				for (int i = 0; i < m_s1EasyModeSetup.Num(); i++)
				{
					m_s1EasyModeSetup[i]->Destroy();
				}
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
			}

			OverlappedActor->Destroy();

			printf("Actor Overlapped = %s", *OverlappedActor->GetName());
			printf("Actor that Overlapped = %s", *OtherActor->GetName());
			//m_setDifficulty = true;
		}
	}
}

void ADDATriggerBox::OnOverLapEnd(AActor * OverlappedActor, AActor * OtherActor)
{
	if (OtherActor && (OtherActor != this))
	{
		printf("Actor Left = %s", *OverlappedActor->GetName());
		printf("Actor Overlapped = %s", *OtherActor->GetName());
		//m_setDifficulty = false;
	}
}
