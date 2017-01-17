// Fill out your copyright notice in the Description page of Project Settings.

#include "TankCombat.h"
#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::Initialise(UTankTrack* RightTankTrackToSet, UTankTrack* LeftTankTrackToSet)
{
	LeftTankTrack = LeftTankTrackToSet;
	RightTankTrack = RightTankTrackToSet;
}

void UTankMovementComponent::IntendToMoveForward(float Throw)
{
	//UE_LOG(LogTemp, Warning, TEXT("RightTrack: %s, LEftTrack: %s"), *RightTankTrack->GetName(), *LeftTankTrack->GetName());
	if (!RightTankTrack || !LeftTankTrack) { return; }
	LeftTankTrack->SetThrottle(Throw);
	RightTankTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendToTurnRight(float Throw)
{
	UE_LOG(LogTemp, Warning, TEXT("Right: %f"), Throw);
	if (!RightTankTrack || !LeftTankTrack) { return; }
	LeftTankTrack->SetThrottle(Throw);
	RightTankTrack->SetThrottle(-Throw); // ovo ne oze da radi ovako jel setuje x na 0 i onda se tenk ne krece
}
