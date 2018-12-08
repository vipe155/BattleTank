// Copyright N. Shepard

#pragma once

#include "CoreMinimal.h"
#include "Tank.generated.h"

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

	// Sets default values for this pawn's properties

public:
	// called by the engine when actor takes damage
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser) override;

	// returns current health as percentage, between 0-1
	UFUNCTION(BlueprintPure, Category = Health)
	float GetHealthPercent() const;
	
private:
	ATank();

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	int32 StartingHealth = 100;
	UPROPERTY(VisibleAnywhere, Category = Health)
	int32 CurrentHealth = StartingHealth;
};