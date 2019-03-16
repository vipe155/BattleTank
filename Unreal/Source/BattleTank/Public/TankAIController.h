// Copyright N. Shepard

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

// Enum for AI perception state
UENUM()
enum class EPerceptionStatus : uint8
{
	Guarding, Attacking
};

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "State")
		EPerceptionStatus GetPerceptionStatus() const;

	UFUNCTION(BlueprintCallable, Category = "State")
		void SetPerceptionStatus(EPerceptionStatus NextPerceptionStatus);
	
protected:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float AcceptanceRadius = 4000;  // how close AI tank gets to the player

private:
	virtual void BeginPlay() override;

	virtual void SetPawn(APawn* InPawn) override;

	UFUNCTION()
	void OnPossessedTankDeath();

	virtual void Tick(float DeltaTime) override;

	//set the default value to patrolling
	UPROPERTY(VisibleAnywhere, Category = "State")
		EPerceptionStatus PerceptionStatus = EPerceptionStatus::Guarding;

};
