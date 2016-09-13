// Fill out your copyright notice in the Description page of Project Settings.

#include "TankCombat.h"
#include "TankBarrel.h"



void UTankBarrel::ElevateBarrel(float RelativeSpeed)
{
	float Time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("Degrees by second are : %f, %f"), Time, RelativeSpeed);
}




