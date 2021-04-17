// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ability.h"
#include "AbilityShield.generated.h"

/**
 * 
 */
UCLASS()
class GAME259PROD_SECB_API UAbilityShield : public UAbility
{
	GENERATED_BODY()

public:

	UAbilityShield(const FObjectInitializer& ObjectInitializer);
	~UAbilityShield();

	virtual void Activate() override;
};
