// Copyright N. Shepard

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

// Forward Declarations
class UTankBarrel;  
class UTankTurret;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:	
	UFUNCTION(BlueprintCallable, Category = Firing)
		void Fire();

private:
	// Sets default values for this pawn's properties
	ATank();

	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		TSubclassOf <AProjectile>ProjectileBlueprint; // Default Value

	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float ReloadTimeSeconds = 3; // Default Value

	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float LaunchSpeed = 4000; // Default Value

	UTankBarrel* Barrel = nullptr; // TODO remove

	double LastFireTime = 0;
};

