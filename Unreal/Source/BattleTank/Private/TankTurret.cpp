// Copyright N. Shepard

#include "TankTurret.h"
#include "Engine/World.h"

void UTankTurret::RotateTurret(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(
		RelativeSpeed,
		-1,
		1
		);

	auto RotationChange = RelativeSpeed * MaxRotationDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto NewRotation = RelativeRotation.Yaw + RotationChange;

	auto Rotation = FMath::Clamp<float>(
		NewRotation,
		MinRotationDegrees,
		MaxRotationDegrees
		);

	SetRelativeRotation(FRotator(0, Rotation, 0));
}