// Fill out your copyright notice in the Description page of Project Settings.


#include "UBuff_Speed.h"
#include "../GAME259Prod_SecBCharacter.h"

UBuff_Speed::UBuff_Speed()
{
}

UBuff_Speed::~UBuff_Speed()
{
}

void UBuff_Speed::Apply()
{
	Cast<AGAME259Prod_SecBCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->speedMulti -= 1.0f;
}
void UBuff_Speed::Remove()
{
	Cast<AGAME259Prod_SecBCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->speedMulti += 1.0f;
	Cast<AGAME259Prod_SecBCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->DestroyEffect(this);
}

