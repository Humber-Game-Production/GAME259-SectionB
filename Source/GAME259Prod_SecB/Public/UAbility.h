// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Class.h"
#include "UAbility.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class Type : uint8 {
	OFFENSIVE = 0 UMETA(DisplayName = "Offensive"),
	DEFENSIVE = 1  UMETA(DisplayName = "Defensive"),
};

UCLASS(BlueprintType)
class GAME259PROD_SECB_API UAbility : public UClass
{
	GENERATED_BODY()
public:
	UAbility();
	~UAbility();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Status)
	TEnumAsByte<Type> type;

	//Can be used by any ability that need a value.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Status)
	float value;

	UFUNCTION(BlueprintCallable, Category = Status)
	virtual void Activate();
};
