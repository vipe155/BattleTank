// Copyright N. Shepard

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto AITank = GetAITank();
	if (!AITank)
	{
		UE_LOG(LogTemp, Error, TEXT("AIController Tank Not Found"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController Tank Found: %s"), *(AITank->GetName()));
	}
}

ATank* ATankAIController::GetAITank() const
{
	return Cast<ATank>(GetPawn());
}


