// Fill out your copyright notice in the Description page of Project Settings.

#include "TankCombat.h"
#include "Tank.h"
#include "Kismet/KismetSystemLibrary.h"
#include "../Public/TankAIController.h"
#include "AimingComponent.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

    AimingComponent = GetPawn()->FindComponentByClass<UAimingComponent>();

	PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	Ammo = 10000;
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	IsPLayerVisible();

	if (ensure(PlayerTank))
	{
		MoveToActor(PlayerTank, AcceptanceRadius);

        if (ensure(AimingComponent))
        {
            AimingComponent->AimAtOpponent(PlayerTank->GetActorLocation());
			if (AimingComponent->GetFiringStatus() == EFiringStatus::Locked && IsPLayerVisible())
				AimingComponent->Fire();
        }
	}
}

bool ATankAIController::IsPLayerVisible()
{
	FHitResult HitResult;
	FCollisionObjectQueryParams QueryParams;
	FCollisionQueryParams IgnoreParam;

	QueryParams.AddObjectTypesToQuery(ECollisionChannel::ECC_WorldStatic);
	QueryParams.AddObjectTypesToQuery(ECollisionChannel::ECC_WorldDynamic);
	IgnoreParam.AddIgnoredActor(GetPawn());
	

	if (PlayerTank == nullptr || GetPawn() == nullptr) { return false; }
	//DrawDebugLine(GetWorld(), GetPawn()->GetActorLoca*tion(), PlayerTank->GetActorLocation(), FColor::Red);

	if (GetWorld()->LineTraceSingleByObjectType(HitResult, GetPawn()->GetActorLocation(), PlayerTank->GetActorLocation(), QueryParams, IgnoreParam))
	{
				if (HitResult.GetActor() == nullptr) { return false; }

				if (HitResult.GetActor()->GetClass()->IsChildOf(ATank::StaticClass()))
					return true;
				
				return false;
	}		
	return false;
}



