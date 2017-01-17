// Fill out your copyright notice in the Description page of Project Settings.

#include "TankCombat.h"
#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle)
{
	FVector ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
    auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	if (!TankRoot) { return; }

	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}



