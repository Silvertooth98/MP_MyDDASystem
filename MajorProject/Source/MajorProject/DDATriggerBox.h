// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "MajorProjectGameInstance.h"
#include "MajorProjectGameMode.h"
#include "MajorProjectCharacter.h"
#include "TextFile.h"
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

	void SaveDataToTextFile(FString Level, FString LevelSection, FString Difficulty,
							FString TotalTime, FString TotalMovementTime,
							FString TotalInLightTime, FString TextFileNumber);

	void DifficultyFinializedSetup(bool S1 = false, bool S2 = false, bool S3 = false, bool S4 = false, bool S5 = false);

public:

	ADDATriggerBox();

	UFUNCTION()
	void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);
	
	UFUNCTION()
	void OnOverLapEnd(class AActor* OverlappedActor, class AActor* OtherActor);

	UFUNCTION(BlueprintPure, Category = "Trigger Box")
	bool GetDifficultyChange() { return m_setDifficulty; }

	FString GetLastDifficulty() { return m_lastDifficultySetting; }

//########################################################################################################################
							// LEVEL 01 SENTRIES
//########################################################################################################################
//#####################################################################################################
							// SECTION 1 SENTRIES
//#####################################################################################################
	
// Array of type actor for the sentries to delete when in easy mode
	UPROPERTY(EditAnywhere, Category = "Level 01 - Section 01 Trigger Box")
	TArray<AActor*> m_L1S1EasyModeSetup;

	// Array of type actor for the sentries to delete when in medium mode
	UPROPERTY(EditAnywhere, Category = "Level 01 - Section 01 Trigger Box")
	TArray<AActor*> m_L1S1MediumModeSetup;

	// DEBUGGING * WON'T REMOVE ANY
	// Array of type actor for the sentries to delete when in hard mode
	UPROPERTY(EditAnywhere, Category = "Level 01 - Section 01 Trigger Box")
	TArray<AActor*> m_L1S1HardModeSetup;

//#####################################################################################################
							// SECTION 2 SENTRIES
//#####################################################################################################
	
	// Array of type actor for the sentries to delete when in easy_01 mode
	UPROPERTY(EditAnywhere, Category = "Level 01 - Section 02 Trigger Box")
	TArray<AActor*> m_L1S2EasyMode1Setup;
	// Array of type actor for the sentries to delete when in easy_02 mode
	UPROPERTY(EditAnywhere, Category = "Level 01 - Section 02 Trigger Box")
	TArray<AActor*> m_L1S2EasyMode2Setup;

	// Array of type actor for the sentries to delete when in medium_01 mode
	UPROPERTY(EditAnywhere, Category = "Level 01 - Section 02 Trigger Box")
	TArray<AActor*> m_L1S2MediumMode1Setup;
	// Array of type actor for the sentries to delete when in medium_02 mode
	UPROPERTY(EditAnywhere, Category = "Level 01 - Section 02 Trigger Box")
	TArray<AActor*> m_L1S2MediumMode2Setup;

	// Array of type actor for the sentries to delete when in hard_01 mode
	UPROPERTY(EditAnywhere, Category = "Level 01 - Section 02 Trigger Box")
	TArray<AActor*> m_L1S2HardMode1Setup;
	// Array of type actor for the sentries to delete when in hard_02 mode
	UPROPERTY(EditAnywhere, Category = "Level 01 - Section 02 Trigger Box")
	TArray<AActor*> m_L1S2HardMode2Setup;

//#####################################################################################################
							// SECTION 3 SENTRIES
//#####################################################################################################

	// Array of type actor for the sentries to delete when in easy_01 mode
	UPROPERTY(EditAnywhere, Category = "Level 01 - Section 03 Trigger Box")
	TArray<AActor*> m_L1S3EasyMode1Setup;
	// Array of type actor for the sentries to delete when in easy_02 mode
	UPROPERTY(EditAnywhere, Category = "Level 01 - Section 03 Trigger Box")
	TArray<AActor*> m_L1S3EasyMode2Setup;

	// Array of type actor for the sentries to delete when in medium_01 mode
	UPROPERTY(EditAnywhere, Category = "Level 01 - Section 03 Trigger Box")
	TArray<AActor*> m_L1S3MediumMode1Setup;
	// Array of type actor for the sentries to delete when in medium_02 mode
	UPROPERTY(EditAnywhere, Category = "Level 01 - Section 03 Trigger Box")
	TArray<AActor*> m_L1S3MediumMode2Setup;

	// Array of type actor for the sentries to delete when in hard_01 mode
	UPROPERTY(EditAnywhere, Category = "Level 01 - Section 03 Trigger Box")
	TArray<AActor*> m_L1S3HardMode1Setup;
	// Array of type actor for the sentries to delete when in hard_02 mode
	UPROPERTY(EditAnywhere, Category = "Level 01 - Section 03 Trigger Box")
	TArray<AActor*> m_L1S3HardMode2Setup;

//#####################################################################################################
							// SECTION 4 SENTRIES
