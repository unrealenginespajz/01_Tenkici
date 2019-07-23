// Fill out your copyright notice in the Description page of Project Settings.

#include "Classes/Components/StaticMeshComponent.h"

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

void UTenkNaciljajKomponenta::Naciljaj(FVector LokacijaNisanPogotka,float BrzinaMetka)

{
	if (!Barrel) { return; }

	FVector OutLounchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("StartPozicijaProjektila"));
	//suggest je staticka kalasa zato ovako zovemo
	
	if (UGameplayStatics::SuggestProjectileVelocity(
		this, OutLounchVelocity, StartLocation, LokacijaNisanPogotka, BrzinaMetka,
		false,0,ESuggestProjVelocityTraceOption::DoNotTrace ))
	{
		auto PravacCiljana = OutLounchVelocity.GetSafeNormal();
		auto ImeTenka = GetOwner()->GetName();
		UE_LOG(LogTemp, Warning, TEXT("%s nisani u %s"),*ImeTenka, *PravacCiljana.ToString());
	}

	
}

