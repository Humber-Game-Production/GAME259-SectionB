// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "Components/HorizontalBox.h"
#include "MatchPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class GAME259PROD_SECB_API AMatchPlayerState : public APlayerState
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere, Category = Variables)
	UHorizontalBox* effectBox;

public:

	UFUNCTION(BlueprintCallable, Category = Functions)
	void SetEffectBox(UHorizontalBox* box);

	UFUNCTION(BlueprintCallable, Category = Functions)
	UHorizontalBox* GetEffectBox() const;
};
