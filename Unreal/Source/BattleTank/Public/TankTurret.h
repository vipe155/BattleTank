// Copyright N. Shepard

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 is max left movement, +1 is max right movement
	void RotateTurret(float RelativeSpeed);

private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MaxRotationDegreesPerSecond = 20; // default value

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MaxRotationDegrees = 360; // default value

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MinRotationDegrees = -360; // default value
};