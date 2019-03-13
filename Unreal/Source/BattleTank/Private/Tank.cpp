// Copyright N. Shepard

#include "Tank.h"
#include "Engine/World.h"
#include "Classes/Kismet/GameplayStatics.h"

// Sets default values
ATank::ATank()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.

	PrimaryActorTick.bCanEverTick = true;
}

void ATank::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = StartingHealth;
}

void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CurrentHealth >= HealthGValue)
	{
		TankState = ETankStatus::Green;
	}
	else if (CurrentHealth >= HealthYValue)
	{
		TankState = ETankStatus::Yellow;
	}
	else if (CurrentHealth >= HealthOValue)
	{
		TankState = ETankStatus::Orange;
	}
	else
	{
		TankState = ETankStatus::Red;
	}
}

ETankStatus ATank::GetTankState() const
{
	return ETankStatus();
}

float ATank::GetHealthPercent() const
{
	return (float)CurrentHealth / (float)StartingHealth;
}

float ATank::TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser)
{
	int32 DamagePoints = FPlatformMath::RoundToInt(DamageAmount);
	int32 DamageToApply = FMath::Clamp(DamagePoints, 0, CurrentHealth);

	CurrentHealth -= DamageToApply;
	
	if (DamageSound != NULL) 
	{
		UGameplayStatics::PlaySoundAtLocation(this, DamageSound, GetActorLocation());
	}
	
	if (CurrentHealth <= 0)
	{
		TankDeath.Broadcast();
	}
	
	return DamageToApply;
}