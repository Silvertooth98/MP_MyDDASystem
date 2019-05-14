// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MajorProjectGameInstance.generated.h"

UENUM(BlueprintType)
enum class EFinalDifficulty : uint8
{
	NONE		UMETA(DisplayName = "No Set Difficulty"),

	EASY_01		UMETA(DisplayName = "EASY_01"),
	EASY_02		UMETA(DisplayName = "EASY_02"),

	MEDIUM_01	UMETA(DisplayName = "MEDIUM_01"),
	MEDIUM_02	UMETA(DisplayName = "MEDIUM_02"),

	HARD_01		UMETA(DisplayName = "HARD_01"),
	HARD_02		UMETA(DisplayName = "HARD_02")
};

UCLASS()
class MAJORPROJECT_API UMajorProjectGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:

	EFinalDifficulty SetDifficulty(EFinalDifficulty difficulty);

	UFUNCTION(BlueprintCallable, Category = "Game Instance Difficulty")
	EFinalDifficulty GetDifficulty() { return m_finalDifficulty; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "DifficultyEnum")
	EFinalDifficulty m_finalDifficulty = EFinalDifficulty::NONE;
	
};
