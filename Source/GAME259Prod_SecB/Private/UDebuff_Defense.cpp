// Fill out your copyright notice in the Description page of Project Settings.

#include "UDebuff_Defense.h"
#include "../GAME259Prod_SecBCharacter.h"

UDebuff_Defense::UDebuff_Defense()
{

}

UDebuff_Defense::~UDebuff_Defense()
{

}

void UDebuff_Defense::Apply() {
	Cast<AGAME259Prod_SecBCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->defenseMulti -= 1.0f;
}

void UDebuff_Defense::Remove() {
	Cast<AGAME259Prod_SecBCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->defenseMulti += 1.0f;
	Cast<AGAME259Prod_SecBCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->DestroyEffect(this);
}

