// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/Object.h"
#include "Components/Image.h"
#include "Components/HorizontalBox.h"
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

	/** Call to apply effect
	isTimed = should the effect be removed after duration has passed?

	duration = if effect is timed how long until it is removed.
	*/
	UFUNCTION(BlueprintCallable, Category = "Init")
	void Start(bool isTimed, float duration_);

	/** Can be called to manualy remove the effect from the character*/
	UFUNCTION()
	virtual void Remove();

	/** Use to add iamge to widget **/
	UFUNCTION(BlueprintCallable, Category = "Init")
	void SetupImage(UHorizontalBox* widget_);

protected:

	/** The image accociated with the effect*/
	//UImage img;
	

private:

	virtual void Apply();

	FTimerHandle Timer;

	//Image here

};
