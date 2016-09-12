// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "AimingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANKCOMBAT_API UAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAimingComponent();

	// Called when the game starts
	virtual void BeginPlay() override;

	//setting the barrel for the tank
	void SetBarrelReference(UStaticMeshComponent* BarrelToSet);
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	//Choose what to aim
	virtual void AimAt(FVector WordSpaceAim);

private:

	UStaticMeshComponent* Barrel = nullptr;
	
};
