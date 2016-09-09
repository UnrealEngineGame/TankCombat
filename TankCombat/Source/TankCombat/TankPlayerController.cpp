// Fill out your copyright notice in the Description page of Project Settings.

#include "TankCombat.h"
#include "TankPlayerController.h"


//on the beggining of the play
void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto CurrentTank = GetControlledTank();
	if (!CurrentTank)
	{
		UE_LOG(LogTemp, Error, TEXT("TankPlayerController not possesing any tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TankPlayerController is possesing: %s"), *CurrentTank->GetName());
	}

	//(!CurrentTank) ? UE_LOG(LogTemp, Error, TEXT("TankPlayerController not possesing any tank")) : UE_LOG(LogTemp, Warning, TEXT("TankPlayerController is possesing: %s"), *CurrentTank->GetName());
}

//every frame of the game
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrossHair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrossHair()
{
	if (!GetControlledTank()) { return;  }

	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation)) // we calculating and creating an out parameter for hit location.
	{
		//UE_LOG(LogTemp, Warning, TEXT("TankPlayerController is possesing: %s"), *HitLocation.ToString());
	}	

	/*FHitResult HitResult;
	FVector ViewLocation;
	FRotator ViewRotation;

	float Reach = 200.f;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT ViewLocation, OUT ViewRotation);

	FVector EndLocation = ViewLocation + ViewRotation.Vector()*Reach;

	GetWorld()->LineTraceSingleByChannel(OUT HitResult, ViewLocation, EndLocation, ECC_WorldStatic, FCollisionQueryParams(true));
	DrawDebugLine(GetWorld(), ViewLocation, EndLocation, FColor(255, 0, 0), false, 0.f, 0.f, 10.f);*/
}

//Get world location of line trace through cross hair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
 
	int32 ViewPortSizeX, ViewPortSizeY;
	GetViewportSize(ViewPortSizeX, ViewPortSizeY);

	auto CrossHairScreenLocation = FVector2D(ViewPortSizeX * CrossHairXLocation, ViewPortSizeY * CrossHairYLocation);

	UE_LOG(LogTemp, Warning, TEXT("Screen ocation of crosshair is : %s"), *CrossHairScreenLocation.ToString());


	return true;
}

