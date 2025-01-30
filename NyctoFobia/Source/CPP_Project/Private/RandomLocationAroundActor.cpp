/*
Author - Lukas Kubinec
Description - Generates random location around an actor
*/

#include "RandomLocationAroundActor.h"
#include <Kismet/KismetMathLibrary.h>

// Sets default values for this component's properties
URandomLocationAroundActor::URandomLocationAroundActor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}


// Called when the game starts
void URandomLocationAroundActor::BeginPlay()
{
	Super::BeginPlay();	
}


// Called every frame
void URandomLocationAroundActor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


// Get a random Vector from Actor - Used to spawn Actor around Player
FVector URandomLocationAroundActor::GetRandomLocationAroundActor(FVector ActorLocation, float distance, float heightZ)
{
	float randomAngle = UKismetMathLibrary::RandomFloatInRange(0.0f, 360.0f);

	float randomX = ActorLocation.X + distance * cos(randomAngle);
	float randomY = ActorLocation.Y + distance * sin(randomAngle);

	return FVector(randomX, randomY, heightZ);
}

