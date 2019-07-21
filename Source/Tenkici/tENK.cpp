// Fill out your copyright notice in the Description page of Project Settings.


#include "tENK.h"

// Sets default values
AtENK::AtENK()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TenkuNaciljaj = CreateDefaultSubobject<UTenkNaciljajKomponenta>(FName("Komponenta Naciljaj"));
}



// Called when the game starts or when spawned
void AtENK::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AtENK::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AtENK::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AtENK::Naciljaj(FVector LokacijaNisanPogotka)
{
	TenkuNaciljaj->Naciljaj(LokacijaNisanPogotka);
	
}

void AtENK::UzmiBarrel(UStaticMeshComponent * CevkaIzBP)
{ 
	TenkuNaciljaj->SetBarrelReference(CevkaIzBP);
}
