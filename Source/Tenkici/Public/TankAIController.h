// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "tENK.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class TENKICI_API ATankAIController : public AAIController
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	AtENK* UzmiKontrolisanogAITenka() const;
	AtENK* PronadjiTenkPlayerControlera() const;
	//Start tenkt the moving the barrel so that shoot would hit where 
	//the crosshair intersect the world
	void AimToward();
};
