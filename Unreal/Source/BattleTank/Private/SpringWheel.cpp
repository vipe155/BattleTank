// Copyright N. Shepard

#include "SpringWheel.h"
#include "Components/StaticMeshComponent.h" 
#include "PhysicsEngine/PhysicsConstraintComponent.h"

// Sets default values
ASpringWheel::ASpringWheel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PhysicsConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("Physics Constraint"));
	SetRootComponent(PhysicsConstraint);

	Axle = CreateDefaultSubobject<USphereComponent>(FName("Axle"));
	Axle->SetupAttachment(PhysicsConstraint);

	PhysicsAxle = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("Physics Axle"));
	PhysicsAxle->SetupAttachment(Axle);

	Wheel = CreateDefaultSubobject<USphereComponent>(FName("Wheel"));
	Wheel->SetupAttachment(Axle);
}

// Called when the game starts or when spawned
void ASpringWheel::BeginPlay()
{
	Super::BeginPlay();

	SetupConstraint();
}

void ASpringWheel::SetupConstraint()
{
	if (!GetAttachParentActor()) { return; }
	UPrimitiveComponent* BodyRoot = Cast<UPrimitiveComponent>(GetAttachParentActor()->GetRootComponent());
	if (!BodyRoot) { return; }
	PhysicsConstraint->SetConstrainedComponents(BodyRoot, NAME_None, Axle, NAME_None);
	PhysicsAxle->SetConstrainedComponents(Axle, NAME_None, Wheel, NAME_None);
}

// Called every frame
void ASpringWheel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


