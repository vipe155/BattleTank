// Copyright N. Shepard

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTracks.generated.h"

/**
 * Tank tracks is used to set maximum driving force to apply forces to tank
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTracks : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	// sets a throttle between -2 and +2
	UFUNCTION(BlueprintCallable, Category = Input)
		void SetThrottle(float Throttle);

	// Max force per track in Newtons
	UPROPERTY(EditDefaultsOnly)
		float TrackMaxDForce = 400000; // Assume 40 ton tank at 1g accel

private:
	UTankTracks();
	
	TArray<class ASpringWheel*> GetWheels() const;

	void DriveTrack(float CurrentThrottle);

};
