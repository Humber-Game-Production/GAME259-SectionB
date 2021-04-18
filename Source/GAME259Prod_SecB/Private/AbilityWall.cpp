// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilityWall.h"
#include "Kismet/GameplayStatics.h"
#include "../GAME259Prod_SecBCharacter.h"
#include "Wall.h"

AAbilityWall::AAbilityWall() {
    //Duration of the ability
    floatValue = 5.0f;

    type = Type::DEFENSIVE;

    //ImagePath
    imagePath = "/Game/ProjectAmulet/Art/AbilityIcons/Force_Field-Wall_Icon";
    SetReplicates(true);
}

AAbilityWall::~AAbilityWall() {}

void AAbilityWall::Activate_Implementation()
{
    FTransform trans = UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn()->GetActorTransform();
    FVector startLoc = trans.GetLocation();
    FVector playerForward = trans.GetRotation().GetForwardVector();

    trans.SetLocation(playerForward * 100 + startLoc);
    FActorSpawnParameters spawnPara;
    spawnPara.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

    GetWorld()->SpawnActor<AWall>(AWall::StaticClass(), trans, spawnPara)->SetLifeSpan(floatValue);

}

bool AAbilityWall::Activate_Validate()
{
    return true;
}