// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * Class responble for barrel moving and firing
 */
UCLASS(meta = (BlueprintSpawnableComponent)) //ovo omogucava da ju mozemo dodavati iz blueprinta.
class TANKCOMBAT_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:

	// -1 is max downward speed, and +1 is max movement
	void ElevateBarrel(float RelativeSpeed);	

private:
	UPROPERTY(EditDefaultsOnly)
	float MaxDeegreesPerSecond = 10.f; 

	UPROPERTY(EditDefaultsOnly)
	float  MinElevationPerSecond = 0.f; 

	UPROPERTY(EditDefaultsOnly)
	float MaxElevationPerSecond = 40.f;    
};
