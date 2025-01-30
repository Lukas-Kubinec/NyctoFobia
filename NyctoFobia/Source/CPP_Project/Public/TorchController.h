/*
Author - Lukas Kubinec
Description - Controls the light emmited by the torch, while looping the torch sound effect
*/
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <Components/PointLightComponent.h>
#include "TorchController.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CPP_PROJECT_API UTorchController : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTorchController();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	// Time counter used as a delay
	float timeDelay;
		
protected:
	// Controls the torch sound effect
	UFUNCTION(BlueprintCallable)
	void PlayTorchSoundEffect(USoundBase* TorchSoundEffect);

	// Controls the torch light
	UFUNCTION(BlueprintCallable)
	void ControlTorchLight(UPointLightComponent* LightSource, float ChangeFrequency, float ColorRatioRedToGreen, FVector2f IntensityRange);

};
