// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ability.h"
#include "AbilityAmbrosia.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class GAME259PROD_SECB_API AAbilityAmbrosia : public AAbility
{
	GENERATED_BODY()
	
public:
	AAbilityAmbrosia(const FObjectInitializer& ObjectInitializer);


	virtual void Activate_Implementation() override;
	virtual bool Activate_Validate() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:

	void ApplyDebuff();
	float buffTime;
	float debuffTime;
};
