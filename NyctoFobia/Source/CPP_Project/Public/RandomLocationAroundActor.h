/*
Author - Lukas Kubinec
Description - Generates random location around an actor
*/

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RandomLocationAroundActor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CPP_PROJECT_API URandomLocationAroundActor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URandomLocationAroundActor();


protected:
	// Called when the game starts
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Get a random Vector from Actor - Used to spawn Actor around Player
	UFUNCTION(BlueprintCallable)
	static FVector GetRandomLocationAroundActor(FVector ActorLocation, float distance, float heightZ);
		
};
