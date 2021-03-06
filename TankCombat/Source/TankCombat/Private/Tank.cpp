// Fill out your copyright notice in the Description page of Project Settings.

#include "TankCombat.h"
#include "Tank.h"
#include "../Public/Tank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	VelocityTreshold = 100.f;
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
    Super::BeginPlay();
}

bool ATank::IsMoving()
{
	return this->GetVelocity().SizeSquared() > VelocityTreshold;
}
	



