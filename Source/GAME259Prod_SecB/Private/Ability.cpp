// Fill out your copyright notice in the Description page of Project Settings.

#include "Ability.h"

AAbility::AAbility()
{

}

AAbility::~AAbility()
{
}

void AAbility::Activate()
{

}

UTexture2D* AAbility::GetIcon()
{
	return Cast<UTexture2D>(StaticLoadObject(UTexture2D::StaticClass(), NULL, *(imagePath)));
}

Type AAbility::GetType()
{
	return type;
}

void AAbility::Boom_Implementation()
{
}

bool AAbility::Boom_Validate() {
	return true;
}

void AAbility::Calling_Implementation() {
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, "Calling");
	Activate();
}

bool AAbility::Calling_Validate() {
	return true;
}

