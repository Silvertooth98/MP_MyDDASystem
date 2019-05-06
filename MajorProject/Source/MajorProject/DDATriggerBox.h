// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "MajorProjectGameMode.h"
#include "MajorProjectCharacter.h"
#include "DDATriggerBox.generated.h"

UENUM()
enum class EDifficulty : uint8
{
	EASY_01,
	EASY_02,

	MEDIUM_01,
	MEDIUM_02,

	HARD_01,
	HARD_02
};

UCLASS()
class MAJORPROJECT_API ADDATriggerBox : public ATriggerBox
{
	GENERATED_BODY()
	
protected:

	virtual void BeginPlay() override;

	EDifficulty GetEDifficulty();
	void DifficultyFinializedSetup(bool S1 = false, bool S2 = false, bool S3 = false);

public:

	ADDATriggerBox();

	UFUNCTION()
	void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);
	
	UFUNCTION()
	void OnOverLapEnd(class AActor* OverlappedActor, class AActor* OtherActor);

	UFUNCTION(BlueprintPure, Category = "Trigger Box")
	bool GetEasy1Difficulty() { return m_easy1Difficulty; }			// Getter for starting Easy difficulty
	UFUNCTION(BlueprintPure, Category = "Trigger Box")
	bool GetEasy2Difficulty() { return m_easy2Difficulty; }			// Getter for easier Easy difficulty

	UFUNCTION(BlueprintPure, Category = "Trigger Box")
	bool GetMedium1Difficulty() { return m_medium1Difficulty; }		// Getter for starting Medium difficulty
	UFUNCTION(BlueprintPure, Category = "Trigger Box")
	bool GetMedium2Difficulty() { return m_medium2Difficulty; }		// Getter for harder Medium difficulty

	UFUNCTION(BlueprintPure, Category = "Trigger Box")
	bool GetHard1Difficulty() { return m_hard1Difficulty; }			// Getter for starting Hard difficulty
	UFUNCTION(BlueprintPure, Category = "Trigger Box")
	bool GetHard2Difficulty() { return m_hard2Difficulty; }			// Getter for harder Hard difficulty

	UFUNCTION(BlueprintPure, Category = "Trigger Box")
	bool GetDifficultyChange() { return m_setDifficulty; }

	FString GetLastDifficulty() { return m_lastDifficultySetting; }

//#####################################################################################################
							// SECTION 1 SENTRIES
//#####################################################################################################
	
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

//#####################################################################################################
							// SECTION 2 SENTRIES
//#####################################################################################################
	
// Array of type actor for the sentries to delete when in easy mode
	UPROPERTY(EditAnywhere, Category = "Trigger Box")
	TArray<AActor*> m_s2EasyModeSetup;

	// Array of type actor for the sentries to delete when in medium mode
	UPROPERTY(EditAnywhere, Category = "Trigger Box")
	TArray<AActor*> m_s2MediumModeSetup;

	// DEBUGGING * WON'T REMOVE ANY
	// Array of type actor for the sentries to delete when in hard mode
	UPROPERTY(EditAnywhere, Category = "Trigger Box")
	TArray<AActor*> m_s2HardModeSetup;

protected:

	//UPROPERTY(EditAnywhere)
	AMajorProjectGameMode* Gamemode;

	//UPROPERTY(EditAnywhere)
	AMajorProjectCharacter* Character;

	EDifficulty m_difficulty;

	int m_intSeconds;

	bool m_easy1Difficulty;		// Starting easy difficulty
	bool m_easy2Difficulty;		// Easier easy difficulty

	bool m_medium1Difficulty;	// Starting medium difficulty
	bool m_medium2Difficulty;	// Harder medium difficulty

	bool m_hard1Difficulty;		// Starting hard difficulty
	bool m_hard2Difficulty;		// Harder hard difficulty

	FString m_lastDifficultySetting;
	bool m_setDifficulty;

};