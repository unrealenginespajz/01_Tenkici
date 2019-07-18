// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "..\Public\TankAIController.h"
#include "Classes/GameFramework/Actor.h"
#include "Classes/Engine/World.h"
#include "Classes/GameFramework/PlayerController.h"
#include "Public/DrawDebugHelpers.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	AtENK* ovaj = PronadjiTenkPlayerControlera();
	if (ovaj)
	{
		FString ImeZaposdnutogTenka = ovaj->GetName();
		UE_LOG(LogTemp, Warning, TEXT("Tenk igraca koji treba unistiti je  %s"), *ImeZaposdnutogTenka);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Nema tenka igraca koga treba unistiti"));
	}


}




void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!UzmiKontrolisanogAITenka()) { return; }
	//FVector LokacijaIgraca = GetWorld()->GetFirstPlayerController()->GetPawn()-> GetActorLocation();
	UzmiKontrolisanogAITenka()->Naciljaj(PronadjiTenkPlayerControlera()->GetActorLocation());

	DrawDebugLine(
		GetWorld(),
		UzmiKontrolisanogAITenka()->GetActorLocation(),
		PronadjiTenkPlayerControlera()->GetActorLocation(),
		FColor(255, 0, 0),
		false, -1, 0,
		5
	);
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


