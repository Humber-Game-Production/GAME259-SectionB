// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Effect.h"
#include "AmuletAwe.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class GAME259PROD_SECB_API UAmuletAwe : public UEffect
{
	GENERATED_BODY()
	
public:
	UAmuletAwe();
	~UAmuletAwe();

	virtual void Remove() override;

private:
	virtual void Apply() override;

};
