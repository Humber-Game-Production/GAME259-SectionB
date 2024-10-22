// Fill out your copyright notice in the Description page of Project Settings.

#include "AbilityShield.h"
#include "Kismet/GameplayStatics.h"
#include "Shield.h"
#include "../GAME259Prod_SecBCharacter.h"

AAbilityShield::AAbilityShield(const FObjectInitializer& ObjectInitializer) {
    type = Type::DEFENSIVE;
    imagePath = "/Game/ProjectAmulet/Art/AbilityIcons/Shield_Icon";
    
    bReplicates = true;

    bAlwaysRelevant = true;

    cooldownTime = 5.0f;
}

AAbilityShield::~AAbilityShield()
{
    //Content/ThirdPersonCPP/Blueprints/Shield.uasset
}

void AAbilityShield::Activate_Implementation()
{
    //Turn shield on


    Cast<AGAME259Prod_SecBCharacter>(GetOwner())->isShielded = true;

    UShield* NewComponent = NewObject<UShield>(GetOwner(), UShield::StaticClass(), "Shield");
    check(NewComponent);

    FAttachmentTransformRules rules = FAttachmentTransformRules(EAttachmentRule::KeepRelative, false);
    NewComponent->AttachToComponent(Cast<ACharacter>(GetOwner())->GetMesh(), rules, "Shield");
    
    NewComponent->RegisterComponent();

    NewComponent->AddRelativeLocation(FVector(0, 0.0f, 50.0f));

    remainingTime = cooldownTime;
}

bool AAbilityShield::Activate_Validate()
{
    return true;
}

void AAbilityShield::Tick(float DeltaTime)
{
    if (remainingTime > 0.0f) {
        remainingTime -= DeltaTime;
    }
}
