// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ability.h"
#include "AbilityShield.generated.h"

/**
 * 
 */
UCLASS()
class GAME259PROD_SECB_API AAbilityShield : public AAbility
{
	GENERATED_BODY()

public:

	AAbilityShield(const FObjectInitializer& ObjectInitializer);
	~AAbilityShield();

	virtual void Activate_Implementation() override;
	virtual bool Activate_Validate() override;

	virtual void Boom_Implementation() override;
	virtual bool Boom_Validate() override;
};
