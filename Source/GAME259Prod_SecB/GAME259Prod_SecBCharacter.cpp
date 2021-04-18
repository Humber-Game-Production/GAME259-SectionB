// Copyright Epic Games, Inc. All Rights Reserved.

#include "GAME259Prod_SecBCharacter.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "Public/Effect.h"

//////////////////////////////////////////////////////////////////////////
// AGAME259Prod_SecBCharacter

AGAME259Prod_SecBCharacter::AGAME259Prod_SecBCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)

	// Double Jump mechanic's jump height
	//JumpHeight = 600.f;

	//Set attackMulti, defenseMulti and speed
	attackMulti = 1.0f;
	defenseMulti = 1.0f;
	speedMulti = 1.0f;

	isShielded = false;
}

float AGAME259Prod_SecBCharacter::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	return Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);
}

//////////////////////////////////////////////////////////////////////////
// Input

void AGAME259Prod_SecBCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	//PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AGAME259Prod_SecBCharacter::DoubleJump);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveForward", this, &AGAME259Prod_SecBCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AGAME259Prod_SecBCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AGAME259Prod_SecBCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AGAME259Prod_SecBCharacter::LookUpAtRate);

	PlayerInputComponent->BindAction("Offensive", IE_Pressed, this, &AGAME259Prod_SecBCharacter::CallOffensiveAbility);
	PlayerInputComponent->BindAction("Defensive", IE_Pressed, this, &AGAME259Prod_SecBCharacter::CallDefensiveAbility);
}

void AGAME259Prod_SecBCharacter::ChangeHealth_Implementation(float value_) {
}

void AGAME259Prod_SecBCharacter::CallOffensiveAbility()
{
	if (!HasAuthority()) {
		ServerCallOffensive();
	}
	else {
		offensiveAbility->Activate();
	}
}

void AGAME259Prod_SecBCharacter::ServerCallOffensive_Implementation()
{
	offensiveAbility->Activate();
}

bool AGAME259Prod_SecBCharacter::ServerCallOffensive_Validate() {
	return true;
}

void AGAME259Prod_SecBCharacter::CallDefensiveAbility()
{
	if (!HasAuthority()) {
		ServerCallDefensive();
	}
	else {
		defensiveAbility->Activate();
	}
}

void AGAME259Prod_SecBCharacter::ServerCallDefensive_Implementation()
{
	defensiveAbility->Activate();
}

bool AGAME259Prod_SecBCharacter::ServerCallDefensive_Validate()
{
	return true;
}

float AGAME259Prod_SecBCharacter::GetAttackMulti() const
{
	return attackMulti;
}

float AGAME259Prod_SecBCharacter::GetDefenseMulti() const
{
	return defenseMulti;
}

float AGAME259Prod_SecBCharacter::GetSpeedMulti() const
{
	return speedMulti;
}

void AGAME259Prod_SecBCharacter::ChangeAttackMulti(float value_)
{
	attackMulti += value_;
}

void AGAME259Prod_SecBCharacter::ChangeDefenseMulti(float value_)
{
	defenseMulti += value_;
}

void AGAME259Prod_SecBCharacter::ChangeSpeedMulti(float value_)
{
	speedMulti += value_;
}

// START OF DOUBLE JUMP MECHANIC
//void AGAME259Prod_SecBCharacter::Landed(const FHitResult& Hit)
//{
//	DoubleJumpCounter = 0;
//}

//void AGAME259Prod_SecBCharacter::DoubleJump()
//{
//	if (DoubleJumpCounter <= 1)
//	{
//		ACharacter::LaunchCharacter(FVector(0, 0, JumpHeight), false, true);
//		DoubleJumpCounter++;
//	}
//
//}
// END OF DOUBLE JUMP MECHANIC

void AGAME259Prod_SecBCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AGAME259Prod_SecBCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void AGAME259Prod_SecBCharacter::MoveForward(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AGAME259Prod_SecBCharacter::MoveRight(float Value)
{
	if ( (Controller != nullptr) && (Value != 0.0f) )
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}
