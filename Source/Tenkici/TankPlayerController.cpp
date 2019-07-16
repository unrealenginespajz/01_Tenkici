// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "Components/PrimitiveComponent.h"

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
	FVector HitLocation;//out parametar
	if (GetSightRayHitLocation(HitLocation)) //has "side-efect" is going line trace
	{
		//UE_LOG(LogTemp, Warning, TEXT("Hit location: %s"), *HitLocation.ToString());
	}
	
}


//Get world location of linetrace	throught corsshair, true if hit landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector & HitLocation)const
{
	//Find crosshead postion in pixel coordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto PrviPresek = ViewportSizeX * CrossHairXLocation;
	auto DrugiPresek = ViewportSizeY * CrossHairYLocation;
	FVector2D ScreenLocation = FVector2D(PrviPresek, DrugiPresek);
	
	//"De-project" the screen postion of the crosshead to a world direction
	FVector WorldDirection;
	if (GetLookDirection(ScreenLocation,WorldDirection))
	{
		UE_LOG(LogTemp, Warning, TEXT("LookDIrection %s"), *WorldDirection.ToString());
	}
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& WorldDirection) const
{
	//ovaj ne koristimo ali moramo da mu damo da upise....ovo je kamerina lokacija mislim
	FVector CameraWorldLocation;


return	DeprojectScreenPositionToWorld(
		ScreenLocation.X, 
		ScreenLocation.Y, 
		CameraWorldLocation, 
		WorldDirection);

}

//bool ATankPlayerController::GetSightRayHitLocation() const
//{
//	FVector Pocetak;
//	FRotator Rotacija;
//	FVector Kraj;
//	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(Pocetak, Rotacija);
//	Kraj = Pocetak + Rotacija.Vector() * 3400.f;
//	FHitResult Hit;
//	FCollisionQueryParams KurParam(FName(TEXT("")), false, GetOwner());
//	bool sarma = GetWorld()->LineTraceSingleByObjectType(Hit, Pocetak, Kraj, ECollisionChannel::ECC_PhysicsBody, KurParam);
//	if (sarma)
//	{
//		UE_LOG(LogTemp, Warning, TEXT("Gledamo %s"), *(Hit.Actor->GetName()));
//		return true;
//	}
//	else
//	{
//		UE_LOG(LogTemp, Warning, TEXT("Nista ne gledamo"), );
//		return false;
//	}
//}
