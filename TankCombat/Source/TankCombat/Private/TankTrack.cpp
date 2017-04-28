// Fill out your copyright notice in the Description page of Project Settings.

#include "TankCombat.h" 
#include "TankTrack.h"


UTankTrack::UTankTrack()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UTankTrack::BeginPlay()
{
    OnComponentHit.AddDynamic(this, &UTankTrack::OnHit);
}

void UTankTrack::ApplySidewaysForce()
{
    //Racunamo kolika je brzina na gusjenicama u stranu
    float SlippingSpeed = FVector::DotProduct(GetComponentVelocity(), GetRightVector());

    float DeltaTime = GetWorld()->GetDeltaSeconds();
    //Racunamo potrebnu akcelaraciju da ispravimo proklizavanja u frame-u
    FVector CorrectionAcceleration = -SlippingSpeed / DeltaTime * GetRightVector();

    //Izracunavamo i dodjeljujemo na bocno ubrzanje sa pojedinacnu gusjenicu
    auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
    if (!ensure(TankRoot)) { return; }
    auto CorrectionForce = (TankRoot->GetMass() * CorrectionAcceleration) / 2;
    TankRoot->AddForce(CorrectionForce);
}

void UTankTrack::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
    DriveTrack();
    ApplySidewaysForce();
    CurrentThrottle = 0.f;
}


void UTankTrack::SetThrottle(float Throttle)
{
    CurrentThrottle = FMath::Clamp<float>(CurrentThrottle + Throttle, -1, 1);
}

void UTankTrack::DriveTrack()
{
    FVector ForceApplied = GetForwardVector() * CurrentThrottle * TrackMaxDrivingForce;
    auto ForceLocation = GetComponentLocation();
    auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
    if (!ensure(TankRoot)) { return; }
    TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}

