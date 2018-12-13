// Copyright N. Shepard

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
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
	void SetupConstraint();

	UPROPERTY(VisibleAnywhere, Category = Components)
		USphereComponent* Wheel = nullptr;

	UPROPERTY(VisibleAnywhere, Category = Components)
		USphereComponent* Axle = nullptr;

	UPROPERTY(VisibleAnywhere, Category = Components)
		UPhysicsConstraintComponent* PhysicsConstraint = nullptr;

	UPROPERTY(VisibleAnywhere, Category = Components)
		UPhysicsConstraintComponent* PhysicsAxle = nullptr;
};
