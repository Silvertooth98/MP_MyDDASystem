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

	void DifficultyFinializedSetup(bool S1 = false, bool S2 = false, bool S3 = false);

public:

	ADDATriggerBox();

	UFUNCTION()
	void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);
	
	UFUNCTION()
	void OnOverLapEnd(class AActor* OverlappedActor, class AActor* OtherActor);

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
	
	// Array of type actor for the sentries to delete when in easy_01 mode
	UPROPERTY(EditAnywhere, Category = "Trigger Box")
	TArray<AActor*> m_s2EasyMode1Setup;
	// Array of type actor for the sentries to delete when in easy_02 mode
	UPROPERTY(EditAnywhere, Category = "Trigger Box")
	TArray<AActor*> m_s2EasyMode2Setup;

	// Array of type actor for the sentries to delete when in medium_01 mode
	UPROPERTY(EditAnywhere, Category = "Trigger Box")
	TArray<AActor*> m_s2MediumMode1Setup;
	// Array of type actor for the sentries to delete when in medium_02 mode
	UPROPERTY(EditAnywhere, Category = "Trigger Box")
	TArray<AActor*> m_s2MediumMode2Setup;

	// Array of type actor for the sentries to delete when in hard_01 mode
	UPROPERTY(EditAnywhere, Category = "Trigger Box")
	TArray<AActor*> m_s2HardMode1Setup;
	// Array of type actor for the sentries to delete when in hard_02 mode
	UPROPERTY(EditAnywhere, Category = "Trigger Box")
	TArray<AActor*> m_s2HardMode2Setup;

//#####################################################################################################
							// SECTION 3 SENTRIES
//#####################################################################################################

protected:

	//UPROPERTY(EditAnywhere)
	AMajorProjectGameMode* Gamemode;

	//UPROPERTY(EditAnywhere)
	AMajorProjectCharacter* Character;

	EDifficulty m_difficulty;

	int m_intSeconds;

	FString m_lastDifficultySetting;
	bool m_setDifficulty;

};