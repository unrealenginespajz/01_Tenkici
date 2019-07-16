// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "tENK.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TENKICI_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AtENK* UzmiKontrolisanogTenka() const;

	void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;


private:

	//Start tenkt the moving the barrel so that shoot would hit where 
	//the crosshair intersect the world
	void AimToward();
	//return OUT parametar, true if hit landscape
	bool GetSightRayHitLocation(FVector& HitLocation) const;
};
