// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "AimingComponent.generated.h"

//Forward declaration
class UTankBarrel;
class UTankTurret;
class AProjectile;

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
    virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

    virtual void BeginPlay() override;

	// Sets default values for this component's properties
	UAimingComponent();

    UFUNCTION(BlueprintCallable, Category = "Aiming Setup")
    void Initialize(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

    /*Based on this range the SuggestProjectileVelocity function will compute the velocity based on distance*/
    UPROPERTY(EditDefaultsOnly, Category = "TankCombat:Firing")
    float LaunchRange = 7000.f; 

    UFUNCTION(BlueprintCallable, Category = "Gameplay")
    void Fire();

	//Choose what to aim
	virtual void AimAtOpponent(FVector Opponent);

	//move the barrel toward aiming location
	void MoveBarrelTowards(FVector AimDirection);

    UTankBarrel* GetTankBarrel() const;

	EFiringStatus GetFiringStatus() const;

protected:

    UPROPERTY(BlueprintReadOnly, Category = "Aiming State")
        EFiringStatus FiringState;

private:

    FVector AimDirection = FVector(0);

	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

    UPROPERTY(EditDefaultsOnly, Category = "TankCombat:Firing")
        float ReloadedTimeInSeconds = 3.f;

    UPROPERTY(EditDefaultsOnly, Category = "Setup")
        TSubclassOf<AProjectile> ProjectileBlueprint;

    double LastFireTime = 0;

    bool IsBarrelStatic();

};
