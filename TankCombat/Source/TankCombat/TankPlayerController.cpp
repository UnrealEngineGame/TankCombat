// Fill out your copyright notice in the Description page of Project Settings.

#include "TankCombat.h"
#include "TankPlayerController.h"
#include "AimingComponent.h"
#include "Tank.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

    UE_LOG(LogTemp, Warning, TEXT("Tank is %s"), GetPawn() ? *FString("possed by TankPlayerController") : *FString("not possed by any PlayerController"));
    AimingComponent = GetPawn()->FindComponentByClass<UAimingComponent>();
    if (!ensure(AimingComponent))
        UE_LOG(LogTemp, Error, TEXT("Tank player controller could not found the aiming compponent on the begin play"));
    OnFoundedAimingComponent(AimingComponent);
}


void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    if (ensure(AimingComponent))
	    AimTowardsCrossHair();
}

void ATankPlayerController::AimTowardsCrossHair()
{
	FVector HitLocation = FVector(0);
    if (GetSightRayHitLocation(HitLocation))
        AimingComponent->AimAtOpponent(HitLocation);	
}

//Get world location of line trace through cross hair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	FHitResult HitResult;
    if (GetHitResultAtScreenPosition(GetCrossHairScreenPosition(), ECollisionChannel::ECC_WorldStatic, false, HitResult))
    {
		HitLocation = HitResult.ImpactPoint;
        return true;
    }
    else {
        return false;
    }
	// Draws a red line for debugging purposes
	//DrawDebugLine(GetWorld(), HitResult.TraceStart, HitResult.TraceEnd, FColor::Red);
}

FVector2D ATankPlayerController::GetCrossHairScreenPosition() const 
{
	int32 ViewPortSizeX, ViewPortSizeY;
	GetViewportSize(ViewPortSizeX, ViewPortSizeY);	 

	return FVector2D(ViewPortSizeX * CrossHairXLocation, ViewPortSizeY * CrossHairYLocation);
}


