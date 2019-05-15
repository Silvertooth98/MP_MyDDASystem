// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "TextFile.generated.h"

/**
 * 
 */
UCLASS()
class MAJORPROJECT_API UTextFile : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	//UFUNCTION(BlueprintCallable, Category = "TextFile")
	static bool SaveTxt(FString SaveText, FString FileName);
	
};
