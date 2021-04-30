// Fill out your copyright notice in the Description page of Project Settings.

#include "DebuffDefense.h"
#include "../GAME259Prod_SecBCharacter.h"

UDebuffDefense::UDebuffDefense()
{
	imagePath = "/Game/ProjectAmulet/Art/EffectIcons/DefenseDown";
}

UDebuffDefense::~UDebuffDefense()
{

}

void UDebuffDefense::Apply() {
	UEffect::Apply();
	Cast<AGAME259Prod_SecBCharacter>(GetOuter())->ChangeDefenseMulti(-0.3f);
}

void UDebuffDefense::Remove() {
	UEffect::Remove();
	Cast<AGAME259Prod_SecBCharacter>(GetOuter())->ChangeDefenseMulti(0.3f);
}

