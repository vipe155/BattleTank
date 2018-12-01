// Copyright N. Shepard

#include "TankAIController.h"
#include "TankAimingComponent.h"
#include "Engine/World.h"

// depends on movement component via pathfinding system

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto AITank = GetPawn();
	
	if (!ensure(PlayerTank && AITank)) { return; }

	// Move towards player
	MoveToActor(PlayerTank, AcceptanceRadius); // TODO check radius units

	// Start aiming towards player
	auto AimingComponent = AITank->FindComponentByClass<UTankAimingComponent>();
	AimingComponent->AimAt(PlayerTank->GetActorLocation());
	
	// Fire if ready
	AimingComponent->Fire(); // TODO don't fire every frame 
}