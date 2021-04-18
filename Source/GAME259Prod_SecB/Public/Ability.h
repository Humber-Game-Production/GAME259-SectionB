// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
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
class GAME259PROD_SECB_API UAbility : public UObject
{
	GENERATED_BODY()
public:
	UAbility();
	~UAbility();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Status)
	Type type;

	//Can be used by any ability that need a value.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Status)
	float floatValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Status)
	FString imagePath;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Status)
	UTexture2D* icon;

	//Nested Multicast Function
	UFUNCTION(BlueprintCallable, NetMulticast, Reliable, Category = Status)
	void Calling();

	UFUNCTION(Category = Status)
	virtual void Activate();




};
