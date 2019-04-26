// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MAJORPROJECT_MajorProjectCharacter_generated_h
#error "MajorProjectCharacter.generated.h already included, missing '#pragma once' in MajorProjectCharacter.h"
#endif
#define MAJORPROJECT_MajorProjectCharacter_generated_h

#define MajorProject_Source_MajorProject_MajorProjectCharacter_h_15_RPC_WRAPPERS
#define MajorProject_Source_MajorProject_MajorProjectCharacter_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define MajorProject_Source_MajorProject_MajorProjectCharacter_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMajorProjectCharacter(); \
	friend struct Z_Construct_UClass_AMajorProjectCharacter_Statics; \
public: \
	DECLARE_CLASS(AMajorProjectCharacter, ACharacter, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MajorProject"), NO_API) \
	DECLARE_SERIALIZER(AMajorProjectCharacter)


#define MajorProject_Source_MajorProject_MajorProjectCharacter_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAMajorProjectCharacter(); \
	friend struct Z_Construct_UClass_AMajorProjectCharacter_Statics; \
public: \
	DECLARE_CLASS(AMajorProjectCharacter, ACharacter, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MajorProject"), NO_API) \
	DECLARE_SERIALIZER(AMajorProjectCharacter)


#define MajorProject_Source_MajorProject_MajorProjectCharacter_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMajorProjectCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMajorProjectCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMajorProjectCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMajorProjectCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMajorProjectCharacter(AMajorProjectCharacter&&); \
	NO_API AMajorProjectCharacter(const AMajorProjectCharacter&); \
public:


#define MajorProject_Source_MajorProject_MajorProjectCharacter_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMajorProjectCharacter(AMajorProjectCharacter&&); \
	NO_API AMajorProjectCharacter(const AMajorProjectCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMajorProjectCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMajorProjectCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMajorProjectCharacter)


#define MajorProject_Source_MajorProject_MajorProjectCharacter_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__Mesh1P() { return STRUCT_OFFSET(AMajorProjectCharacter, Mesh1P); } \
	FORCEINLINE static uint32 __PPO__FP_Gun() { return STRUCT_OFFSET(AMajorProjectCharacter, FP_Gun); } \
	FORCEINLINE static uint32 __PPO__FP_MuzzleLocation() { return STRUCT_OFFSET(AMajorProjectCharacter, FP_MuzzleLocation); } \
	FORCEINLINE static uint32 __PPO__FirstPersonCameraComponent() { return STRUCT_OFFSET(AMajorProjectCharacter, FirstPersonCameraComponent); } \
	FORCEINLINE static uint32 __PPO__R_MotionController() { return STRUCT_OFFSET(AMajorProjectCharacter, R_MotionController); } \
	FORCEINLINE static uint32 __PPO__L_MotionController() { return STRUCT_OFFSET(AMajorProjectCharacter, L_MotionController); } \
	FORCEINLINE static uint32 __PPO__CameraShake() { return STRUCT_OFFSET(AMajorProjectCharacter, CameraShake); }


#define MajorProject_Source_MajorProject_MajorProjectCharacter_h_12_PROLOG
#define MajorProject_Source_MajorProject_MajorProjectCharacter_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MajorProject_Source_MajorProject_MajorProjectCharacter_h_15_PRIVATE_PROPERTY_OFFSET \
	MajorProject_Source_MajorProject_MajorProjectCharacter_h_15_RPC_WRAPPERS \
	MajorProject_Source_MajorProject_MajorProjectCharacter_h_15_INCLASS \
	MajorProject_Source_MajorProject_MajorProjectCharacter_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define MajorProject_Source_MajorProject_MajorProjectCharacter_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MajorProject_Source_MajorProject_MajorProjectCharacter_h_15_PRIVATE_PROPERTY_OFFSET \
	MajorProject_Source_MajorProject_MajorProjectCharacter_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	MajorProject_Source_MajorProject_MajorProjectCharacter_h_15_INCLASS_NO_PURE_DECLS \
	MajorProject_Source_MajorProject_MajorProjectCharacter_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID MajorProject_Source_MajorProject_MajorProjectCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
