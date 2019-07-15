#include "TextFile.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"

bool UTextFile::SaveTxt(FString SaveText, FString FileName)
{
	return FFileHelper::SaveStringToFile(SaveText, *(FPaths::ProjectDir() + FileName));
}