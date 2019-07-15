// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "MajorProjectCharacter.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/InputSettings.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/GameEngine.h"
#include "TimerManager.h"

DEFINE_LOG_CATEGORY_STATIC(LogFPChar, Warning, All);

//////////////////////////////////////////////////////////////////////////
// AMajorProjectCharacter

AMajorProjectCharacter::AMajorProjectCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);

	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->RelativeLocation = FVector(-39.56f, 1.75f, 64.f); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetupAttachment(FirstPersonCameraComponent);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;
	Mesh1P->RelativeRotation = FRotator(1.9f, -19.19f, 5.2f);
	Mesh1P->RelativeLocation = FVector(-0.5f, -4.4f, -155.7f);

	// Create a gun mesh component
	FP_Gun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FP_Gun"));
	FP_Gun->SetOnlyOwnerSee(true);			// only the owning player will see this mesh
	FP_Gun->bCastDynamicShadow = false;
	FP_Gun->CastShadow = false;
	FP_Gun->SetupAttachment(RootComponent);

	FP_MuzzleLocation = CreateDefaultSubobject<USceneComponent>(TEXT("MuzzleLocation"));
	FP_MuzzleLocation->SetupAttachment(FP_Gun);
	FP_MuzzleLocation->SetRelativeLocation(FVector(0.2f, 48.4f, -10.6f));

	// Default offset from the character location for projectiles to spawn
	GunOffset = FVector(100.0f, 0.0f, 10.0f);

	// Set movement time to 0
	m_movementTime = 0;
}

void AMajorProjectCharacter::BeginPlay()
{
	// Call the base class
	Super::BeginPlay();

	//Attach gun mesh component to Skeleton, doing it here because the skeleton is not yet created in the constructor
	FP_Gun->AttachToComponent(Mesh1P, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("GripPoint"));

	// Link gamemode variable to the gamemode
	Gamemode = (AMajorProjectGameMode*)GetWorld()->GetAuthGameMode();

	m_CharDifficulty = new Difficulty();
}

void AMajorProjectCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Check if the player is not moving
	if (GetVelocity().Size() == 0)
	{
		// Check if the movement timer exists
		if (GetWorldTimerManager().TimerExists(m_movementTimer))
		{
			// Pause the movement timer
			GetWorldTimerManager().PauseTimer(m_movementTimer);
		}
	}
}

//////////////////////////////////////////////////////////////////////////
// Input

void AMajorProjectCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);

	// Bind jump events
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	// Bind movement events
	PlayerInputComponent->BindAxis("MoveForward", this, &AMajorProjectCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMajorProjectCharacter::MoveRight);

	// Mouse rotation bindings which provide an absolute delta
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
}

// Set the difficulty to be the same as the difficulty set within the difficulty class
void AMajorProjectCharacter::Update()
{
	switch (m_CharDifficulty->GetStateEDiff())
	{
	case EDifficulty::NONE:
		SetDifficulty(ESetDifficulty::NONE);
		break;
	case EDifficulty::EASY_01:
		SetDifficulty(ESetDifficulty::EASY_01);
		break;
	case EDifficulty::EASY_02:
		SetDifficulty(ESetDifficulty::EASY_02);
		break;
	case EDifficulty::MEDIUM_01:
		SetDifficulty(ESetDifficulty::MEDIUM_01);
		break;
	case EDifficulty::MEDIUM_02:
		SetDifficulty(ESetDifficulty::MEDIUM_02);
		break;
	case EDifficulty::HARD_01:
		SetDifficulty(ESetDifficulty::HARD_01);
		break;
	case EDifficulty::HARD_02:
		SetDifficulty(ESetDifficulty::HARD_02);
		break;
	default:
		break;
	}
}

void AMajorProjectCharacter::MoveForward(float Value)
{
	if (Value != 0.0f && CameraShake != NULL)
	{
		// add movement in that direction
		AddMovementInput(GetActorForwardVector(), Value);
		// Add the camera shake in when player is moving
		GetWorld()->GetFirstPlayerController()->PlayerCameraManager->PlayCameraShake(CameraShake, 1.0f);

		// If the movement timer does not exist
		if (!GetWorldTimerManager().TimerExists(m_movementTimer))
		{
			// Set the movement timer to start. Run the MovementTimer function in 1 second intervals. 
			GetWorldTimerManager().SetTimer(m_movementTimer, this, &AMajorProjectCharacter::MovementTimer, 1.0f, true, 1.0f);
		}
		// If the movement timer does exist
		else
		{
			// Unpause the movement timeer
			GetWorldTimerManager().UnPauseTimer(m_movementTimer);
		}
	}
}

void AMajorProjectCharacter::MoveRight(float Value)
{
	if (Value != 0.0f && CameraShake != NULL)
	{
		// add movement in that direction
		AddMovementInput(GetActorRightVector(), Value);
		// Add the camera shake in when player is moving
		GetWorld()->GetFirstPlayerController()->PlayerCameraManager->PlayCameraShake(CameraShake, 1.0f);

		// If the movement timer does not exist
		if (!GetWorldTimerManager().TimerExists(m_movementTimer))
		{
			// Set the movement timer to start. Run the MovementTimer function in 1 second intervals. 
			GetWorldTimerManager().SetTimer(m_movementTimer, this, &AMajorProjectCharacter::MovementTimer, 1.0f, true, 1.0f);
		}
		// If the movement timer does exist
		else
		{
			// Unpause the movement timeer
			GetWorldTimerManager().UnPauseTimer(m_movementTimer);
		}
	}
}

// DEBUG
void AMajorProjectCharacter::MovementTimer()
{
	if (GEngine)
	{
		// Add 1 to the current movement time integer
		m_movementTime = m_movementTime + 1;
		// Convert int to FString
		FString movementTimeStr = FString::FromInt(m_movementTime);
	}
}

void AMajorProjectCharacter::InLightTimer()
{
	// If the in light timer does not exist
	if (!GetWorldTimerManager().TimerExists(m_inLightTimer))
	{
		// Set the in light timer to start. Run the InLightTimer function in 1 second intervals. 
		GetWorldTimerManager().SetTimer(m_inLightTimer, this, &AMajorProjectCharacter::AddToInLightTimer, 1.0f, true, 1.0f);
	}
	// If the in light timer does exist
	else
	{
		// Unpause the in light timeer
		GetWorldTimerManager().UnPauseTimer(m_inLightTimer);
	}
}

void AMajorProjectCharacter::AddToInLightTimer()
{
	if (GEngine)
	{
		// Add 1 to the current in light time integer
		m_inLightTime = m_inLightTime + 1;
		FString inLightStr = FString::FromInt(m_inLightTime);
	}
}

void AMajorProjectCharacter::PauseInLightTimer()
{
	// Pause the in light timer
	GetWorldTimerManager().PauseTimer(m_inLightTimer);
}

ESetDifficulty AMajorProjectCharacter::SetDifficulty(ESetDifficulty SetDifficulty)
{
	m_setDifficulty = SetDifficulty;

	return m_setDifficulty;
}

AMajorProjectCharacter::~AMajorProjectCharacter()
{
	delete m_CharDifficulty;
}