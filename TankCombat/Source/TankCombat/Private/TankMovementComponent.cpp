// Fill out your copyright notice in the Description page of Project Settings.

#include "TankCombat.h"
#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::Initialise(UTankTrack* RightTankTrackToSet, UTankTrack* LeftTankTrackToSet)
{
	if (!RightTankTrackToSet || !LeftTankTrackToSet) { return; }

	LeftTankTrack = LeftTankTrackToSet;
	RightTankTrack = RightTankTrackToSet;
}

void UTankMovementComponent::IntendToMoveForward(float Throw)
{
	//UE_LOG(LogTemp, Warning, TEXT("RightTrack: %s, LEftTrack: %s"), *RightTankTrack->GetName(), *LeftTankTrack->GetName());
	if (!RightTankTrack || !LeftTankTrack) { return; }
	RightTankTrack->SetThrottle(Throw);
	LeftTankTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendToMoveRight(float Throw)
{
	UE_LOG(LogTemp, Warning, TEXT("Right: %f"), Throw);
	if (!RightTankTrack || !LeftTankTrack) { return; }
	RightTankTrack->SetThrottle(-Throw);
	LeftTankTrack->SetThrottle(Throw);
}
