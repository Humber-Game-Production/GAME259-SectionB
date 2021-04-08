// Fill out your copyright notice in the Description page of Project Settings.


#include "Ability.h"

UAbility::UAbility()
{
	

}

UAbility::~UAbility()
{
}

void UAbility::Activate()
{

}

UTexture2D* UAbility::GetIcon()
{
	return Cast<UTexture2D>(StaticLoadObject(UTexture2D::StaticClass(), NULL, *(imagePath)));
}

Type UAbility::GetType()
{
	return type;
}

void UAbility::Calling_Implementation() {
	Activate();
}

