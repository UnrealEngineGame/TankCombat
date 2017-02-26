// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "AimingComponent.generated.h"

//Forward declaration
class UTankBarrel;
class UTankTurret;

UENUM()
enum class EFiringStatus : uint8
{
    Reloading,
    Aiming,
    Locked
};

//Holds all the properties for aiming to an opponent
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANKCOMBAT_API UAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAimingComponent();

    UFUNCTION(BlueprintCallable, Category = "Aiming Setup")
    void Initialize(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

    //setting the barrel for the tank from blueprint
    UPROPERTY(EditDefaultsOnly, Category = "TankCombat:Firing")
    float LaunchSpeed = 4000.f; //Sensible starting value 1000 m/s

	//Choose what to aim
	virtual void AimAtOpponent(FVector Opponent);

	//move the barrel toward aiming location
	void MoveBarrelTowards(FVector AimDirection);

    UTankBarrel* GetTankBarrel() const;

protected:

    UPROPERTY(BlueprintReadOnly, Category = "Aiming State")
    EFiringStatus FiringState = EFiringStatus::Aiming;

private:

	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

};
