// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

//Forward declaration
class UTankBarrel; 
class UAimingComponent;

UCLASS()
class TANKCOMBAT_API ATank : public APawn
{
	GENERATED_BODY()

private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;	

protected:
	//pointer to component that we will include on our every tank at compile time
	UAimingComponent* AimingComponent = nullptr;

public:	
	virtual void AimAt(FVector HitLocation, float LaunchSpeed);

	virtual float GetLaunchSpeed();

	//setting the barrel for the tank from blueprint
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	//setting the barrel for the tank from blueprint
	UPROPERTY(EditAnywhere, Category = "TankCombat:Firing")
		float LaunchSpeed = 100000.f; //Sensible starting value 1000 m/s
};
