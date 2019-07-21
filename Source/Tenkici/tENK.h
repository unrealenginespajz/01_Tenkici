// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TenkNaciljajKomponenta.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "tENK.generated.h"

UCLASS()
class TENKICI_API AtENK : public APawn
{
	GENERATED_BODY()

public:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Sets default values for this pawn's properties
	AtENK();
	void Naciljaj(FVector LokacijaNisanPogotka);

protected:
	UTenkNaciljajKomponenta* TenkuNaciljaj = nullptr;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
