// Fill out your copyright notice in the Description page of Project Settings.

#include "TankCombat.h"
#include "Tank.h"
#include "../Public/TankAIController.h"
#include "AimingComponent.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

    AimingComponent = GetPawn()->FindComponentByClass<UAimingComponent>();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ATank* PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	ATank* AITank = Cast<ATank>(GetPawn());

	if (ensure(PlayerTank && AITank))
	{
        MoveToActor(PlayerTank, 3000.f);

        if (ensure(AimingComponent))
        {
            AimingComponent->AimAtOpponent(PlayerTank->GetActorLocation());
            AimingComponent->Fire();
        }
	}
}





