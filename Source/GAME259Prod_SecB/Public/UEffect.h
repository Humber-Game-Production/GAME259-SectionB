// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/Object.h"
#include "UEffect.generated.h"


/**
 *  Base class for temporary player effects.
 */

UCLASS(BlueprintType)
class GAME259PROD_SECB_API UEffect : public UObject
{
	GENERATED_BODY()
public:
	UEffect();
	~UEffect();

	/** Call to apply effect and start timer if it is a count down type */
	UFUNCTION(BlueprintCallable, Category = "Init")
	void Start();

	/** Can be called to manualy remove the effect from the character*/
	UFUNCTION()
	virtual void Remove();

protected:

	//Is this effect removed via time?
	bool isTimed;

	//Duration of the timer
	float duration;

private:

	virtual void Apply();

	FTimerHandle Timer;
	
	//Image here

};
