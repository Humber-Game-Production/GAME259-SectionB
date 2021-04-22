// Fill out your copyright notice in the Description page of Project Settings.


#include "DebuffSpeed.h"
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
	Cast<AGAME259Prod_SecBCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->ChangeSpeedMulti(-1.0f);
}

void UDebuffSpeed::Remove() {
	UEffect::Remove();
	Cast<AGAME259Prod_SecBCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->ChangeSpeedMulti(1.0f);
}

