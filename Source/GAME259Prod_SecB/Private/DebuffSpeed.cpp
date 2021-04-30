// Fill out your copyright notice in the Description page of Project Settings.


#include "DebuffSpeed.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "../GAME259Prod_SecBCharacter.h"

UDebuffSpeed::UDebuffSpeed()
{
	imagePath = "/Game/ProjectAmulet/Art/EffectIcons/SpeedDown";
}

UDebuffSpeed::~UDebuffSpeed()
{

}

void UDebuffSpeed::Apply() {
	UEffect::Apply();
	Cast<AGAME259Prod_SecBCharacter>(GetOuter())->ChangeSpeedMulti(0.5f);
}

void UDebuffSpeed::Remove() {
	UEffect::Remove();
	Cast<AGAME259Prod_SecBCharacter>(GetOuter())->ChangeSpeedMulti(2.0f);
}

