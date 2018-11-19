// Copyright N. Shepard

#include "TankAIController.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Error, TEXT("AIController can't find Player"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found Player: %s"), *(PlayerTank->GetName()));
	}
}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (GetPlayerTank())
	{
		// TODO move towards player

		// Start aiming towards player
		GetAITank()->AimAt(GetPlayerTank()->GetActorLocation());
		// Fire if ready
	}
}

ATank* ATankAIController::GetAITank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}