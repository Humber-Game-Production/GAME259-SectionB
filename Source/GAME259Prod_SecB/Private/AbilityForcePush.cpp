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

    DrawDebugSphere
    (
        GetWorld(),
        trans.GetLocation(),  //Start
        300.0f,
        12.0f,
        FColor::Cyan, //Color
        true,
        10.0f,
        0,
        2.0f
    );

    for (auto actors : outActors)
    {
        ACharacter* a = Cast<ACharacter>(actors);

        FRotator rot = UKismetMathLibrary::FindLookAtRotation(startLoc, actors->GetActorLocation());
        FVector vec = rot.Vector();
        vec.Normalize();
        vec *= force;



        a->LaunchCharacter(FVector(vec.X, vec.Y, 0.0f), false, false);
    }

    
}

bool AAbilityForcePush::Activate_Validate()
{
    return true;
}