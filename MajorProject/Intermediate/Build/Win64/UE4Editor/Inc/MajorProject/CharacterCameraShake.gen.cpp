// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MajorProject/CharacterCameraShake.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCharacterCameraShake() {}
// Cross Module References
	MAJORPROJECT_API UClass* Z_Construct_UClass_UCharacterCameraShake_NoRegister();
	MAJORPROJECT_API UClass* Z_Construct_UClass_UCharacterCameraShake();
	ENGINE_API UClass* Z_Construct_UClass_UCameraShake();
	UPackage* Z_Construct_UPackage__Script_MajorProject();
// End Cross Module References
	void UCharacterCameraShake::StaticRegisterNativesUCharacterCameraShake()
	{
	}
	UClass* Z_Construct_UClass_UCharacterCameraShake_NoRegister()
	{
		return UCharacterCameraShake::StaticClass();
	}
	struct Z_Construct_UClass_UCharacterCameraShake_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCharacterCameraShake_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UCameraShake,
		(UObject* (*)())Z_Construct_UPackage__Script_MajorProject,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCharacterCameraShake_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "CharacterCameraShake.h" },
		{ "ModuleRelativePath", "CharacterCameraShake.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCharacterCameraShake_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCharacterCameraShake>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UCharacterCameraShake_Statics::ClassParams = {
		&UCharacterCameraShake::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001010A0u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UCharacterCameraShake_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UCharacterCameraShake_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UCharacterCameraShake()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UCharacterCameraShake_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UCharacterCameraShake, 3881932604);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UCharacterCameraShake(Z_Construct_UClass_UCharacterCameraShake, &UCharacterCameraShake::StaticClass, TEXT("/Script/MajorProject"), TEXT("UCharacterCameraShake"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCharacterCameraShake);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
