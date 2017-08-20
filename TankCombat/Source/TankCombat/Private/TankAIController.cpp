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
	AITank = Cast<ATank>(GetPawn());
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	IsPLayerVisible();

	if (ensure(PlayerTank && AITank))
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
	IgnoreParam.AddIgnoredActor(AITank);


	if (PlayerTank == nullptr || GetPawn() == nullptr) { return false; }
	//DrawDebugLine(GetWorld(), AITank->GetActorLocation(), PlayerTank->GetActorLocation(), FColor::Red);

	if (GetWorld()->LineTraceSingleByObjectType(HitResult, AITank->GetActorLocation(), PlayerTank->GetActorLocation(), QueryParams, IgnoreParam))
	{
				if (HitResult.GetActor() == nullptr) { return false; }

				if (HitResult.GetActor()->GetClass()->IsChildOf(ATank::StaticClass()))
				{
					//UE_LOG(LogTemp, Error, TEXT("Tenk jebeni %s"), *HitResult.GetActor()->GetClass()->GetName());
					return true;
				}
				else
				{
					//UE_LOG(LogTemp, Warning, TEXT("NIJEEEE"));
				}
				return false;
	}		
	return false;
}



