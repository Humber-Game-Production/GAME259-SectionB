// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Shield.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class GAME259PROD_SECB_API UShield : public UStaticMeshComponent
{
	GENERATED_BODY()

public:

	UShield();
	UShield(const FObjectInitializer& ObjectInitializer);
	~UShield();

	UFUNCTION(BlueprintNativeEvent)
	void BeginPlay() override;

	float shieldHealth;

	//Use to damage shield
	UFUNCTION(BlueprintCallable)
	void Damage(float value);

	//Use to disable the shield and make the player vulerable again.
	UFUNCTION(BlueprintCallable)
		void EndShield();
private:
	
	
};
