// Fill out your copyright notice in the Description page of Project Settings.

#include "TankCombat.h"
#include "TankTurret.h"

void UTankTurret::RotateTurret(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto RotationInWorld = RelativeSpeed * MaxDeegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewRotation = RelativeRotation.Yaw + RotationInWorld;

	SetRelativeRotation(FRotator(0, RawNewRotation, 0));
}




