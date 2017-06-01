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

    UAimingComponent* AimingComponent = nullptr;
	UPROPERTY(EditDefaultsOnly, Category = "Gameplay")
	float AcceptanceRadius = 150000.f; // the tank wont try to reach us inside of this radius

};
