// Fill out your copyright notice in the Description page of Project Settings.


#include "BuffDefense.h"
#include "../GAME259Prod_SecBCharacter.h"

UBuffDefense::UBuffDefense()
{
	imagePath = "/Game/ProjectAmulet/Art/EffectIcons/DefenseUp";
}

UBuffDefense::~UBuffDefense()
{
}

void UBuffDefense::Apply()
{
	UEffect::Apply();
	Cast<AGAME259Prod_SecBCharacter>(GetOuter())->ChangeDefenseMulti(0.3f);
}

void UBuffDefense::Remove()
{
	UEffect::Remove();
	Cast<AGAME259Prod_SecBCharacter>(GetOuter())->ChangeDefenseMulti(-0.3f);
}


