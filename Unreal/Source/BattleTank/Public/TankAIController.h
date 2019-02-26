// Copyright N. Shepard

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float AcceptanceRadius = 4000;  // how close AI tank gets to the player

private:
	virtual void BeginPlay() override;

	virtual void SetPawn(APawn* InPawn) override;

	UFUNCTION()
	void OnPossessedTankDeath();

	virtual void Tick(float DeltaTime) override;

};
