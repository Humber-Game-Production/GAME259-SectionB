// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ability.h"
#include "Wall.h"
#include "AbilityWall.generated.h"

/**
 * 
 */

//class AWall;

UCLASS()
class GAME259PROD_SECB_API AAbilityWall : public AAbility
{
	GENERATED_BODY()
	
public:
	AAbilityWall();
	~AAbilityWall();
	virtual void Activate_Implementation() override;
	virtual bool Activate_Validate() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	bool release;

	AWall* wall;
};
