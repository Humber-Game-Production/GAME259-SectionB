// Fill out your copyright notice in the Description page of Project Settings.

#include "AbilityShield.h"
#include "Kismet/GameplayStatics.h"
#include "Shield.h"
#include "../GAME259Prod_SecBCharacter.h"

UAbilityShield::UAbilityShield(const FObjectInitializer& ObjectInitializer) {
	type = Type::DEFENSIVE;
}

UAbilityShield::~UAbilityShield()
{
	///Content/ThirdPersonCPP/Blueprints/Shield.uasset
}

void UAbilityShield::Activate()
{
	//Internal cool down.
	if (Cast<AGAME259Prod_SecBCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->isShielded == false) {
		//Turn shield on
		Cast<AGAME259Prod_SecBCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->isShielded = true;

		//Spawn Shield static mesh
		NewObject<UShield>(UGameplayStatics::GetPlayerController(GetWorld(), 0), TEXT("Shield")); //Bounds->CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere"));
		//Get the mesh
		//static ConstructorHelpers::FObjectFinder<UStaticMeshComponent> mesh(TEXT("StaticMesh'/Engine/BasicShapes/Cylinder.Cylinder'"));
		//ShieldMesh->SetStaticMesh(mesh.Object);
		//ShieldMesh->SetupAttachment(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)), "Shield");

		//Crieria of removal - 1. health = 0, 2. time = 0, 3. pickup new ability
	}
}
