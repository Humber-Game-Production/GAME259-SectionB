// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ability.h"
#include "AbilityAmbrosia.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class GAME259PROD_SECB_API UAbilityAmbrosia : public UAbility
{
	GENERATED_BODY()
	
public:
	UAbilityAmbrosia(const FObjectInitializer& ObjectInitializer);
	~UAbilityAmbrosia();

	virtual void Activate() override;

private:

	void ApplyDebuff();

	float buffTime;
	float debuffTime;
};
