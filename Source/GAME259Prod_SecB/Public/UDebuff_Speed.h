// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UEffect.h"
#include "UDebuff_Speed.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class GAME259PROD_SECB_API UDebuff_Speed : public UEffect
{
	GENERATED_BODY()
public:
	UDebuff_Speed();
	~UDebuff_Speed();

	virtual void Remove() override;

private:

	virtual void Apply() override;
};
