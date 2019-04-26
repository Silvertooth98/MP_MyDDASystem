// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "DDATriggerBox.generated.h"

/**
 * 
 */
UCLASS()
class MAJORPROJECT_API ADDATriggerBox : public ATriggerBox
{
	GENERATED_BODY()
	
protected:

	virtual void BeginPlay() override;

public:

	ADDATriggerBox();

	UFUNCTION()
		void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);

	UFUNCTION()
		void OnOverLapEnd(class AActor* OverlappedActor, class AActor* OtherActor);
};