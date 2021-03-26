// Fill out your copyright notice in the Description page of Project Settings.


#include "UBuff_Defense.h"
#include "../GAME259Prod_SecBCharacter.h"

UBuff_Defense::UBuff_Defense()
{
}

UBuff_Defense::~UBuff_Defense()
{
}

void UBuff_Defense::Apply()
{
	Cast<AGAME259Prod_SecBCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->defenseMulti -= 1.0f;
}

void UBuff_Defense::Remove()
{
	Cast<AGAME259Prod_SecBCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->defenseMulti += 1.0f;
	Cast<AGAME259Prod_SecBCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->DestroyEffect(this);
}


