// Fill out your copyright notice in the Description page of Project Settings.

#include "AbilityForcePush.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "DrawDebugHelpers.h"
#include "../GAME259Prod_SecBCharacter.h"

AAbilityForcePush::AAbilityForcePush()
{
    type = Type::OFFENSIVE;
    range = 2.0f;

    imagePath = "/Game/ProjectAmulet/Art/AbilityIcons/PushBack_Icon";

    //Force of the pushback
    force = 100.0f;
}

void AAbilityForcePush::Activate_Implementation()
{

    FTransform trans = GetOwner()->GetTransform();
    FVector startLoc = trans.GetLocation();
    FVector playerForward = trans.GetRotation().GetForwardVector();

    TArray<TEnumAsByte<EObjectTypeQuery>> collisionQuery;
    collisionQuery.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_Pawn));

    const TArray<AActor*> actorIgnore{ GetOwner() };

    TArray<AActor*> outActors;

    UKismetSystemLibrary::SphereOverlapActors
    (
        GetWorld(),
        trans.GetLocation(),
        300.0f,
        collisionQuery,
        AGAME259Prod_SecBCharacter::StaticClass(),
        actorIgnore,
        outActors
    );

    for (auto actors : outActors)
    {
        ACharacter* actor = Cast<ACharacter>(actors);

        FRotator rot = UKismetMathLibrary::FindLookAtRotation(startLoc, actors->GetActorLocation());
        FVector vec = rot.Vector();
        vec.Normalize();
        vec *= force;

        actor->LaunchCharacter(FVector(vec.X, vec.Y, 0.0f), false, false);
    }

    
}

bool AAbilityForcePush::Activate_Validate()
{
    return true;
}