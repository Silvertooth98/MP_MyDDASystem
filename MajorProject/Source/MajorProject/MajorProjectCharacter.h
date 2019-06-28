// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterCameraShake.h"
#include "MajorProjectGameMode.h"
#include "Difficulty.h"
#include "MyEnums.h"
#include "MajorProjectCharacter.generated.h"

UENUM(BlueprintType)
enum class ESetDifficulty : uint8
{
	NONE		UMETA(DisplayName = "No Set Difficulty"),

	EASY_01		UMETA(DisplayName = "EASY_01"),
	EASY_02 	UMETA(DisplayName = "EASY_02"),

	MEDIUM_01 	UMETA(DisplayName = "MEDIUM_01"),
	MEDIUM_02 	UMETA(DisplayName = "MEDIUM_02"),

	HARD_01 	UMETA(DisplayName = "HARD_01"),
	HARD_02 	UMETA(DisplayName = "HARD_02")
};

UENUM(BlueprintType)
enum class ESection : uint8
{
	SECTION_01	UMETA(DisplayName = "SECTION_01"),
	SECTION_02 	UMETA(DisplayName = "SECTION_02"),
	SECTION_03 	UMETA(DisplayName = "SECTION_03"),
	SECTION_04 	UMETA(DisplayName = "SECTION_04"),
	SECTION_05 	UMETA(DisplayName = "SECTION_05")
};

class UInputComponent;

UCLASS(config=Game)
class AMajorProjectCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Pawn mesh: 1st person view (arms; seen only by self) */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	class USkeletalMeshComponent* Mesh1P;

	/** Gun mesh: 1st person view (seen only by self) */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	class USkeletalMeshComponent* FP_Gun;

	/** Location on gun mesh where projectiles should spawn. */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	class USceneComponent* FP_MuzzleLocation;

	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FirstPersonCameraComponent;

	// CameraShake subclass variable
	UPROPERTY(EditAnywhere)
	TSubclassOf<UCameraShake> CameraShake;

	// Gamemode class pointer variable
	UPROPERTY(EditAnywhere)
	AMajorProjectGameMode* Gamemode;	

public:
	AMajorProjectCharacter();
	~AMajorProjectCharacter();

	/** Handles updating the difficulty enum within this class */
	void Update();

	// Difficulty class pointer variable
	Difficulty* m_CharDifficulty;

	// FString variable for the player's character name to check when entering trigger boxes
	UPROPERTY(EditAnywhere, Category = "Character Name")
	FString PlayerCharacterName;

	// Getter for the total movement time
	int GetTotalMovementTime() { return m_movementTime; }
	
	// Getter for the total in light time
	int GetTotalInLightTime() { return m_inLightTime; }

	/** Handles the creation/unpausing of the in the light timer */
	void InLightTimer();

	/** Handles the timer for the player being in the light */
	void AddToInLightTimer();

	/** Handles the pausing for the light timer */
	void PauseInLightTimer();

	// Setter - sets the difficulty using the ESetDifficulty enum
	ESetDifficulty SetDifficulty(ESetDifficulty SetDifficulty);

	// Getter - gets the difficulty set within the ESetDifficulty enum
	UFUNCTION(BlueprintCallable, category = "DifficultyEnum")
	ESetDifficulty GetSetDifficulty() { return m_setDifficulty; }

	// ESetDifficulty enum variable
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "DifficultyEnum")
	ESetDifficulty m_setDifficulty = ESetDifficulty::NONE;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "SectionEnum")
	ESection m_section = ESection::SECTION_01;

	// Level Section Booleans
	UPROPERTY(BlueprintReadWrite, category = "Level Sections")
	bool m_section01 = false;									// Boolean for first section
	UPROPERTY(BlueprintReadWrite, category = "Level Sections")
	bool m_section02 = false;									// Boolean for second section
	UPROPERTY(BlueprintReadWrite, category = "Level Sections")
	bool m_section03 = false;									// Boolean for third section
	UPROPERTY(BlueprintReadWrite, category = "Level Sections")
	bool m_section04 = false;									// Boolean for fourth section
	UPROPERTY(BlueprintReadWrite, category = "Level Sections")
	bool m_section05 = false;									// Boolean for fifth section

	// Gun muzzle's offset from the characters location
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	FVector GunOffset;

protected:
	virtual void BeginPlay();

	virtual void Tick(float DeltaTime) override;

	int m_movementTime;
	int m_intSeconds;
	float m_fltSeconds;
	FTimerHandle m_movementTimer;

	int m_inLightTime;
	FTimerHandle m_inLightTimer;

	/** Handles moving forward/backward */
	void MoveForward(float Val);

	/** Handles stafing movement, left and right */
	void MoveRight(float Val);

	/** Handles the timer for the movement */
	void MovementTimer();

	// USED FOR DEBUGGING
	/** Handles displaying total time */
	void DisplayTotalTime();

	// APawn interface
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;
	// End of APawn interface

public:
	/** Returns Mesh1P subobject **/
	FORCEINLINE class USkeletalMeshComponent* GetMesh1P() const { return Mesh1P; }
	/** Returns FirstPersonCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }

};