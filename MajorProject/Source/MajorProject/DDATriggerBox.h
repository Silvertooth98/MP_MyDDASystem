// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "MajorProjectGameInstance.h"
#include "MajorProjectGameMode.h"
#include "MajorProjectCharacter.h"
#include "MyEnums.h"
#include "DDATriggerBox.generated.h"

UCLASS()
class MAJORPROJECT_API ADDATriggerBox : public ATriggerBox
{
	GENERATED_BODY()
	
protected:

	virtual void BeginPlay() override;

	void SetDataChecks(int time = 0, int movement01 = 0, int movement02 = 0, int movement03 = 0, int movement04 = 0,
					   int movement05 = 0, int inLight01 = 0, int inLight02 = 0, int inLight03 = 0, int inLight04 = 0);
	void DifficultyFinializedSetup(ESections section);
	void DifficultyShift(bool IsFirstTB = false);

public:

	ADDATriggerBox();

	UFUNCTION()
	void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);
	
	/*UFUNCTION()
	void OnOverLapEnd(class AActor* OverlappedActor, class AActor* OtherActor);*/

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

	FString m_playerCharName;
	FString m_currentLevel;
	FString m_totalTime;
	FString m_movementTime;
	FString m_inLightTime;
	FString m_levelName;
	FString m_sectionNum;
	FString m_levelDifficulty;

	const FString LEVEL01NAME = "Level_01";
	const FString LEVEL02NAME = "Level_02";
	const FString TRIGGERBOX01 = "DDATriggerBox_01";
	const FString TRIGGERBOX02 = "DDATriggerBox_02";
	const FString TRIGGERBOX03 = "DDATriggerBox_03";
	const FString TRIGGERBOX04 = "DDATriggerBox_04";
	const FString TRIGGERBOX05 = "DDATriggerBox_05";

	int m_intSeconds;

	int m_timeChk;
	int m_mvmntChk01;
	int m_mvmntChk02;
	int m_mvmntChk03;
	int m_mvmntChk04;
	int m_mvmntChk05;
	int m_inLightChk01;
	int m_inLightChk02;
	int m_inLightChk03;
	int m_inLightChk04;

};