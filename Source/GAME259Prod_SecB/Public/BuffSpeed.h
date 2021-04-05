// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Effect.h"
#include "BuffSpeed.generated.h"

/**
 * Buff player speed
 */
UCLASS(BlueprintType)
class GAME259PROD_SECB_API UBuffSpeed : public UEffect
{
	GENERATED_BODY()
public:
	UBuffSpeed();
	~UBuffSpeed();

	virtual void Remove() override;

private:

	virtual void Apply() override;
};
