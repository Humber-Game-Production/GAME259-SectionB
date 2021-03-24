// Fill out your copyright notice in the Description page of Project Settings.

#include "UBuff_Attack.h"
#include "../GAME259Prod_SecBCharacter.h"

UBuff_Attack::UBuff_Attack()
{

}

UBuff_Attack::~UBuff_Attack()
{

}

void UBuff_Attack::Apply() {
	Cast<AGAME259Prod_SecBCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->attackMulti += 1.0f;
}

void UBuff_Attack::Remove() {
	Cast<AGAME259Prod_SecBCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->attackMulti -= 1.0f;
	Cast<AGAME259Prod_SecBCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->DestroyEffect(this);
}
