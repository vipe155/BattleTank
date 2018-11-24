// Copyright N. Shepard

#include "TankTracks.h"

void UTankTracks::SetThrottle(float Throttle)
{
	//auto Time = GetWorld()->GetTimeSeconds();
	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s: throttle: %f"), *Name, Throttle);
}


