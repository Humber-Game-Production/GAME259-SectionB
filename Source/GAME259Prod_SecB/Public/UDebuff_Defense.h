// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UEffect.h"
#include "UDebuff_Defense.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class GAME259PROD_SECB_API UDebuff_Defense : public UEffect
{
	GENERATED_BODY()
public:
	UDebuff_Defense();
	~UDebuff_Defense();

	virtual void Remove() override;

private:

	virtual void Apply() override;
};
