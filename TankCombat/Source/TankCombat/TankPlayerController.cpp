// Fill out your copyright notice in the Description page of Project Settings.

#include "TankCombat.h"
#include "Tank.h"
#include "TankPlayerController.h"
#include "AimingComponent.h"


//on the begging of the play
void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	ATank* CurrentTank = GetControlledTank();

    UE_LOG(LogTemp, Warning, TEXT("Tank is %s"), CurrentTank ? "possed by TankPlayerController" : "not possed by any PlayerController");
    UAimingComponent* AimingComponent = GetControlledTank()->FindComponentByClass<UAimingComponent>();
    if (!AimingComponent)
        UE_LOG(LogTemp, Error, TEXT("Tank player controller could not found the aiming compponent on the begin play"));
    FoundedAimingComponent(AimingComponent);
}

//every frame of the game
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrossHair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	APawn* ControlledTank = GetPawn();
	if (!ControlledTank) { return nullptr; }
	return Cast<ATank>(ControlledTank);
}

void ATankPlayerController::AimTowardsCrossHair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation = FVector(0);
	if (GetSightRayHitLocation(HitLocation)) // we calculating and creating an out parameter for hit location.
		GetControlledTank()->AimAt(HitLocation, GetControlledTank()->LaunchSpeed);
	
}

//Get world location of line trace through cross hair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
 
	FHitResult HitResult;
	if (GetHitResultAtScreenPosition(GetCrossHairScreenPosition(), ECollisionChannel::ECC_WorldStatic, false, HitResult))
		HitLocation = HitResult.ImpactPoint;
	// Draws a red line for debugging purposes
	//DrawDebugLine(GetWorld(), HitResult.TraceStart, HitResult.TraceEnd, FColor::Red);

	return true;
}

FVector2D ATankPlayerController::GetCrossHairScreenPosition() const 
{
	int32 ViewPortSizeX, ViewPortSizeY;
	GetViewportSize(ViewPortSizeX, ViewPortSizeY);	 

	return FVector2D(ViewPortSizeX * CrossHairXLocation, ViewPortSizeY * CrossHairYLocation);
}


