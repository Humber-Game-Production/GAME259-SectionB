// Fill out your copyright notice in the Description page of Project Settings.

#include "BuffAttack.h"
#include "../GAME259Prod_SecBCharacter.h"

UBuffAttack::UBuffAttack()
{

}

UBuffAttack::~UBuffAttack()
{

}

void UBuffAttack::Apply() {
	Cast<AGAME259Prod_SecBCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->attackMulti += 1.0f;
}

void UBuffAttack::Remove() {
	Cast<AGAME259Prod_SecBCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->attackMulti -= 1.0f;
}
