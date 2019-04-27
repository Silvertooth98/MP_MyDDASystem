// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "MajorProjectGameMode.h"
#include "MajorProjectCharacter.h"
#include "DDATriggerBox.generated.h"

/**
 * 
 */
UCLASS()
class MAJORPROJECT_API ADDATriggerBox : public ATriggerBox
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	AMajorProjectGameMode* Gamemode;

	UPROPERTY(EditAnywhere)
	AMajorProjectCharacter* Character;
	
protected:

	virtual void BeginPlay() override;

public:

	ADDATriggerBox();

	UFUNCTION()
	void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);
	
	UFUNCTION()
	void OnOverLapEnd(class AActor* OverlappedActor, class AActor* OtherActor);

	UFUNCTION(BlueprintPure, Category = "Trigger Box")
	bool GetEasyDifficulty() { return m_easyDifficulty; }

	UFUNCTION(BlueprintPure, Category = "Trigger Box")
	bool GetMediumDifficulty() { return m_mediumDifficulty; }

	UFUNCTION(BlueprintPure, Category = "Trigger Box")
	bool GetHardDifficulty() { return m_hardDifficulty; }

	UFUNCTION(BlueprintPure, Category = "Trigger Box")
	bool GetDifficultyChange() { return m_setDifficulty; }

protected:

	int m_intSeconds;

	bool m_easyDifficulty;
	bool m_mediumDifficulty;
	bool m_hardDifficulty;
	bool m_setDifficulty;

};