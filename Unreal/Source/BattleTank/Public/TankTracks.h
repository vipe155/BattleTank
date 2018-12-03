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
	
private:
	UTankTracks();
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

public:
	// sets a throttle between -1 and +1
	UFUNCTION(BlueprintCallable, Category = Input)
		void SetThrottle(float Throttle);

	// Max force per track in Newtons
	UPROPERTY(EditDefaultsOnly)
		float TrackMaxDForce = 400000; // Assume 40 ton tank at 1g accel
};
