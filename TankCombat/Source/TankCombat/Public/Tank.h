// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

//Forward declaration
class UTankMovementComponent;

UCLASS()
class TANKCOMBAT_API ATank : public APawn
{
	GENERATED_BODY()

public:

	bool IsMoving();

private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Gameplay")
	float VelocityTreshold;


protected:

	//Mozemo ovo maknuti i u Aimingcomponent isto kao na tutorijalu ali meni je dosta logicnije da stoji ovdje
	UPROPERTY(BlueprintReadOnly, Category = Input)
	UTankMovementComponent* TankMovementComponent = nullptr;


};
