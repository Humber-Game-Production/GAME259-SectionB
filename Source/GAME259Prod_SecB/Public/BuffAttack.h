// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Effect.h"
#include "BuffAttack.generated.h"


/**
 * Buff player attack
 */
UCLASS(BlueprintType)
class GAME259PROD_SECB_API UBuffAttack : public UEffect
{
	GENERATED_BODY()
public:
	UBuffAttack();
	~UBuffAttack();

	virtual void Remove() override;

private:
	virtual void Apply() override;

};
