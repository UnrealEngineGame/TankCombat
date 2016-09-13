// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent)) //ovo omogucava da ju mozemo dodavati iz blueprinta.
class TANKCOMBAT_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:

	void ElevateBarrel(float DeegreesBySecond);	

private:
	UPROPERTY(EditAnywhere)
	float MaxDeegreesPerSecond = 20.f; 

	UPROPERTY(EditAnywhere)
	float  MinElevationPerSecond = 0.f; 

	UPROPERTY(EditAnywhere)
	float MaxElevationPerSecond = 40.f; 
};
