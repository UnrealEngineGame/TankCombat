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
	PrimaryComponentTick.bCanEverTick = true;
    PrimaryComponentTick.bStartWithTickEnabled = true;

	// ...
}


void UAimingComponent::Initialize(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet)
{
    if (!ensure(BarrelToSet && TurretToSet)) { return; }
    Turret = TurretToSet;
    Barrel = BarrelToSet;
}

void UAimingComponent::BeginPlay()
{
    //First fire after initial load
    FiringState = EFiringStatus::Reloading;
    LastFireTime = GetWorld()->GetTimeSeconds();
}

void UAimingComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
    if ((GetWorld()->GetTimeSeconds() - LastFireTime) > ReloadedTimeInSeconds)
    {
        IsBarrelStatic() ? FiringState = EFiringStatus::Locked : FiringState = EFiringStatus::Aiming;
    }
    else
    {
        FiringState = EFiringStatus::Reloading;
    }
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
		AimDirection = TossVelocity.GetSafeNormal();
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
    if (FiringState != EFiringStatus::Reloading)
    {
        if (!ensure(Barrel)) { return; }
        if (!ensure(ProjectileBlueprint)) { return; }
        AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, Barrel->GetSocketLocation(FName("Projectile")), Barrel->GetSocketRotation(FName("Projectile")));
        if (!ensure(Projectile)) { return; }
        Projectile->LaunchProjectile(LaunchSpeed);
        LastFireTime = GetWorld()->GetTimeSeconds();
    }
}

UTankBarrel* UAimingComponent::GetTankBarrel() const
{
    return Barrel;
}

bool UAimingComponent::IsBarrelStatic()
{
    if (!ensure(Barrel)) { return false; }
    return Barrel->GetForwardVector().Equals(AimDirection, 0.01f);
}




