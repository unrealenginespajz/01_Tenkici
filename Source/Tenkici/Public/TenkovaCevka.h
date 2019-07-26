// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TenkovaCevka.generated.h"

/**
 * 
 */
UCLASS()
class TENKICI_API UTenkovaCevka : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void PodigniCevku(float vrednost);
};
