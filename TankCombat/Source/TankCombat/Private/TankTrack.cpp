// Fill out your copyright notice in the Description page of Project Settings.

#include "TankCombat.h"
#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle)
{

	UE_LOG(LogTemp, Warning, TEXT("Direction: %s, Throttle: %f"), *GetName(), Throttle);

	FVector ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	UE_LOG(LogTemp, Warning, TEXT("GetForwardVector: %s"), *GetForwardVector().ToString());

	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	UE_LOG(LogTemp, Warning, TEXT("Root: %s"), *GetOwner()->GetName());

	if (!TankRoot) { return; }
	UE_LOG(LogTemp, Error, TEXT("ForceApplied : %s"), *ForceApplied.ToString());

	TankRoot->AddForceAtLocation(ForceApplied, GetComponentLocation());

}



