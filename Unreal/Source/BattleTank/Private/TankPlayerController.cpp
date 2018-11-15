// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("PlayerController Tank Not Found"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController Tank Found: %s"), *(ControlledTank->GetName()));
	}
}

// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick( DeltaTime );
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector OutHitLocation; // Out Parameter
	if (GetSightRayHitLocation(OutHitLocation)) // TODO Raytrace
	{
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *OutHitLocation.ToString());
			
		// TODO Tell controlled tank to aim at point
	}
}

// Get world location if linetrace through crosshair, true if it hits the landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	OutHitLocation = FVector(1.0);

	return true;
	//FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());
	//GetWorld()->LineTraceSingleByObjectType(
	//	OUT OutHitLocation(),
	//	GetReachLineStart(),
	//	GetReachLineEnd(),
	//	FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
	//	TraceParameters
	//);
}