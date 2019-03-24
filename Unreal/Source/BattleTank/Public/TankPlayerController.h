// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class UTankAimingComponent;
class ATank;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	UFUNCTION(BlueprintImplementableEvent, Category = Setup)
		void TankConstructed(UTankAimingComponent* AimingCompRef, ATank* TankRef);

private:
	// Start the tank moving the barrel where crosshair intersects world
	void AimTowardsCrosshair();

	// Return an OUT parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly)
		float CrossHairXLocation = 0.5;

	UPROPERTY(EditDefaultsOnly)
		float CrossHairYLocation = 0.3333;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	UPROPERTY(EditDefaultsOnly)
		float LineTraceRange = 1000000;

	bool GetLookVectorHitLocation(FVector& LookDirection, FVector& OutHitLocation) const;

	virtual void SetPawn(APawn* InPawn) override;

	UFUNCTION(BlueprintCallable, Category = "State")
	void OnPlayerTankDeath();
};
