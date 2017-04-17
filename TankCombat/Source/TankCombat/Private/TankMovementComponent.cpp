// Fill out your copyright notice in the Description page of Project Settings.

#include "TankCombat.h"
#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::Initialize(UTankTrack* RightTankTrackToSet, UTankTrack* LeftTankTrackToSet)
{
	LeftTankTrack = LeftTankTrackToSet;
	RightTankTrack = RightTankTrackToSet;
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{

    //we are moving the tank from the result of cosines parallelism between the tank forward direction and AI forward direction
    //both vector values have to be normalized to get total result of x,y and of max value 1
    //Dot product calculates this value by default for us and return a float between -1 and 1;
    float DotVectorDirection = FVector::DotProduct(GetOwner()->GetActorForwardVector().GetSafeNormal(), MoveVelocity.GetSafeNormal());


    IntendToMoveForward(DotVectorDirection);
    //Cross product calculates the parallelism between the tank direction (local) and the direction that AI intends to go, The result is the vector (odd) and the z value is the rotation that we are looking for.
    FVector CrossVectorRotation = FVector::CrossProduct(GetOwner()->GetActorForwardVector().GetSafeNormal(), MoveVelocity.GetSafeNormal());

    //HINT AI wont rotate to player unless it is is collision with the nav mesh is restarted at the start of play mode
    IntendToTurnRight(CrossVectorRotation.Z);
}
 

void UTankMovementComponent::IntendToMoveForward(float Throw)
{
    if (ensure(RightTankTrack && LeftTankTrack))
    {
        LeftTankTrack->SetThrottle(Throw);
        RightTankTrack->SetThrottle(Throw);
    }
}


void UTankMovementComponent::IntendToTurnRight(float Throw)
{

    if (ensure(RightTankTrack && LeftTankTrack)) 
    { 
	    LeftTankTrack->SetThrottle(Throw);
	    RightTankTrack->SetThrottle(-Throw); 
    }
    
}

