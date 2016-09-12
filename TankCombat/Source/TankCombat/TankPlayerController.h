// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TANKCOMBAT_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:

	virtual void BeginPlay() override; //override is used to get sure that we are overriding the parent's class. virtual that we allow this class to be overwritten within our children.

	virtual void Tick(float DeltaTime);

	ATank* GetControlledTank() const;

	// Start the tank moving the barrel towards to crosshair
	void AimTowardsCrossHair();

	//Return an out parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& HitLocation) const;

	FVector2D GetCrossHairScreenPosition() const;

	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5f;

	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.33333f;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000.f;

	
};
