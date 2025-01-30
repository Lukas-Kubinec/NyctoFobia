/*
Author - Lukas Kubinec
Description - Main character controller
*/
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyPlayerCharacter.generated.h"

UCLASS()
class CPP_PROJECT_API AMyPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyPlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Used to Enable/Disable player's movement
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool canMove;


protected:

	// Camera component
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UCameraComponent* Camera;

	// Jumping mechanics
	void Jump();

	// Crouching mechanics
	void Crouch();
	void UnCrouch();
	void PlayCrouchWalkingSound();

	// Player Movement mechanics
	void MoveForward(float InputValue);
	void MoveRight(float InputValue);
	void PlayNormalWalkingSound();


	// Camera movement controller 
	void MouseYawX(float InputValue);
	void MousePitchY(float InputValue);

	// Sound effects
	UPROPERTY(EditAnywhere)
	USoundBase* StepSound;
	UPROPERTY(EditAnywhere)
	USoundBase* QuietStepSound;
	UPROPERTY(EditAnywhere)
	USoundBase* CrouchSound;
	UPROPERTY(EditAnywhere)
	USoundBase* JumpSound;

	// Counts time while player is moving
	float characterMovingTime;

	// Sets the delay between steps when walking normally
	UPROPERTY(EditAnywhere)
	float characterNormalStepDelay;

	// Sets the delay between steps when walking while crouching
	UPROPERTY(EditAnywhere)
	float characterCrouchedStepDelay;

};


/*
References:

https://www.youtube.com/watch?v=4IbuUT6Tyj8&t=1s&ab_channel=Acromata
https://dev.epicgames.com/documentation/en-us/unreal-engine/array-containers-in-unreal-engine
https://dev.epicgames.com/documentation/en-us/unreal-engine/API/Runtime/Engine/Sound/USoundBase#references
https://dev.epicgames.com/community/learning/tutorials/Klde/unreal-engine-custom-blueprint-nodes-exposing-c-to-blueprint-with-ufunction

*/