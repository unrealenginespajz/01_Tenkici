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
};
