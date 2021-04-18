// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ability.h"
#include "AbilityRocket.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class GAME259PROD_SECB_API AAbilityRocket : public AAbility
{
	GENERATED_BODY()

public:
	AAbilityRocket(const FObjectInitializer& ObjectInitializer);
	~AAbilityRocket();


virtual void Activate_Implementation() override;
virtual bool Activate_Validate() override;

private:
	//Weapons range.
	float range;
};
