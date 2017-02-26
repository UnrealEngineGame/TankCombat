// Fill out your copyright notice in the Description page of Project Settings.

#include "TankCombat.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "AimingComponent.h"
#include "../Public/AimingComponent.h"
#include "Projectile.h"


// Sets default values for this component's properties
UAimingComponent::UAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


void UAimingComponent::Initialize(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet)
{
    if (!ensure(BarrelToSet && TurretToSet)) { return; }
    Turret = TurretToSet;
    Barrel = BarrelToSet;
}

void UAimingComponent::AimAtOpponent(FVector OpponentLocation)
{
	FVector TossVelocity;	
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	
	if (UGameplayStatics::SuggestProjectileVelocity(
		this, 
		TossVelocity, 
		StartLocation, 
		OpponentLocation, 
		LaunchSpeed, 
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
		))
	{
		FVector AimDirection = TossVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);	
	}
}

void UAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
    if (!ensure(Barrel && Turret)) { return; }

	FRotator BarrelRotation = Barrel->GetForwardVector().Rotation();
	FRotator AimDirectionRotation = AimDirection.Rotation();
	FRotator DeltaRotator = AimDirectionRotation - BarrelRotation;
	
	Barrel->ElevateBarrel(DeltaRotator.Pitch);
	Turret->RotateTurret(DeltaRotator.Yaw);

}

void UAimingComponent::Fire()
{
    if (!ensure(Barrel && ProjectileBlueprint)) { return; }
    bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadedTimeInSeconds;

    if (isReloaded)
    {
        AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, Barrel->GetSocketLocation(FName("Projectile")), Barrel->GetSocketRotation(FName("Projectile")));
        if (!ensure(Projectile)) { return; }
        Projectile->LaunchProjectile(LaunchSpeed);
        LastFireTime = FPlatformTime::Seconds();
    }
    else {
        return;
    }
}

UTankBarrel* UAimingComponent::GetTankBarrel() const
{
    return Barrel;
}




