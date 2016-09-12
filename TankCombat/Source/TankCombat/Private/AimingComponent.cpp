// Fill out your copyright notice in the Description page of Project Settings.

#include "TankCombat.h"
#include "AimingComponent.h"
#include "../Public/AimingComponent.h"


// Sets default values for this component's properties
UAimingComponent::UAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UAimingComponent::SetBarrelReference(UStaticMeshComponent * BarrelToSet)
{
	if (BarrelToSet)
	{
		Barrel = BarrelToSet;
	}
}


// Called every frame
void UAimingComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

void UAimingComponent::AimAt(FVector WordSpaceAim)
{
	auto OurTankName = GetOwner()->GetName();
	//FString BarrelLocation = ;
	UE_LOG(LogTemp, Warning, TEXT("%s aiming at : %s from: %s"), *OurTankName, *WordSpaceAim.ToString(),  *Barrel->GetComponentLocation().ToString());
}

