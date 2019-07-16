// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "..\Public\TankAIController.h"
#include "Classes/GameFramework/Actor.h"
#include "Classes/Engine/World.h"
#include "Classes/GameFramework/PlayerController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	AtENK* ovaj = PronadjiTenkPlayerControlera();
	if (ovaj)
	{
		FString ImeZaposdnutogTenka = ovaj->GetName();
		UE_LOG(LogTemp, Warning, TEXT("Ime AI zaposednutog tenka je %s"), *ImeZaposdnutogTenka);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Nema AI zaposdnutog tenka"));
	}


}




AtENK * ATankAIController::UzmiKontrolisanogAITenka() const
{
	return Cast<AtENK>(GetPawn());
}



AtENK* ATankAIController::PronadjiTenkPlayerControlera() const
{
	auto Nesto = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (Nesto)
	{

		return Cast<AtENK>(Nesto);
	}
	else
	{
		return  nullptr;
		
	}
}


