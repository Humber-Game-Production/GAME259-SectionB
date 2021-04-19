// Fill out your copyright notice in the Description page of Project Settings.


#include "BuffSpeed.h"
#include "../GAME259Prod_SecBCharacter.h"

UBuffSpeed::UBuffSpeed()
{
	imagePath = "/Game/ProjectAmulet/Art/EffectIcons/Ambrosia_speedup";
}

UBuffSpeed::~UBuffSpeed()
{
}

void UBuffSpeed::Apply()
{
	Cast<AGAME259Prod_SecBCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->speedMulti -= 1.0f;
}
void UBuffSpeed::Remove()
{
	Cast<AGAME259Prod_SecBCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->speedMulti += 1.0f;
}

