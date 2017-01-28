// Fill out your copyright notice in the Description page of Project Settings.

#include "TankCombat.h"
#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::Initialise(UTankTrack* RightTankTrackToSet, UTankTrack* LeftTankTrackToSet)
{
	LeftTankTrack = LeftTankTrackToSet;
	RightTankTrack = RightTankTrackToSet;
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
    //we are moving the tank from the result of cosines parallelism between the tank forward direction and AI forward direction
    //both vector values have to be normalized to get total result of x,y and of max value 1
    //Dot product calculates this value by default for us and return a float between -1 - 1;
    float ParallelismCos = FVector::DotProduct(GetOwner()->GetActorForwardVector().GetSafeNormal(), MoveVelocity.GetSafeNormal());

    IntendToMoveForward(ParallelismCos);




}
 

void UTankMovementComponent::IntendToMoveForward(float Throw)
{
	if (!RightTankTrack || !LeftTankTrack) { return; }
	LeftTankTrack->SetThrottle(Throw);
	RightTankTrack->SetThrottle(Throw);
}


void UTankMovementComponent::IntendToTurnRight(float Throw)
{
	if (!RightTankTrack || !LeftTankTrack) { return; }
	LeftTankTrack->SetThrottle(Throw);
	RightTankTrack->SetThrottle(-Throw); 
}

