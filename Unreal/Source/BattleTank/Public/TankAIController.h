// Copyright N. Shepard

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class ATank; // Forward Declaration
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
private:
	ATank* GetAITank() const;

	ATank* GetPlayerTank() const;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
};
