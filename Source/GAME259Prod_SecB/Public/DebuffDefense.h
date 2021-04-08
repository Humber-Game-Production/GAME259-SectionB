// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Effect.h"
#include "DebuffDefense.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class GAME259PROD_SECB_API UDebuffDefense : public UEffect
{
	GENERATED_BODY()
public:
	UDebuffDefense();
	~UDebuffDefense();

	virtual void Remove() override;

private:

	virtual void Apply() override;
};
