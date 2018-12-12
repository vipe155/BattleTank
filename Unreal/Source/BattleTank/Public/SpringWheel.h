// Copyright N. Shepard

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpringWheel.generated.h"

// Forward declaration(s)
class UStaticMeshComponent;
class UPhysicsConstraintComponent;

UCLASS()
class BATTLETANK_API ASpringWheel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpringWheel();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, Category = Components)
		UStaticMeshComponent* Mass = nullptr;

	UPROPERTY(VisibleAnywhere, Category = Components)
		UStaticMeshComponent* Wheel = nullptr;

	UPROPERTY(VisibleAnywhere, Category = Components)
		UPhysicsConstraintComponent* PhysicsConstraint = nullptr;
};
