// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilityRocket.h"
#include "Kismet/GameplayStatics.h"
#include "../GAME259Prod_SecBCharacter.h"
#include "Rocket.h"



AAbilityRocket::AAbilityRocket(const FObjectInitializer& ObjectInitializer) {
    type = Type::OFFENSIVE;
    range = 2.0f;

    floatValue = 30.0f; //Damage

    imagePath = "/Game/ProjectAmulet/Art/AbilityIcons/RocketShot_Icon";

    bReplicates = true;

    bAlwaysRelevant = true;

    cooldownTime = 5.0f;
}

AAbilityRocket::~AAbilityRocket() {

}

void AAbilityRocket::Activate_Implementation()
{
    FCollisionQueryParams RV_TraceParams = FCollisionQueryParams(FName(TEXT("RV_Trace")), true);
    RV_TraceParams.bTraceComplex = true;
    //RV_TraceParams.bTraceAsyncScene = true;
    RV_TraceParams.bReturnPhysicalMaterial = false;

    //Re-initialize hit info
    FHitResult RV_Hit(ForceInit);

    FTransform trans = GetOwner()->GetTransform();
    FVector startLoc = trans.GetLocation();
    FVector playerForward = trans.GetRotation().GetForwardVector();


    //call GetWorld() from within an actor extending class
    GetWorld()->LineTraceSingleByChannel(
        RV_Hit,        //result
        trans.GetLocation(),    //start
        startLoc + playerForward * range, //end
        ECC_Visibility, //collision channel
        RV_TraceParams
    );

    

    trans.SetLocation(playerForward * 100 + startLoc);
    FActorSpawnParameters spawnPara;
    spawnPara.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;
    //Spawn Rocket Here.
    if (UGameplayStatics::GetPlayerCharacter(GetWorld(), 0) != nullptr) {
        GetWorld()->SpawnActor<ARocket>(ARocket::StaticClass(), trans, spawnPara)->Initalize(floatValue * Cast<AGAME259Prod_SecBCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->GetAttackMulti());
    }
    remainingTime = cooldownTime;
}

bool AAbilityRocket::Activate_Validate()
{
    return true;
}

void AAbilityRocket::Tick(float DeltaTime)
{
    if (remainingTime > 0.0f) {
        remainingTime -= DeltaTime;
    }

}
