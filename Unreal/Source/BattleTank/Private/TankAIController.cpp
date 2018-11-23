// Copyright N. Shepard

#include "TankAIController.h"
#include "Engine/World.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto AITank = Cast<ATank>(GetPawn());
	if (PlayerTank)
	{
		// TODO move towards player

		// Start aiming towards player
		AITank->AimAt(PlayerTank->GetActorLocation());
		// Fire if ready
		AITank->Fire(); // TODO don't fire every frame
	}
}