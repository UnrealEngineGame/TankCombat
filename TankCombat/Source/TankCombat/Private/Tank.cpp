// Fill out your copyright notice in the Description page of Project Settings.

#include "TankCombat.h"
#include "Tank.h"
#include "AimingComponent.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "../Public/Tank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//No need to protect points as added at construction
	//We are initializing component on compile time in the tank blueprint
	AimingComponent = CreateDefaultSubobject<UAimingComponent>(FName("Aiming component"));

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();	
}


void ATank::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	AimingComponent->SetBarrelReference(BarrelToSet);	
	Barrel = BarrelToSet;
}

void ATank::SetTurretReference(UTankTurret * TurretToSet)
{
	AimingComponent->SetTurretReference(TurretToSet);
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void ATank::AimAt(FVector HitLocation, float LaunchSpeed)
{
	AimingComponent->AimAtOpponent(HitLocation, LaunchSpeed);
}

float ATank::GetLaunchSpeed()
{
	return LaunchSpeed;
}

void ATank::Fire()
{
	UE_LOG(LogTemp, Warning, TEXT("Firing"));
	if (!Barrel) { return; }

	FVector Lokacija = Barrel->GetSocketLocation(FName("Projectile"));
	GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, Barrel->GetSocketLocation(FName("Projectile")), Barrel->GetSocketRotation(FName("Projectile")));
}

