// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Kismet/GameplayStatics.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TenkNaciljajKomponenta.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TENKICI_API UTenkNaciljajKomponenta : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Konstruktor
	UTenkNaciljajKomponenta();

	void SetBarrelReference(UStaticMeshComponent* AOvaCevka);

	void Naciljaj(FVector LokacijaNisanPogotka,float BrzinaMetka);
		
private:
	UStaticMeshComponent* SM_Cevka = nullptr;
	void MoveBarrel(FVector AimDirection) const;
};
