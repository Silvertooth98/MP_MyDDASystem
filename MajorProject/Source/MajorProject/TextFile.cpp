// Fill out your copyright notice in the Description page of Project Settings.

#include "TextFile.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"

bool UTextFile::SaveTxt(FString SaveText, FString FileName)
{
	return FFileHelper::SaveStringToFile(SaveText, *(FPaths::ProjectDir() + FileName)); // , FFileHelper::EEncodingOptions::AutoDetect, &IFileManager::Get(), EFileWrite::FILEWRITE_Append);
}