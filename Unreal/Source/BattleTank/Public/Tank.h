// Copyright N. Shepard

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;  // Forward Declaration
class UTankTurret; // Forward Declaration
class UTankAimingComponent; // Forward Declaration
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = Firing)
		void Fire();

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetTurretReference(UTankTurret* TurretToSet);

protected:
	UTankAimingComponent* TankAimingComponent = nullptr;
	UTankAimingComponent* TankProjectileComponent = nullptr;

private:
	
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = Firing)
		float LaunchSpeed = 4000; // Default Value

	UPROPERTY(EditAnywhere, Category = Setup)
		TSubclassOf <AProjectile>ProjectileBlueprint; // Default Value

	// Local barrel reference
	UTankBarrel* Barrel = nullptr;

	float ReloadTimeSeconds = 3;

	double LastFireTime = 0;
};

