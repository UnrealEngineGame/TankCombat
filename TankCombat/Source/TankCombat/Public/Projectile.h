// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Projectile.generated.h"


UCLASS()
class TANKCOMBAT_API AProjectile : public AActor
{
	GENERATED_BODY()
	


private:	
	// Sets default values for this actor's properties
	AProjectile();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

private:
	//Initialize Projectile Movement Component 
	UProjectileMovementComponent* ProjectileMovementComponent = nullptr;
	
};
