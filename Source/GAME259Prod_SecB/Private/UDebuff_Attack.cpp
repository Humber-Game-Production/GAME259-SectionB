// Fill out your copyright notice in the Description page of Project Settings.


#include "UDebuff_Attack.h"
#include "../GAME259Prod_SecBCharacter.h"

UDebuff_Attack::UDebuff_Attack()
{
}

UDebuff_Attack::~UDebuff_Attack()
{
}

void UDebuff_Attack::Apply() {
	Cast<AGAME259Prod_SecBCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->attackMulti -= 1.0f;
}

void UDebuff_Attack::Remove() {
	Cast<AGAME259Prod_SecBCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->attackMulti += 1.0f;
	Cast<AGAME259Prod_SecBCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->DestroyEffect(this);
}
