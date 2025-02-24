// Fill out your copyright notice in the Description page of Project Settings.

#include "Ability.h"

AAbility::AAbility()
{

    SetReplicates(true);

    SetActorTickEnabled(true);
    PrimaryActorTick.bCanEverTick = true;
}

AAbility::~AAbility()
{
}

void AAbility::Activate_Implementation()
{

}

bool AAbility::Activate_Validate()
{
    return true;
}

UTexture2D* AAbility::GetIcon()
{
    return Cast<UTexture2D>(StaticLoadObject(UTexture2D::StaticClass(), NULL, *(imagePath)));
}

Type AAbility::GetType()
{
    return type;
}

bool AAbility::CanUse() const
{
    if (remainingTime > 0.0f) {
        return false;
    }
    return true;
}

void AAbility::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
