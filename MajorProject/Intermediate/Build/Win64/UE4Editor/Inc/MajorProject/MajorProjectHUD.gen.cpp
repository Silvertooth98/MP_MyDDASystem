// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MajorProject/MajorProjectHUD.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMajorProjectHUD() {}
// Cross Module References
	MAJORPROJECT_API UClass* Z_Construct_UClass_AMajorProjectHUD_NoRegister();
	MAJORPROJECT_API UClass* Z_Construct_UClass_AMajorProjectHUD();
	ENGINE_API UClass* Z_Construct_UClass_AHUD();
	UPackage* Z_Construct_UPackage__Script_MajorProject();
// End Cross Module References
	void AMajorProjectHUD::StaticRegisterNativesAMajorProjectHUD()
	{
	}
	UClass* Z_Construct_UClass_AMajorProjectHUD_NoRegister()
	{
		return AMajorProjectHUD::StaticClass();
	}
	struct Z_Construct_UClass_AMajorProjectHUD_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMajorProjectHUD_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AHUD,
		(UObject* (*)())Z_Construct_UPackage__Script_MajorProject,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMajorProjectHUD_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Rendering Actor Input Replication" },
		{ "IncludePath", "MajorProjectHUD.h" },
		{ "ModuleRelativePath", "MajorProjectHUD.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMajorProjectHUD_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMajorProjectHUD>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMajorProjectHUD_Statics::ClassParams = {
		&AMajorProjectHUD::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x008002ACu,
		nullptr, 0,
		nullptr, 0,
		"Game",
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AMajorProjectHUD_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AMajorProjectHUD_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMajorProjectHUD()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMajorProjectHUD_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMajorProjectHUD, 4137347775);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMajorProjectHUD(Z_Construct_UClass_AMajorProjectHUD, &AMajorProjectHUD::StaticClass, TEXT("/Script/MajorProject"), TEXT("AMajorProjectHUD"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMajorProjectHUD);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
