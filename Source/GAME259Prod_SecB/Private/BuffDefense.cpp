// Fill out your copyright notice in the Description page of Project Settings.


#include "BuffDefense.h"
#include "../GAME259Prod_SecBCharacter.h"

UBuffDefense::UBuffDefense()
{
	imagePath = "/Game/ProjectAmulet/Art/Effects/ShieldUp";
}

UBuffDefense::~UBuffDefense()
{
}

void UBuffDefense::Apply()
{
	UEffect::Apply();
	Cast<AGAME259Prod_SecBCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->ChangeDefenseMulti(1.0f);
}

void UBuffDefense::Remove()
{
	UEffect::Remove();
	Cast<AGAME259Prod_SecBCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->ChangeDefenseMulti(-1.0f);
}





