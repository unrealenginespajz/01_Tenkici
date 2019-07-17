// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "Components/PrimitiveComponent.h"
#include "Public/DrawDebugHelpers.h"

//KAKO CILJAMO SA TENKOM !!!
//Treba da nadjemo LineTraceSinge ovog puta po kanalu(Visible) znaci sto vidimo.To nam zahteva pocetak i rotaciju
//kao ulazne parametre...pocetak uzimamo preko CameraManager i uzmemo lokaciju kamere....
//za rotaciju je potrebno prvo da uzmemo lokaciju nisaana pa uz pomoc DeprojectScreenPositionToWorld 
//uzmemo FVector rotaciju tog nisana i tako na kraju dobijemo HitResult koji pretvorimo u FVector

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

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



void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimToward();
}



AtENK* ATankPlayerController::UzmiKontrolisanogTenka() const
{
	return Cast<AtENK>(GetPawn());
}


void ATankPlayerController::AimToward()
{
	if (!UzmiKontrolisanogTenka()) { return; }
	FVector LokacijaNisanPogotka;//out parametar
	if (GetLokacijaPogodtkaNisana(LokacijaNisanPogotka)) //has "side-efect" is going line trace
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit Location %s"), *LokacijaNisanPogotka.ToString());
	}	
}


//Get world location of linetrace	throught corsshair, true if hit landscape
bool ATankPlayerController::GetLokacijaPogodtkaNisana(FVector & HitLocation)const
{
	//Pronadjemo lokaciju nisana u koordinatnom sistemu
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto PrviPresek = ViewportSizeX * CrossHairXLocation;
	auto DrugiPresek = ViewportSizeY * CrossHairYLocation;
	FVector2D LokacijaNisana = FVector2D(PrviPresek, DrugiPresek);
	
	//"De-project" poziciju nisana na svet lokaciju
	FVector RotacijaNisana;
	if (PravacGledanjaNisana(LokacijaNisana,RotacijaNisana))
	{
		//Line-trace along that LookDirection,and see what hit (up to max range)

		LineTracePogodak(RotacijaNisana, HitLocation);
	
	}
	return true;
}

bool ATankPlayerController::PravacGledanjaNisana(FVector2D LokacijaNisana, FVector& WorldDirection) const
{
	//ovaj ne koristimo ali moramo da mu damo da upise....ovo je kamerina lokacija mislim
	FVector CameraWorldLocation;


return	DeprojectScreenPositionToWorld(
		LokacijaNisana.X, 
		LokacijaNisana.Y, 
		CameraWorldLocation, 
		WorldDirection);
}

bool ATankPlayerController::LineTracePogodak(FVector RotacijaNisana, FVector& HitLocation) const
{
	FHitResult Hit;

	//!!!! da kao pocetak uzimamo GetfirsPlayercontroler ActorEyesView onda bi dosta promasivali jer je to lokacija tacno ispod tenka
	FVector Pocetak = PlayerCameraManager->GetCameraLocation();
	FVector Kraj ;
	Kraj = Pocetak + (RotacijaNisana * LineTraceRange);

	DrawDebugLine(
		GetWorld(),
		Pocetak,
		Kraj,
		FColor(255, 0, 0),
		false, -1, 0,
		5
	);
	//ECC_Visibility ako ga vidimo onda ga pogadjamo...naravno na distancu koju postovimo
	if (GetWorld()->LineTraceSingleByChannel(
		Hit, Pocetak, Kraj, ECollisionChannel::ECC_Visibility))
	{
		HitLocation = Hit.Location;//Konvertujemo HitResult u FVector
		return true;
	}
	HitLocation = FVector(0);
	return false;//nismo nista pogodili pogledom

}
