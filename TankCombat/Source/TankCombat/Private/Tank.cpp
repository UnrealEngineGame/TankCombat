// Fill out your copyright notice in the Description page of Project Settings.

#include "TankCombat.h"
#include "Tank.h"
#include "AimingComponent.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "TankMovementComponent.h"
#include "../Public/Tank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
    Super::BeginPlay();

    AimingComponent = FindComponentByClass<UAimingComponent>();
    Barrel = AimingComponent->GetTankBarrel();
}


// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void ATank::AimAt(FVector HitLocation, float LaunchSpeed)
{
    if (!ensure(AimingComponent)) { return; }
	AimingComponent->AimAtOpponent(HitLocation, LaunchSpeed);
}

void ATank::Fire()
{

    if (!ensure(Barrel)) { return; }
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadedTimeInSeconds;

	if (isReloaded)
	{ 
		AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, Barrel->GetSocketLocation(FName("Projectile")), Barrel->GetSocketRotation(FName("Projectile")));
		if (!Projectile) { return; }
		Projectile->LaunchProjectile(LaunchSpeed); 
		LastFireTime = FPlatformTime::Seconds();
	}
	else {
		return;
	}
}

