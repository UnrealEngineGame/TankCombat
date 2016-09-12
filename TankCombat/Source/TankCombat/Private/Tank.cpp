// Fill out your copyright notice in the Description page of Project Settings.

#include "TankCombat.h"
#include "Tank.h"
#include "../Public/Tank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//No need to protect points as added at construction
	//We are initializing component on compile time in the tank blueprint
	AimingComponent = CreateDefaultSubobject<UAimingComponent>(FName("Aiming component"));

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}


void ATank::SetBarrelReference(UStaticMeshComponent * BarrelToSet)
{
	AimingComponent->SetBarrelReference(BarrelToSet);
}

// Called every frame
void ATank::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void ATank::AimAt(FVector HitLocation)
{
	AimingComponent->AimAt(HitLocation);
} 

