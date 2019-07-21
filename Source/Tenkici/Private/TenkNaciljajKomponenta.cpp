// Fill out your copyright notice in the Description page of Project Settings.


#include "TenkNaciljajKomponenta.h"



// Called when the game starts
void UTenkNaciljajKomponenta::BeginPlay()
{
	Super::BeginPlay();

	// ...

}


// Sets default values for this component's properties
UTenkNaciljajKomponenta::UTenkNaciljajKomponenta()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UTenkNaciljajKomponenta::SetBarrelReference(UStaticMeshComponent * AOvaCevka)
{
	Barrel = AOvaCevka;
}




// Called every frame
void UTenkNaciljajKomponenta::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTenkNaciljajKomponenta::Naciljaj(FVector LokacijaNisanPogotka)
{
	auto ImeTenka =GetOwner() -> GetName();
	auto LokacijaCevke = Barrel->GetComponentLocation().ToString();
	UE_LOG(LogTemp, Warning, TEXT("%s je naciljao %s sa lokacije %s"), *ImeTenka, *LokacijaNisanPogotka.ToString(),*LokacijaCevke);
}

