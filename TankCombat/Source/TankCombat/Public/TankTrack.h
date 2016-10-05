// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * Tank track is used to set maximum driving force and to apply forces to the tank.
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class TANKCOMBAT_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
private:

public:
	UFUNCTION(BlueprintCallable, Category = Input)
		void SetThrottle(float Throttle);

	UPROPERTY(EditDefaultsOnly, Category = Input)
		float TrackMaxDrivingForce = 400000; //Assume 40 tonne tank, and 1g force (10ms2)

	
};
