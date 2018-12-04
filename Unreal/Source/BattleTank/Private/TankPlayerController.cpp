// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Engine/World.h"
#include "TankAimingComponent.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }
	FoundAimingComponent(AimingComponent);
}

// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick( DeltaTime );
	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetPawn()) { return; } // if not possessing
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }
	
	FVector OutHitLocation; // Out Parameter

	bool bGotHitLocation = GetSightRayHitLocation(OutHitLocation);

	if (bGotHitLocation) 
	{
		AimingComponent->AimAt(OutHitLocation);
	}
}

// Get world location if linetrace through crosshair, true if it hits the landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	// Find the crosshair in pixel coordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	// Deproject the screen position to a world direction
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);
	FVector LookDirection;

	if (GetLookDirection(ScreenLocation, LookDirection)) 
	{
		// line trace that LookDirection and see what we hit
		return GetLookVectorHitLocation(LookDirection, OutHitLocation);
	}
	return false;
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector& LookDirection, FVector& OutHitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);

	if (GetWorld()->LineTraceSingleByChannel
	(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility
	))
	{
		// set hit location
		OutHitLocation = HitResult.Location;
		return true; 
	}

	OutHitLocation = FVector(0);
	return false; // line trace doesn't succeed

		//const auto CrosshairScreenPosition = GetCrosshairScreenPosition();

		////DrawDebugTracing(CrosshairScreenPosition);
		//FHitResult HitResult;
		//if (GetHitResultAtScreenPosition(CrosshairScreenPosition, ECC_Visibility, false, OUT HitResult))
		//{
		//	OutHitLocation = HitResult.Location;
		//}
		//// if we cant find some physycal body take abstract distant point in the sky passing through camera and crosshair
		//else
		//{
		//	FVector CameraLocation;
		//	FVector CameraDirection;
		//	DeprojectScreenPositionToWorld(CrosshairScreenPosition.X, CrosshairScreenPosition.Y, CameraLocation, CameraDirection);
		//	OutHitLocation = FVector(CameraLocation + CameraDirection * 10000);
		//}

}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation;  //discarded

	return DeprojectScreenPositionToWorld
	(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraWorldLocation,
		LookDirection
	);
}


