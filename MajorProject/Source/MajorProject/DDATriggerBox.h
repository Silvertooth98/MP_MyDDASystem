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

	// SECTION 1 SENTRIES
	// Array of type actor for the sentries to delete when in easy mode
	UPROPERTY(EditAnywhere, Category = "Trigger Box")
	TArray<AActor*> m_s1EasyModeSetup;

	// Array of type actor for the sentries to delete when in medium mode
	UPROPERTY(EditAnywhere, Category = "Trigger Box")
	TArray<AActor*> m_s1MediumModeSetup;

	// DEBUGGING * WON'T REMOVE ANY
	// Array of type actor for the sentries to delete when in hard mode
	UPROPERTY(EditAnywhere, Category = "Trigger Box")
	TArray<AActor*> m_s1HardModeSetup;


protected:

	//UPROPERTY(EditAnywhere)
	AMajorProjectGameMode* Gamemode;

	//UPROPERTY(EditAnywhere)
	AMajorProjectCharacter* Character;

	int m_intSeconds;

	bool m_easyDifficulty;
	bool m_mediumDifficulty;
	bool m_hardDifficulty;
	bool m_setDifficulty;

};