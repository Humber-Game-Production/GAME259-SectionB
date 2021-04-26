// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ability.h"
#include "PhysicsEngine/RadialForceComponent.h"
#include "AbilityForcePush.generated.h"

/**
 * 
 */
UCLASS()
class GAME259PROD_SECB_API AAbilityForcePush : public AAbility
{
	GENERATED_BODY()
	
public:
	AAbilityForcePush();
	virtual void Activate_Implementation() override;
	virtual bool Activate_Validate() override;

private:
	float range;
	URadialForceComponent* forceComponent;
};
