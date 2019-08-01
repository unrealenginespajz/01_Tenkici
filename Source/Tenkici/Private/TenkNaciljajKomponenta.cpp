// Fill out your copyright notice in the Description page of Project Settings.



#include "TenkNaciljajKomponenta.h"
#include "Classes/Components/StaticMeshComponent.h"


// Sets default values for this component's properties
UTenkNaciljajKomponenta::UTenkNaciljajKomponenta()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
}


void UTenkNaciljajKomponenta::SetBarrelReference(UStaticMeshComponent * AOvaCevka)
{
	SM_Cevka = AOvaCevka;
}


void UTenkNaciljajKomponenta::Naciljaj(FVector LokacijaNisanPogotka,float BrzinaMetka)

{
	if (!SM_Cevka) { return; }

	FVector OutLounchVelocity;
	FVector StartLocation = SM_Cevka->GetSocketLocation(FName("StartPozicijaProjektila"));
	//suggest je staticka kalasa zato ovako zovemo
	//posle brzine metka sledeca tri parametra imaju defoutlne vrednosti zato ih sklanjamo i ovako ih ne menjamo
	if (UGameplayStatics::SuggestProjectileVelocity(
		this, OutLounchVelocity, StartLocation, LokacijaNisanPogotka, BrzinaMetka,
		ESuggestProjVelocityTraceOption::DoNotTrace ))
	{
		auto PravacCiljana = OutLounchVelocity.GetSafeNormal();
		auto ImeTenka = GetOwner()->GetName();
		UE_LOG(LogTemp, Warning, TEXT("%s nisani u %s"),*ImeTenka, *PravacCiljana.ToString());
		MoveBarrel(PravacCiljana);

	}	
	else
	{
		UE_LOG(LogTemp,Warning,TEXT("Promasuje"),)
	}
}

void UTenkNaciljajKomponenta::MoveBarrel(FVector AimDirection) const
{
	//kad znamo sta pogadjamo tower pomeramo po rotaciji ja bi je pomerao po lokaciji nisan pogodtka
	//nadjemo komponentu tauren i  dajemo joj tu hit lokaciju (znaci levo desno) a barrel gore dole
	//dati mu maximalnu brzinu(ovoga se nisam setio ja )
	
	//pozicija barela po x osi i onda ptrtvaramo u Rotation tj. peach, yawl, rotation
	auto BarrelRotator = SM_Cevka->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	UE_LOG(LogTemp, Warning, TEXT("AimAsRotator %s"), *AimAsRotator.ToString());
}


