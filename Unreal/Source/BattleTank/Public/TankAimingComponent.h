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

// Holds parameters for barrel properties/elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	// Sets default values for this component's properties
	UTankAimingComponent();

	void SetBarrelReference(UTankBarrel* BarrelToSet);

	void SetTurretReference(UTankTurret* TurretToSet);

	void AimAt(FVector HitLocation, float LaunchSpeed);

protected:
	UPROPERTY(BlueprintReadOnly, Category = State)
		EFiringStatus FiringState = EFiringStatus::Reloading;
	
private:
	UTankBarrel* Barrel = nullptr;

	UTankTurret* Turret = nullptr;

	void MoveBarrelTowards(FVector AimDirection);
};