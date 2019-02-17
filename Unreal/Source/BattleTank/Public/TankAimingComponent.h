// Copyright N. Shepard

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "TankAimingComponent.generated.h"

// Enum for aiming status
UENUM()
enum class EFiringStatus : uint8 
{ 
	Reloading,
	Aiming,
	Locked,
	OutofAmmo
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

	UFUNCTION(BlueprintCallable, Category = Firing)
	int32 GetRoundsLeft() const;

	EFiringStatus GetFiringState() const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	class USoundBase* FireSound;

protected:
	UPROPERTY(BlueprintReadOnly, Category = State)
		EFiringStatus FiringState = EFiringStatus::Reloading;
	
private:
	UTankAimingComponent();

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	virtual void BeginPlay() override;

	void MoveBarrelTowards();

	bool IsBarrelMoving();

	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	// Default Values
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		TSubclassOf <AProjectile>ProjectileBlueprint; 

	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float ReloadTimeSeconds = 3; 

	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float LaunchSpeed = 4000; 

	UPROPERTY(EditDefaultsOnly, Category = Firing)
		int32 AmmoCount = 15;

	double LastFireTime = 0;

	FVector AimDirection;
};