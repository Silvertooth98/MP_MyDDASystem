// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterCameraShake.h"

UCharacterCameraShake::UCharacterCameraShake()
{
	OscillationDuration = 1.0f;
	OscillationBlendInTime = 0.2f;
	OscillationBlendOutTime = 0.2f;

	RotOscillation.Pitch.Amplitude = 0.25f;
	RotOscillation.Pitch.Frequency = 1.0f;

	RotOscillation.Yaw.Amplitude = 0.0f;
	RotOscillation.Yaw.Frequency = 0.5f;

	RotOscillation.Roll.Amplitude = 0.25f;
	RotOscillation.Roll.Frequency = 0.5f;

	LocOscillation.Z.Amplitude = 0.5f;
	LocOscillation.Z.Frequency = 1.0f;
}