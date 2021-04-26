// Fill out your copyright notice in the Description page of Project Settings.

#include "AbilityForcePush.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "DrawDebugHelpers.h"
#include "../GAME259Prod_SecBCharacter.h"

AAbilityForcePush::AAbilityForcePush()
{
    type = Type::OFFENSIVE;
    range = 2.0f;
    forceComponent = CreateDefaultSubobject<URadialForceComponent>(TEXT("fc"));
}

void AAbilityForcePush::Activate_Implementation()
{
    FTransform trans = GetOwner()->GetTransform();
    FVector startLoc = trans.GetLocation();
    FVector playerForward = trans.GetRotation().GetForwardVector();

    FCollisionQueryParams RV_TraceParams = FCollisionQueryParams(FName(TEXT("RV_Trace")), true);
    RV_TraceParams.bTraceComplex = true;
    RV_TraceParams.bReturnPhysicalMaterial = false;

    FHitResult RV_Hit(ForceInit);
    FHitResult hitResult[5];

    //GetWorld()->LineTraceSingleByChannel(
    //    RV_Hit,        //result
    //    trans.GetLocation(),    //start
    //    startLoc + playerForward + FVector(0.0f, 0.0f, 1.0f) * range, //end
    //    ECC_Visibility, //collision channel
    //    RV_TraceParams
    //);

    TArray<TEnumAsByte<EObjectTypeQuery>> collisionQuery;
    collisionQuery.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_Pawn));

    const TArray<AActor*> actorIgnore{ GetOwner() };

    TArray<AActor*> outActors;
    TEnumAsByte<EObjectTypeQuery> outActor;

    //Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent())->AddRadialForce(GetOwner()->GetActorLocation(), 300.0f, 50.0f, ERadialImpulseFalloff::RIF_Constant);

    forceComponent->AttachTo(GetOwner()->GetRootComponent());
    forceComponent->bIgnoreOwningActor = true;
    forceComponent->bImpulseVelChange = true;
    forceComponent->ImpulseStrength = 500.0f;
    forceComponent->ForceStrength = 500.0f;
    forceComponent->AddObjectTypeToAffect(outActor);
    forceComponent->FireImpulse();

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
        50.0f,
        0,
        2.0f
    );

    /*for (auto actors : outActors)
    {
        ACharacter* a = Cast<ACharacter>(actors);

        a->LaunchCharacter(FVector(startLoc - actors->GetActorLocation()).GetSafeNormal() * 3000.0f, false, false);
    }*/

    //for (int i = 0; i < 5; i++)
    //{

    //    GetWorld()->LineTraceSingleByChannel(
    //        hitResult[i],        //result
    //        trans.GetLocation(),    //start
    //        startLoc + playerForward + FVector(0.0f, 0.0f, -2.0f + i) * range, //end
    //        ECC_Visibility, //collision channel
    //        RV_TraceParams
    //    );

    //    DrawDebugLine
    //    (
    //        GetWorld(),
    //        trans.GetLocation(),  //Start
    //        startLoc + playerForward + FVector(0.0f, 0.0f, -2.0f + i) * range, //End
    //        FColor::Cyan, //Color
    //        true,
    //        5.0f,
    //        1,
    //        2.0f
    //    );


    //    if (hitResult[i].GetActor() != nullptr)
    //    {
    //        ACharacter* a = Cast<ACharacter>(hitResult[i].GetActor());
    //        a->LaunchCharacter(playerForward * FVector(3000.0f, 0.0f, 0.0f), false, false);
    //    }
    //}

    
}

bool AAbilityForcePush::Activate_Validate()
{
    return true;
}