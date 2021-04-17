// Fill out your copyright notice in the Description page of Project Settings.


#include "Ability.h"

UAbility::UAbility()
{
	//icon = Cast<UTexture2D>(StaticLoadObject(UTexture2D::StaticClass(), NULL, *(imagePath)));

}

UAbility::~UAbility()
{
}

void UAbility::Activate()
{

}

void UAbility::Calling_Implementation() {
	Activate();
}

