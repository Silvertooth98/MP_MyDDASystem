// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerCapsule.h"
#include "MajorProjectCharacter.h"
#include "DDATriggerCapsule.generated.h"

/**
 * 
 */
UCLASS()
class MAJORPROJECT_API ADDATriggerCapsule : public ATriggerCapsule
{
	GENERATED_BODY()

public:
	ADDATriggerCapsule();

	UFUNCTION()
	void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);
	
	UFUNCTION()
	void OnOverLapEnd(class AActor* OverlappedActor, class AActor* OtherActor);
	
protected:
	virtual void BeginPlay();

	AMajorProjectCharacter* Character;
};
