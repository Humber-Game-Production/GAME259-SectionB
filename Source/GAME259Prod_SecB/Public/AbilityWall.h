// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ability.h"
#include "AbilityWall.generated.h"

/**
 * 
 */
UCLASS()
class GAME259PROD_SECB_API UAbilityWall : public UAbility
{
	GENERATED_BODY()
	
public:
	UAbilityWall();
	~UAbilityWall();
	virtual void Activate() override;
};
