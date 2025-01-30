/*
Author - Lukas Kubinec
Description - Chooses a random sound effect from the array that is passed when calling the function
*/

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <Kismet/KismetMathLibrary.h>
#include "RandomSoundEffectComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CPP_PROJECT_API URandomSoundEffectComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URandomSoundEffectComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	// Chooses a random sound effect
	UFUNCTION(BlueprintPure, BlueprintCallable) // Not possible to use TObjectPtr for unreal engine functions :(
	static USoundBase* ChooseRandomSoundEffect(TArray<USoundBase*> SoundEffectsArray);

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};

/*
References:

https://raharuu.github.io/unreal/blueprint-pure-functions-complicated/

*/