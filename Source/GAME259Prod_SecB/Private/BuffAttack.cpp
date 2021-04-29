// Fill out your copyright notice in the Description page of Project Settings.

#include "BuffAttack.h"
#include "../GAME259Prod_SecBCharacter.h"

UBuffAttack::UBuffAttack()
{
	imagePath = "/Game/ProjectAmulet/Art/EffectIcons/AttackUp";
}

UBuffAttack::~UBuffAttack()
{

}

void UBuffAttack::Apply() {
	UEffect::Apply();
	Cast<AGAME259Prod_SecBCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->ChangeAttackMulti(1.0f);
}

void UBuffAttack::Remove() {
	UEffect::Remove();
	Cast<AGAME259Prod_SecBCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->ChangeAttackMulti(-1.0f);
}
