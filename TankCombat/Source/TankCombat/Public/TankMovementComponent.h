// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTrack;

/**
 * Is responsible for all the movement of the tank. AI and the player.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TANKCOMBAT_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = Setup)
	void Initialize(UTankTrack* RightTankTrackToSet, UTankTrack* LeftTankTrackToSet);

	UFUNCTION(BlueprintCallable, Category = Input)
	void IntendToMoveForward(float Throw);

	UFUNCTION(BlueprintCallable, Category = Input)
	void IntendToTurnRight(float Throw);

private:

	UTankTrack* RightTankTrack = nullptr;
	UTankTrack* LeftTankTrack = nullptr;

    //Called from the path finding logic by the AI controllers
	void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;    
};
