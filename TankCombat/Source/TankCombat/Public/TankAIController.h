// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"

//Forward declaration
class UAimingComponent;

/**
 * 
 */
UCLASS()
class TANKCOMBAT_API ATankAIController : public AAIController
{
	GENERATED_BODY()

private:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Gameplay")
	ATank* PlayerTank;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Gameplay")
	ATank* AITank;

    UAimingComponent* AimingComponent = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Gameplay")
	float AcceptanceRadius = 150000.f; // the tank wont try to reach us inside of this radius

	/*Ammo count for Ai tanks, set to 1000 by default (infinite)*, this will overwrite the default ammo on the Aiming component*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Gameplay")
	int32 Ammo; 

	bool IsPLayerVisible();

};
