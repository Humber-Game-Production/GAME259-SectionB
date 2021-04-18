// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Effect.h"
#include "HealOverTime.generated.h"


/**
 * Buff player defense
 */
UCLASS(BlueprintType)
class GAME259PROD_SECB_API UHealOverTime : public UEffect
{
	GENERATED_BODY()
public:
	UHealOverTime();
	~UHealOverTime();

	virtual void Remove() override;

private:

	virtual void Apply() override;

	void TickEffect();

private:

	FTimerHandle tickTimer;
	
};