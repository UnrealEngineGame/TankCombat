// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

//Forward declaration
class UAimingComponent;
/**
 * Class responsible for player movement (initialized in a TankCombat game mode)
 */
UCLASS()
class TANKCOMBAT_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	virtual void BeginPlay() override; //override is used to get sure that we are overriding the parent's class. virtual that we allow this class to be overwritten within our children.

	virtual void Tick(float DeltaTime);

protected:

    UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
    void OnFoundedAimingComponent(UAimingComponent* AimingComponent);

    UAimingComponent* AimingComponent = nullptr;

private:

	// Start the tank moving the barrel towards to crosshair
    UFUNCTION(BlueprintCallable, Category = "Aiming")
	void AimTowardsCrossHair();

	//Return an out parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& HitLocation) const;

	FVector2D GetCrossHairScreenPosition() const;

	UPROPERTY(EditDefaultsOnly)
	float CrossHairXLocation = 0.5f;

	UPROPERTY(EditDefaultsOnly)
	float CrossHairYLocation = 0.33333f; 

	

	
};
