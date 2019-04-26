// Fill out your copyright notice in the Description page of Project Settings.

#define print(text) if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.0, FColor::Green, text)
#define printf(text, fstring) if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.0, FColor::Yellow, FString::Printf(TEXT(text), fstring))

#include "DDATriggerBox.h"
#include "DrawDebugHelpers.h"
#include "Engine/GameEngine.h"

ADDATriggerBox::ADDATriggerBox()
{
	OnActorBeginOverlap.AddDynamic(this, &ADDATriggerBox::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &ADDATriggerBox::OnOverLapEnd);
}

void ADDATriggerBox::BeginPlay()
{
	Super::BeginPlay();

	DrawDebugBox(GetWorld(), GetActorLocation(), GetComponentsBoundingBox().GetExtent(), FColor::Purple, true, 100, 0, 5);
}

void ADDATriggerBox::OnOverlapBegin(AActor * OverlappedActor, AActor * OtherActor)
{
	// Check if the trigger box is the first one
	if (OverlappedActor->GetName() == "SpawnTriggerBox_1")
	{
		// Check if the actor overlapping the trigger box is the FirstPersonCharacter
		if (OtherActor && OtherActor != this && OtherActor->GetName() == "FirstPersonCharacter")
		{
			// Do the checks for the total time and set the difficult etc etc
			// Spawn a certain amount of enemies based on the above

			print("Being Overlap - Spawn Sentries");
			printf("Actor Overlapped = %s", *OverlappedActor->GetName());
			printf("Actor that Overlapped = %s", *OtherActor->GetName());
		}
	}
}

void ADDATriggerBox::OnOverLapEnd(AActor * OverlappedActor, AActor * OtherActor)
{
	if (OtherActor && (OtherActor != this))
	{
		print("End Overlap - Sentries already spawned");
		printf("Actor Left = %s", *OverlappedActor->GetName());
		printf("Actor Overlapped = %s", *OtherActor->GetName());
	}
}