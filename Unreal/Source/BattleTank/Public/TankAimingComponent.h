// Copyright N. Shepard

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// Enum for aiming status
UENUM()
enum class EFiringStatus : uint8 
{ 
	Reloading,
	Aiming,
	Locked
};

// Forward Declaration
class UTankBarrel; 
class UTankTurret;
class AProjectile;

// Holds parameters for barrel properties/elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = Setup)
		void Initialize(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	UFUNCTION(BlueprintCallable, Category = Firing)
		void Fire();

protected:
	UPROPERTY(BlueprintReadOnly, Category = State)
		EFiringStatus FiringState = EFiringStatus::Aiming;
	
private:
	UTankAimingComponent();

	void MoveBarrelTowards(FVector AimDirection);

	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		TSubclassOf <AProjectile>ProjectileBlueprint; // Default Value

	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float ReloadTimeSeconds = 3; // Default Value

	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float LaunchSpeed = 4000; // Default Value

	double LastFireTime = 0;
};