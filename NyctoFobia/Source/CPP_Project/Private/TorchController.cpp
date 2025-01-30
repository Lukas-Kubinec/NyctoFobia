/*
Author - Lukas Kubinec
Description - Controls the light emmited by the torch, while looping the torch sound effect
*/

#include "TorchController.h"
#include <Kismet/GameplayStatics.h>
#include <Components/PointLightComponent.h>
#include <Kismet/KismetMathLibrary.h>

// Sets default values for this component's properties
UTorchController::UTorchController()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTorchController::BeginPlay()
{
	Super::BeginPlay();

	// ...

}


// Called every frame
void UTorchController::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

// Controls the torch sound effect
void UTorchController::PlayTorchSoundEffect(USoundBase* TorchSoundEffect)
{
	// Gets and stores the owner location
	FVector OwnerLocation;
	OwnerLocation = GetOwner()->GetActorLocation();

	// Plays the sound effect at the actors location
	UGameplayStatics::PlaySoundAtLocation(GetWorld(), TorchSoundEffect, OwnerLocation);

}

// Controls the torch light
void UTorchController::ControlTorchLight(UPointLightComponent* LightSource, float ChangeFrequency, float ColorRatioRedToGreen, FVector2f IntensityRange)
{
	

	timeDelay += 1 * GetWorld()->GetDeltaSeconds();

	if (timeDelay >= ChangeFrequency) {

		// Change the light colour
		float _randomRedColorValue;
		_randomRedColorValue = UKismetMathLibrary::RandomFloatInRange(ColorRatioRedToGreen, 1);
		LightSource->SetLightColor(FLinearColor(_randomRedColorValue, 1-_randomRedColorValue,0,1), true);

		// Change the light intensity
		float _randomIntensity = UKismetMathLibrary::RandomFloatInRange(IntensityRange.X, IntensityRange.Y);
		LightSource->SetIntensity(_randomIntensity);

		// Resets the timer
		timeDelay = 0.0f;
	}

}

/*
References:
https://dev.epicgames.com/documentation/en-us/unreal-engine/API/Runtime/Engine/Kismet/UGameplayStatics/PlaySoundAtLocation/1
https://dev.epicgames.com/documentation/en-us/unreal-engine/API/Runtime/Engine/Components/UPointLightComponent
https://dev.epicgames.com/documentation/en-us/unreal-engine/API/Runtime/Core/Math/FLinearColor
*/