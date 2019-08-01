// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TenkNaciljajKomponenta.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "tENK.generated.h"

UCLASS()
class TENKICI_API AtENK : public APawn
{
	GENERATED_BODY()

public:

	virtual void BeginPlay() override;
	AtENK();
	virtual void Tick(float DeltaTime) override;



	void Naciljaj(FVector LokacijaNisanPogotka);

	UFUNCTION(BlueprintCallable,Category = Setup)
	void UzmiBarrel(UStaticMeshComponent* CevkaIzBP);
	

protected:

	UTenkNaciljajKomponenta* TenkuNaciljaj = nullptr;

private:
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere,Category = Pucanj)
		float BrzinaPucnja = 100000; // 1000 m/s TODO nadji razumnu vrednost
};
