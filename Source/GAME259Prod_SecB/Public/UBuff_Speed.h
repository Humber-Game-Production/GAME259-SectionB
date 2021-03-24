// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UEffect.h"
#include "UBuff_Speed.generated.h"

/**
 * Buff player speed
 */
UCLASS(BlueprintType)
class GAME259PROD_SECB_API UBuff_Speed : public UEffect
{
	GENERATED_BODY()
public:
	UBuff_Speed();
	~UBuff_Speed();

	virtual void Remove() override;

private:

	virtual void Apply() override;
};
