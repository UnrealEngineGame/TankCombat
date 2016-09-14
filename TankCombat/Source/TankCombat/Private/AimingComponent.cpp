// Fill out your copyright notice in the Description page of Project Settings.

#include "TankCombat.h"
#include "TankBarrel.h"
#include "AimingComponent.h"
#include "../Public/AimingComponent.h"


// Sets default values for this component's properties
UAimingComponent::UAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


void UAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	if (!BarrelToSet) { return; }
	Barrel = BarrelToSet;
}


void UAimingComponent::AimAtOpponent(FVector Opponent, float LaunchSpeed)
{
	auto OurTankName = GetOwner()->GetName();
	//FString BarrelLocation = ;

	FVector TossVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	
	if (UGameplayStatics::SuggestProjectileVelocity(
		this, 
		TossVelocity, 
		StartLocation, 
		Opponent, 
		LaunchSpeed, 		
		ESuggestProjVelocityTraceOption::DoNotTrace
		))
	{
		FVector AimDirection = TossVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);	
	}



}

void UAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	FRotator BarrelRotation = Barrel->GetForwardVector().Rotation();
	FRotator AimDirectionRotation = AimDirection.Rotation();
	FRotator BarrelMoveRotation = AimDirectionRotation - BarrelRotation;

	Barrel->ElevateBarrel(5.f);

	//UE_LOG(LogTemp, Warning, TEXT("Barrel is aiming at : %s"), *BarrelMoveRotation.ToString());

}

