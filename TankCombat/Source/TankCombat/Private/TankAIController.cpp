// Fill out your copyright notice in the Description page of Project Settings.

#include "TankCombat.h"
#include "../Public/TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto CurrentTank = GetControlledTank();
	if (!CurrentTank)
	{
		UE_LOG(LogTemp, Error, TEXT("AIPlayerController not possesing any tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIPlayerController is possesing: %s"), *CurrentTank->GetName());
	}

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Error, TEXT("AIPlayerController can't find player tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIPlayerController: Player controller is %s"), *PlayerTank->GetName());
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}
