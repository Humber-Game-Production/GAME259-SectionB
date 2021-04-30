// Fill out your copyright notice in the Description page of Project Settings.


#include "DebuffAttack.h"
#include "../GAME259Prod_SecBCharacter.h"

UDebuffAttack::UDebuffAttack()
{
	imagePath = "/Game/ProjectAmulet/Art/EffectIcons/AttackDown";
}

UDebuffAttack::~UDebuffAttack()
{
}

void UDebuffAttack::Apply() {
	UEffect::Apply();
	Cast<AGAME259Prod_SecBCharacter>(GetOuter())->ChangeAttackMulti(-0.3f);
}

void UDebuffAttack::Remove() {
	UEffect::Remove();
	Cast<AGAME259Prod_SecBCharacter>(GetOuter())->ChangeAttackMulti(0.3f);
}
