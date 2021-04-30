// Fill out your copyright notice in the Description page of Project Settings.


#include "BuffSpeed.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "../GAME259Prod_SecBCharacter.h"

UBuffSpeed::UBuffSpeed()
{
	imagePath = "/Game/ProjectAmulet/Art/EffectIcons/SpeedUp";
}

UBuffSpeed::~UBuffSpeed()
{
}

void UBuffSpeed::Apply()
{
	UEffect::Apply();
	Cast<AGAME259Prod_SecBCharacter>(GetOuter())->ChangeSpeedMulti(2.0f);
}
void UBuffSpeed::Remove()
{
	UEffect::Remove();
	Cast<AGAME259Prod_SecBCharacter>(GetOuter())->ChangeSpeedMulti(0.5f);
}