//#####################################################################################################

	// Array of type actor for the sentries to delete when in easy_01 mode
	UPROPERTY(EditAnywhere, Category = "Level 01 - Section 04 Trigger Box")
	TArray<AActor*> m_L1S4EasyMode1Setup;
	// Array of type actor for the sentries to delete when in easy_02 mode
	UPROPERTY(EditAnywhere, Category = "Level 01 - Section 04 Trigger Box")
	TArray<AActor*> m_L1S4EasyMode2Setup;

	// Array of type actor for the sentries to delete when in medium_01 mode
	UPROPERTY(EditAnywhere, Category = "Level 01 - Section 04 Trigger Box")
	TArray<AActor*> m_L1S4MediumMode1Setup;
	// Array of type actor for the sentries to delete when in medium_02 mode
	UPROPERTY(EditAnywhere, Category = "Level 01 - Section 04 Trigger Box")
	TArray<AActor*> m_L1S4MediumMode2Setup;

	// Array of type actor for the sentries to delete when in hard_01 mode
	UPROPERTY(EditAnywhere, Category = "Level 01 - Section 04 Trigger Box")
	TArray<AActor*> m_L1S4HardMode1Setup;
	// Array of type actor for the sentries to delete when in hard_02 mode
	UPROPERTY(EditAnywhere, Category = "Level 01 - Section 04 Trigger Box")
	TArray<AActor*> m_L1S4HardMode2Setup;

//########################################################################################################################
							// LEVEL 02 SENTRIES
//########################################################################################################################
//#####################################################################################################
							// SECTION 1 SENTRIES
//#####################################################################################################

	// Array of type actor for the sentries to delete when in easy mode
	UPROPERTY(EditAnywhere, Category = "Level 02 - Section 01 Trigger Box")
	TArray<AActor*> m_L2S1EasyModeSetup;

	// Array of type actor for the sentries to delete when in medium mode
	UPROPERTY(EditAnywhere, Category = "Level 02 - Section 01 Trigger Box")
	TArray<AActor*> m_L2S1MediumModeSetup;

	// Array of type actor for the sentries to delete when in hard mode
	UPROPERTY(EditAnywhere, Category = "Level 02 - Section 01 Trigger Box")
	TArray<AActor*> m_L2S1HardModeSetup;

//#####################################################################################################
							// SECTION 2 SENTRIES
//#####################################################################################################

	// Array of type actor for the sentries to delete when in easy_01 mode
	UPROPERTY(EditAnywhere, Category = "Level 02 - Section 02 Trigger Box")
	TArray<AActor*> m_L2S2EasyMode1Setup;
	// Array of type actor for the sentries to delete when in easy_02 mode
	UPROPERTY(EditAnywhere, Category = "Level 02 - Section 02 Trigger Box")
	TArray<AActor*> m_L2S2EasyMode2Setup;

	// Array of type actor for the sentries to delete when in medium_01 mode
	UPROPERTY(EditAnywhere, Category = "Level 02 - Section 02 Trigger Box")
	TArray<AActor*> m_L2S2MediumMode1Setup;
	// Array of type actor for the sentries to delete when in medium_02 mode
	UPROPERTY(EditAnywhere, Category = "Level 02 - Section 02 Trigger Box")
	TArray<AActor*> m_L2S2MediumMode2Setup;

	// Array of type actor for the sentries to delete when in hard_01 mode
	UPROPERTY(EditAnywhere, Category = "Level 02 - Section 02 Trigger Box")
	TArray<AActor*> m_L2S2HardMode1Setup;
	// Array of type actor for the sentries to delete when in hard_02 mode
	UPROPERTY(EditAnywhere, Category = "Level 02 - Section 02 Trigger Box")
	TArray<AActor*> m_L2S2HardMode2Setup;

//#####################################################################################################
							// SECTION 3 SENTRIES
//#####################################################################################################

	// Array of type actor for the sentries to delete when in easy_01 mode
	UPROPERTY(EditAnywhere, Category = "Level 02 - Section 03 Trigger Box")
	TArray<AActor*> m_L2S3EasyMode1Setup;
	// Array of type actor for the sentries to delete when in easy_02 mode
	UPROPERTY(EditAnywhere, Category = "Level 02 - Section 03 Trigger Box")
	TArray<AActor*> m_L2S3EasyMode2Setup;

	// Array of type actor for the sentries to delete when in medium_01 mode
	UPROPERTY(EditAnywhere, Category = "Level 02 - Section 03 Trigger Box")
	TArray<AActor*> m_L2S3MediumMode1Setup;
	// Array of type actor for the sentries to delete when in medium_02 mode
	UPROPERTY(EditAnywhere, Category = "Level 02 - Section 03 Trigger Box")
	TArray<AActor*> m_L2S3MediumMode2Setup;

	// Array of type actor for the sentries to delete when in hard_01 mode
	UPROPERTY(EditAnywhere, Category = "Level 02 - Section 03 Trigger Box")
	TArray<AActor*> m_L2S3HardMode1Setup;
	// Array of type actor for the sentries to delete when in hard_02 mode
	UPROPERTY(EditAnywhere, Category = "Level 02 - Section 03 Trigger Box")
	TArray<AActor*> m_L2S3HardMode2Setup;

protected:

	UMajorProjectGameInstance* GameInstance;

	AMajorProjectGameMode* Gamemode;

	AMajorProjectCharacter* Character;

	UTextFile* m_textFile;

	EDifficulty m_difficulty;

	FString m_playerCharacterName;
	FString m_currentLevel;
	FString m_totalTime;
	FString m_movementTime;
	FString m_inLightTime;

	int m_intSeconds;

	// Level 01 Section 01 const variables to replace magic numbers
	/*const int m_L1S1SecondsCheck = 5;
	const int m_L1S1EasyMovementCheck = 5;
	const int m_L1S1MediumMovementCheck01 = 3;
	const int m_L1S1MediumMovementCheck02 = 5;
	const int m_L1S1HardMovementCheck = 2;*/
	
	FString m_lastDifficultySetting;
	bool m_setDifficulty;

};