// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ability.h"
#include "AbilityRocket.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class GAME259PROD_SECB_API UAbilityRocket : public UAbility
{
	GENERATED_BODY()

public:
	UAbilityRocket(const FObjectInitializer& ObjectInitializer);
	~UAbilityRocket();


virtual void Activate() override;

private:
	//Weapons range.
	float range;
};
