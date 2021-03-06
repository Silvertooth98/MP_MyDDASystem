#include "DDATriggerCapsule.h"
#include "DrawDebugHelpers.h"
#include "Engine/GameEngine.h"


ADDATriggerCapsule::ADDATriggerCapsule()
{
	OnActorBeginOverlap.AddDynamic(this, &ADDATriggerCapsule::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &ADDATriggerCapsule::OnOverLapEnd);
}

void ADDATriggerCapsule::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	// Link character variable to the character class
	Character = Cast<AMajorProjectCharacter>(GetWorld()->GetFirstPlayerController()->GetCharacter());
}

void ADDATriggerCapsule::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	// Check if the actor overlapping the trigger box is the FirstPersonCharacter
	if (OtherActor && OtherActor != this && OtherActor->GetName() == "FirstPersonCharacter")
	{
		Character->InLightTimer();
	}
}

void ADDATriggerCapsule::OnOverLapEnd(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor && OtherActor != this && OtherActor->GetName() == "FirstPersonCharacter")
	{
		Character->PauseInLightTimer();
	}
}