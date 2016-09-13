// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "AimingComponent.generated.h"

//Forward declaration
class UTankBarrel; 

//Holds all the properties for aiaming to an opponent
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANKCOMBAT_API UAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAimingComponent();

	//setting the barrel for the tank
	void SetBarrelReference(UTankBarrel* BarrelToSet);
	
	//Choose what to aim
	virtual void AimAtOpponent(FVector Opponent, float LaunchSpeed);

	//move the barrel toward aiming location
	void MoveBarrelTowards(FVector AimDirection);

private:

	UTankBarrel* Barrel = nullptr;

};
