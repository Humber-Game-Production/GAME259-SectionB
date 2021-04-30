// Fill out your copyright notice in the Description page of Project Settings.


#include "AmuletAwe.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "../GAME259Prod_SecBCharacter.h"

UAmuletAwe::UAmuletAwe()
{
	imagePath = "/Game/ProjectAmulet/Art/EffectIcons/AmuletAwe";
}

UAmuletAwe::~UAmuletAwe()
{

}

void UAmuletAwe::Remove()
{
	UEffect::Remove();
	Cast<AGAME259Prod_SecBCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->ChangeSpeedMulti(1.0f);
	UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->GetCharacterMovement()->MaxWalkSpeed /= 2;
}

void UAmuletAwe::Apply()
{
	UEffect::Apply();
	Cast<AGAME259Prod_SecBCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->ChangeSpeedMulti(-1.0f);
	UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->GetCharacterMovement()->MaxWalkSpeed *= 2;

}
