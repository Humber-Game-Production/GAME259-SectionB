// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UEffect.h"
#include "UBuff_Attack.generated.h"


/**
 * Buff player attack
 */
UCLASS(BlueprintType)
class GAME259PROD_SECB_API UBuff_Attack : public UEffect
{
	GENERATED_BODY()
public:
	UBuff_Attack();
	~UBuff_Attack();

	virtual void Remove() override;

private:
	virtual void Apply() override;

};
