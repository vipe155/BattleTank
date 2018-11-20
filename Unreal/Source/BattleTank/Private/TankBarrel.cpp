// Copyright N. Shepard

#include "TankBarrel.h"
#include "Engine/World.h"

void UTankBarrel::ElevateBarrel(float RelativeSpeed)
{
	// Move the barrel the right amount this frame

	// Given the max elev speed, and the frame time
	RelativeSpeed = FMath::Clamp<float>(
		RelativeSpeed,
		-1,
		1
		);
		
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	
	auto Elevation = FMath::Clamp<float>(
		RawNewElevation,
		MinElevDegrees,
		MaxElevDegrees
		);

	SetRelativeRotation(FRotator(Elevation, 0, 0));
}

