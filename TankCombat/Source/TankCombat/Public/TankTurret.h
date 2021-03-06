// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class TANKCOMBAT_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	void RotateTurret(float RelativeSpeed);

private:
	
	UPROPERTY(EditDefaultsOnly)
	float MaxDeegreesPerSecond = 15.f;
};
