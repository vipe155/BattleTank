// Copyright N. Shepard

#include "TankTracks.h"
#include "Engine/World.h"
#include "SpringWheel.h"
#include "SpawnPoint.h"

UTankTracks::UTankTracks()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

TArray<class ASpringWheel*> UTankTracks::GetWheels() const
{
	TArray<class ASpringWheel*> ResultArray;
	TArray < USceneComponent*> Children;
	GetChildrenComponents(true, Children);

	for (USceneComponent* Child : Children)
	{
		auto SpawnPointChild = Cast<USpawnPoint>(Child);
		if (!SpawnPointChild) { continue; }

		AActor* SpawnedChild = SpawnPointChild->GetSpawnedActor();
		auto SpringWheel = Cast<ASpringWheel>(SpawnedChild);

		if (!SpringWheel) continue;

		ResultArray.Add(SpringWheel);
	}
	return ResultArray;
}

void UTankTracks::SetThrottle(float Throttle)
{
	float CurrentThrottle = FMath::Clamp<float>(Throttle, -2, 2);

	DriveTrack(CurrentThrottle);
}

void UTankTracks::DriveTrack(float CurrentThrottle)
{
	auto ForceApplied = CurrentThrottle * TrackMaxDForce;
	auto Wheels = GetWheels();

	auto ForcePerWheel = ForceApplied / Wheels.Num();
	
	for (ASpringWheel* Wheel : Wheels)
	{
		Wheel->AddDrivingForce(ForcePerWheel);
	}
}