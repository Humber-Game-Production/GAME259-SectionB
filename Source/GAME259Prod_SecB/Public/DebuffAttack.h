// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Effect.h"
#include "DebuffAttack.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class GAME259PROD_SECB_API UDebuffAttack : public UEffect
{
	GENERATED_BODY()
public:
	UDebuffAttack();
	~UDebuffAttack();

	virtual void Remove() override;

private:

	virtual void Apply() override;
};
