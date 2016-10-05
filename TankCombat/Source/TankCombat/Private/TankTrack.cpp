// Fill out your copyright notice in the Description page of Project Settings.

#include "TankCombat.h"
#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle)
{

	UE_LOG(LogTemp, Warning, TEXT("Direstion: %s, Throttle: %f"), *GetName(), Throttle);

	FVector ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, GetComponentLocation());
}



