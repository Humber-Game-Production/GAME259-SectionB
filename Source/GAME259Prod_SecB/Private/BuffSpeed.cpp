// Fill out your copyright notice in the Description page of Project Settings.


#include "BuffSpeed.h"
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
	Cast<AGAME259Prod_SecBCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->ChangeSpeedMulti(1.0f);
}
void UBuffSpeed::Remove()
{
	UEffect::Remove();
	Cast<AGAME259Prod_SecBCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->ChangeSpeedMulti(-1.0f);
}

