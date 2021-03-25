// Fill out your copyright notice in the Description page of Project Settings.


#include "UDebuff_Speed.h"
#include "../GAME259Prod_SecBCharacter.h"

UDebuff_Speed::UDebuff_Speed()
{

}

UDebuff_Speed::~UDebuff_Speed()
{

}

void UDebuff_Speed::Apply() {
	Cast<AGAME259Prod_SecBCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->speedMulti -= 1.0f;
}

void UDebuff_Speed::Remove() {
	Cast<AGAME259Prod_SecBCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->speedMulti += 1.0f;
	Cast<AGAME259Prod_SecBCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->DestroyEffect(this);
}

