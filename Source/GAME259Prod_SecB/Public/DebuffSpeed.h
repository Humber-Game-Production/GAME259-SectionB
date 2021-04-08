// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Effect.h"
#include "DebuffSpeed.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class GAME259PROD_SECB_API UDebuffSpeed : public UEffect
{
	GENERATED_BODY()
public:
	UDebuffSpeed();
	~UDebuffSpeed();

	virtual void Remove() override;

private:

	virtual void Apply() override;
};
