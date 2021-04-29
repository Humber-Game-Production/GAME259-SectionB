// Fill out your copyright notice in the Description page of Project Settings.


#include "AmuletAwe.h"
#include "../GAME259Prod_SecBCharacter.h"

UAmuletAwe::UAmuletAwe()
{
	imagePath = "Game/ProjectAmulet/Art/EffectIcons/AmuletAwe.uasset";
}

UAmuletAwe::~UAmuletAwe()
{

}

void UAmuletAwe::Remove()
{
	UEffect::Remove();
	Cast<AGAME259Prod_SecBCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->ChangeSpeedMulti(1.0f);
}

void UAmuletAwe::Apply()
{
	UEffect::Apply();
	Cast<AGAME259Prod_SecBCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->ChangeSpeedMulti(-1.0f);

}
