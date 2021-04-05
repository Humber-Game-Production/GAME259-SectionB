// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Effect.h"
#include "BuffDefense.generated.h"


/**
 * Buff player defense
 */
UCLASS(BlueprintType)
class GAME259PROD_SECB_API UBuffDefense : public UEffect
{
	GENERATED_BODY()
public:
	UBuffDefense();
	~UBuffDefense();

	virtual void Remove() override;

private:

	virtual void Apply() override;
};
