/*
Author - Lukas Kubinec
Description - Main character controller
*/

#include "../Player/MyPlayerCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraComponent.h"

// Sets actors default values
AMyPlayerCharacter::AMyPlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set up of the Player's Camera
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(RootComponent);
	Camera->bUsePawnControlRotation = true;

}

// Called when the game starts or when spawned
void AMyPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMyPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Selecting the input component
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Character advanced movement functions binding
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMyPlayerCharacter::Jump);
	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &AMyPlayerCharacter::Crouch);
	PlayerInputComponent->BindAction("Crouch", IE_Released, this, &AMyPlayerCharacter::UnCrouch);

	// Character movement functions binding
	PlayerInputComponent->BindAxis("MoveForward", this, &AMyPlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyPlayerCharacter::MoveRight);

	// Camera movement functions binding
	PlayerInputComponent->BindAxis("MouseYawX", this, &AMyPlayerCharacter::MouseYawX);
	PlayerInputComponent->BindAxis("MousePitchY", this, &AMyPlayerCharacter::MousePitchY);

}

void AMyPlayerCharacter::Jump()
{
	// Character must not be crouched, nor be falling in order to jump
	if (!GetCharacterMovement()->IsCrouching() && !GetCharacterMovement()->IsFalling()) {
		// Jump mechanics using the built in ACharacer method
		ACharacter::Jump();
		UGameplayStatics::PlaySound2D(GetWorld(), JumpSound);
	}
}

void AMyPlayerCharacter::Crouch()
{
	// Crouch mechanics using the built in ACharacer method
	ACharacter::Crouch();
	UGameplayStatics::PlaySound2D(GetWorld(), CrouchSound);
}

void AMyPlayerCharacter::UnCrouch()
{
	// UnCrouch mechanics using the built in ACharacer method
	ACharacter::UnCrouch();
}

void AMyPlayerCharacter::MoveForward(float InputValue)
{
	if (canMove) {
		// Character Forward/Backward movement
		FVector ForwardDirection = GetActorForwardVector();
		AddMovementInput(ForwardDirection, InputValue);

		if (InputValue != 0 && GetCharacterMovement()->IsMovingOnGround() && !GetCharacterMovement()->IsCrouching())
		{
			// Plays normal walking sound while the player is moving, is grounded and is not crouched
			PlayNormalWalkingSound();
		}
		else if (InputValue != 0 && GetCharacterMovement()->IsMovingOnGround() && GetCharacterMovement()->IsCrouching())
		{
			// Plays crouched walking sound while the player is moving, is grounded and is crouched
			PlayCrouchWalkingSound();
		}
	}
}

void AMyPlayerCharacter::MoveRight(float InputValue)
{
	if (canMove) {
		// Character Left/Right strafe movement
		FVector RightDirection = GetActorRightVector();
		AddMovementInput(RightDirection, InputValue);
	}

	if (InputValue != 0 && GetCharacterMovement()->IsMovingOnGround() && !GetCharacterMovement()->IsCrouching())
	{
		// Plays normal walking sound while the player is moving, is grounded and is not crouched
		PlayNormalWalkingSound();
	}
	else if (InputValue != 0 && GetCharacterMovement()->IsMovingOnGround() && GetCharacterMovement()->IsCrouching())
	{
		// Plays crouched walking sound while the player is moving, is grounded and is crouched
		PlayCrouchWalkingSound();
	}
}

void AMyPlayerCharacter::PlayNormalWalkingSound()
{
	// Tracks the time character is moving
	characterMovingTime += GetWorld()->GetDeltaSeconds();

	// Checks if character is moving longer that the set delay between steps
	if (characterMovingTime > characterNormalStepDelay) {
		UGameplayStatics::PlaySound2D(GetWorld(), StepSound);

		// Reset the counter
		characterMovingTime = 0.0f;
	}
}

void AMyPlayerCharacter::PlayCrouchWalkingSound()
{
	// Tracks the time character is moving

	characterMovingTime += GetWorld()->GetDeltaSeconds();

	// Checks if character is moving longer that the set delay between steps
	if (characterMovingTime > characterCrouchedStepDelay) {
		UGameplayStatics::PlaySound2D(GetWorld(), QuietStepSound);

		// Reset the counter
		characterMovingTime = 0.0f;
	}
}

void AMyPlayerCharacter::MouseYawX(float InputValue)
{
	if (canMove) {
		// Camera Sideway movement
		AddControllerYawInput(InputValue);
	}
}

void AMyPlayerCharacter::MousePitchY(float InputValue)
{
	if (canMove) {
		// Camera Up/Down movement
		AddControllerPitchInput(InputValue);
	}
}

/*
References:

https://www.youtube.com/watch?v=4IbuUT6Tyj8&t=1s&ab_channel=Acromata
https://dev.epicgames.com/documentation/en-us/unreal-engine/array-containers-in-unreal-engine
https://dev.epicgames.com/documentation/en-us/unreal-engine/API/Runtime/Engine/Sound/USoundBase#references
https://dev.epicgames.com/community/learning/tutorials/Klde/unreal-engine-custom-blueprint-nodes-exposing-c-to-blueprint-with-ufunction

*/