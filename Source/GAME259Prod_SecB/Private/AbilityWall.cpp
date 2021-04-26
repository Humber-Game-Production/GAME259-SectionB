// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilityWall.h"
#include "Kismet/GameplayStatics.h"
#include "../GAME259Prod_SecBCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Wall.h"

AAbilityWall::AAbilityWall() {
    //Duration of the ability
    floatValue = 5.0f;

    type = Type::DEFENSIVE;

    //ImagePath
    imagePath = "/Game/ProjectAmulet/Art/AbilityIcons/Force_Field-Wall_Icon";
    SetReplicates(true);

    release = false;

    SetActorTickEnabled(true);
    PrimaryActorTick.bCanEverTick = true;
    
}

AAbilityWall::~AAbilityWall() {}

// Called every frame
void AAbilityWall::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (release) {
        FTransform trans = UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn()->GetActorTransform();
        FVector startLoc = trans.GetLocation();

        FRotator rot = Cast<AGAME259Prod_SecBCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->GetCameraBoom()->GetTargetRotation();

        FVector wallLoc = FVector(startLoc + (UKismetMathLibrary::GetForwardVector(rot) * 400));

        FCollisionQueryParams RV_TraceParams = FCollisionQueryParams(FName(TEXT("RV_Trace")), true, wall);
        RV_TraceParams.bTraceComplex = true;
        //RV_TraceParams.bTraceAsyncScene = true;
        RV_TraceParams.bReturnPhysicalMaterial = false;

        //Re-initialize hit info
        FHitResult RV_Hit(ForceInit);

        trans = GetOwner()->GetTransform();
        startLoc = trans.GetLocation();
        FVector playerForward = trans.GetRotation().GetForwardVector();

        GetWorld()->LineTraceSingleByChannel(RV_Hit, //Hit Result
            startLoc, //Start Location
            wallLoc, //End Location
            ECollisionChannel::ECC_Visibility, //Collision Channel
            RV_TraceParams //Trace Parameters
        );

        if (RV_Hit.IsValidBlockingHit()) {
            bool hit = false;
            for (auto tag : RV_Hit.GetActor()->Tags) {
                if (tag == "IsGround") {
                    hit = true;
                }
            }

            if (hit) {
                wall->SetActorLocation(RV_Hit.ImpactPoint);

                //TODO: Get Material Interface.
                //Cast<UStaticMeshComponent>(wall->GetComponentByClass(UStaticMeshComponent::StaticClass()))->SetMaterial(0,;

                wall->SetActorRotation(FRotator(wall->GetActorRotation().Roll, wall->GetActorRotation().Pitch, rot.Yaw));
            }
        }

        //TODO: Get Material Interface.
        //Cast<UStaticMeshComponent>(wall->GetComponentByClass(UStaticMeshComponent::StaticClass()))->SetMaterial(0,;

        wall->SetActorRotation(FRotator(wall->GetActorRotation().Roll, wall->GetActorRotation().Pitch, rot.Yaw));
    }

}

void AAbilityWall::Activate_Implementation()
{

    if(!release) {
    FTransform trans = UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn()->GetActorTransform();
    FVector startLoc = trans.GetLocation();

    FRotator rot = Cast<AGAME259Prod_SecBCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->GetCameraBoom()->GetTargetRotation();

    FVector wallLoc = FVector(startLoc + (UKismetMathLibrary::GetForwardVector(rot) * 400));

    trans.SetLocation(wallLoc);
    FActorSpawnParameters spawnPara;
    spawnPara.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

    wall = GetWorld()->SpawnActor<AWall>(AWall::StaticClass(), trans, spawnPara);

    release = true;
    }
    else {
        FTransform trans = UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn()->GetActorTransform();
        FVector startLoc = trans.GetLocation();

        FRotator rot = Cast<AGAME259Prod_SecBCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->GetCameraBoom()->GetTargetRotation();

        FVector wallLoc = FVector(startLoc + (UKismetMathLibrary::GetForwardVector(rot) * 400));

        FCollisionQueryParams RV_TraceParams = FCollisionQueryParams(FName(TEXT("RV_Trace")), true, wall);
        RV_TraceParams.bTraceComplex = true;
        //RV_TraceParams.bTraceAsyncScene = true;
        RV_TraceParams.bReturnPhysicalMaterial = false;

        //Re-initialize hit info
        FHitResult RV_Hit(ForceInit);

        trans = GetOwner()->GetTransform();
        startLoc = trans.GetLocation();
        FVector playerForward = trans.GetRotation().GetForwardVector();

        GetWorld()->LineTraceSingleByChannel(RV_Hit, //Hit Result
            startLoc, //Start Location
            wallLoc, //End Location
            ECollisionChannel::ECC_Visibility, //Collision Channel
            RV_TraceParams //Trace Parameters
        );

        if (RV_Hit.IsValidBlockingHit()) {
            bool hit = false;
            for (auto tag : RV_Hit.GetActor()->Tags) {
                if (tag == "IsGround") {
                    hit = true;
                }
            }

            if (hit) {
                wall->SetActorLocation(RV_Hit.ImpactPoint);

                wall->SetActorRotation(FRotator(wall->GetActorRotation().Roll, wall->GetActorRotation().Pitch, rot.Yaw));
                wall->SetLifeSpan(floatValue);
            }
            else {
                wall->Destroy();
            }
        }

        release = false;
    }
}

bool AAbilityWall::Activate_Validate()
{
    return true;
}