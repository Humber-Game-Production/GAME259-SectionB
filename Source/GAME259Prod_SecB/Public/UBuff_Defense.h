// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UEffect.h"
#include "UBuff_Defense.generated.h"


/**
 * Buff player defense
 */
UCLASS(BlueprintType)
class GAME259PROD_SECB_API UBuff_Defense : public UEffect
{
	GENERATED_BODY()
public:
	UBuff_Defense();
	~UBuff_Defense();

	virtual void Remove() override;

private:

	virtual void Apply() override;
};
