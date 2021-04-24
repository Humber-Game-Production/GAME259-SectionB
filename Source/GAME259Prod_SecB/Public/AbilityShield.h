// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ability.h"
#include "AbilityShield.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class GAME259PROD_SECB_API AAbilityShield : public AAbility
{
	GENERATED_BODY()

public:

	AAbilityShield(const FObjectInitializer& ObjectInitializer);
	~AAbilityShield();

	virtual void Activate_Implementation() override;
	virtual bool Activate_Validate() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
