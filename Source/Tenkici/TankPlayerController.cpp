// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("TankPlayerControler begin play"));

	AtENK* ovaj = UzmiKontrolisanogTenka();
	if (ovaj)
	{
		FString ImeZaposdnutogTenka = ovaj->GetName();
		UE_LOG(LogTemp, Warning, TEXT("Ime zaposednutog tenka je %s"),*ImeZaposdnutogTenka);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Nema zaposdnutog tenka"));
	}
}

AtENK* ATankPlayerController::UzmiKontrolisanogTenka() const
{
	return Cast<AtENK>(GetPawn());
}

