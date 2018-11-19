// Copyright N. Shepard

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = ("collision"))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void ElevateBarrel(float DegreesPerSecond);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreesPerSecond = 20; // default value

	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxElevDegrees = 20; // default value

	UPROPERTY(EditAnywhere, Category = Setup)
		float MinElevDegrees = 0; // default value
};
