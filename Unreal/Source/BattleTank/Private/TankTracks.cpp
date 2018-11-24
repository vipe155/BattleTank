// Copyright N. Shepard

#include "TankTracks.h"

void UTankTracks::SetThrottle(float Throttle)
{
	//auto Time = GetWorld()->GetTimeSeconds();
	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s: throttle: %f"), *Name, Throttle);

	// TODO clamp actual throttle value so no overdrive

	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDForce;
	auto ForceLocation = GetComponentLocation();

	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}


