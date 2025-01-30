/*
Author - Lukas Kubinec
Description - Chooses a random sound effect from the array that is passed when calling the function
*/

#include "RandomSoundEffectComponent.h"
#include <Kismet/KismetMathLibrary.h>

// Sets default values for this component's properties
URandomSoundEffectComponent::URandomSoundEffectComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void URandomSoundEffectComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void URandomSoundEffectComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

USoundBase* URandomSoundEffectComponent::ChooseRandomSoundEffect(TArray<USoundBase*> SoundEffectsArray)
{
	// Gets the lenght of array
	int32 _arrayLen = SoundEffectsArray.Num() - 1; // -1 because arrays start at 0

	// Used to randomly select sound effect from array
	int32 _randomInt = UKismetMathLibrary::RandomIntegerInRange(0, _arrayLen);

	// Returns the randomly chosen sound effect
	return SoundEffectsArray[_randomInt];
}