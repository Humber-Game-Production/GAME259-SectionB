// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UAbility.h"
#include "RocketAbility.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class GAME259PROD_SECB_API URocketAbility : public UAbility
{
	GENERATED_BODY()

public:
	URocketAbility(const FObjectInitializer& ObjectInitializer);
	~URocketAbility();


virtual void Activate() override;

private:
	//Weapons range.
	float range;
};
