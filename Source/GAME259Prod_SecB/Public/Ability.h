// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ability.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class Type : uint8 {
	OFFENSIVE = 0 UMETA(DisplayName = "Offensive"),
	DEFENSIVE = 1  UMETA(DisplayName = "Defensive"),
};

UCLASS(BlueprintType)
class GAME259PROD_SECB_API AAbility : public AActor
{
	GENERATED_BODY()
public:
	AAbility();
	~AAbility();

	//Can be used by any ability that need a value.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Status)
		float floatValue;

	//Nested Multicast Function
	UFUNCTION(BlueprintCallable)
	void Calling();

	UFUNCTION(NetMulticast, Reliable, WithValidation)
	virtual void Activate();

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_Activate();

	UFUNCTION(NetMulticast, Reliable, WithValidation)
	virtual void Boom();

	UFUNCTION(BlueprintCallable, Category = Status)
	UTexture2D* GetIcon();

	UFUNCTION(BlueprintCallable, Category = Status)
	Type GetType();




protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Status)
	FString imagePath;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Status)
	Type type;
};
