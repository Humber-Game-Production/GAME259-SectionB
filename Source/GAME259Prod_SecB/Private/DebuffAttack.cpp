// Fill out your copyright notice in the Description page of Project Settings.


#include "DebuffAttack.h"
#include "../GAME259Prod_SecBCharacter.h"

UDebuffAttack::UDebuffAttack()
{
	imagePath = "/Game/ProjectAmulet/Art/EffectIcons/Ambrosia_attackdown";
}

UDebuffAttack::~UDebuffAttack()
{
}

void UDebuffAttack::Apply() {
	Cast<AGAME259Prod_SecBCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->attackMulti -= 1.0f;
}

void UDebuffAttack::Remove() {
	Cast<AGAME259Prod_SecBCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->attackMulti += 1.0f;
}
