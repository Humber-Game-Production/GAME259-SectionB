// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Public/Ability.h"
#include "Components/HorizontalBox.h"
#include "GAME259Prod_SecBCharacter.generated.h"


UCLASS(config=Game)
class AGAME259Prod_SecBCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
public:
	AGAME259Prod_SecBCharacter();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;


	/** Player Health value. */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Stats)
	float health;

	/** Used to increase player damage. */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Stats)
	float attackMulti;

	/** Used to reduce damage player takes. */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Stats)
	float defenseMulti; 

	/** Used to change player speed. */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Stats)
	float speedMulti;

	/** Take Damage Override*/
	float TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser);


	/** Indicates player is protected. */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Stats)
	bool isShielded;

	/** Used to change player speed. */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Ability)
	AAbility* offensiveAbility;

	/** Used to change player speed. */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Ability)
	AAbility* defensiveAbility;


protected:

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	//Reference to HUD Widget for Effectss
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = WidgetRef)
	UHorizontalBox* effectBox;

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

	// Double Jump Mechanic
	/*virtual void Landed(const FHitResult& Hit) override;*/

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
	/** Returns effectBox **/
	FORCEINLINE class UHorizontalBox* GetEffectBox() const { return effectBox; }


	void CallOffensiveAbility();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerCallOffensive();

	void CallDefensiveAbility();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerCallDefensive();

	//C++ Getters

	UFUNCTION()
	float GetAttackMulti() const;

	UFUNCTION()
	float GetDefenseMulti() const;

	UFUNCTION()
	float GetSpeedMulti() const;

	//C++ Setters

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Functions") 
	void ChangeHealth(float value_);

	UFUNCTION(BlueprintCallable)
	void ChangeAttackMulti(float value_);

	UFUNCTION(BlueprintCallable)
	void ChangeDefenseMulti(float value_);

	UFUNCTION(BlueprintCallable)
	void ChangeSpeedMulti(float value_);

	// Double Jump Mechanic
	//UFUNCTION()
	//	void DoubleJump();

	//UPROPERTY()
	//	int DoubleJumpCounter;

	//UPROPERTY()
	//	float JumpHeight;

};

