// Fill out your copyright notice in the Description page of Project Settings.

#include "TankCombat.h"
#include "TankBarrel.h"

void UTankBarrel::ElevateBarrel(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto ElevationChange = RelativeSpeed * MaxDeegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;

	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevationPerSecond, MaxElevationPerSecond); //works without the float also

	SetRelativeRotation(FRotator(Elevation, 0, 0));
}




