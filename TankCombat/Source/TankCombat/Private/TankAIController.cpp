// Fill out your copyright notice in the Description page of Project Settings.

#include "TankCombat.h"
#include "Tank.h"
#include "../Public/TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ATank* PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	ATank* AITank = Cast<ATank>(GetPawn());

	if (PlayerTank && AITank)
	{
        MoveToActor(PlayerTank, 3000.f);

		//AimTowardsPlayer;
		AITank->AimAt(PlayerTank->GetActorLocation(), AITank->LaunchSpeed);
		AITank->Fire();
	}
}





