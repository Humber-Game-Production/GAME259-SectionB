// Fill out your copyright notice in the Description page of Project Settings.

#include "AbilityShield.h"
#include "Kismet/GameplayStatics.h"
#include "Shield.h"
#include "../GAME259Prod_SecBCharacter.h"

AAbilityShield::AAbilityShield(const FObjectInitializer& ObjectInitializer) {
	type = Type::DEFENSIVE;
	imagePath = "/Game/ProjectAmulet/Art/AbilityIcons/Shield_Icon";
	SetReplicates(true);
}

AAbilityShield::~AAbilityShield()
{
	//Content/ThirdPersonCPP/Blueprints/Shield.uasset
}

void AAbilityShield::Activate_Implementation()
{
	//Internal cool down.
	if (Cast<AGAME259Prod_SecBCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->isShielded == false) {
		//Turn shield on
		Cast<AGAME259Prod_SecBCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->isShielded = true;

		UShield* NewComponent = NewObject<UShield>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0), UShield::StaticClass(), "Shield");
		check(NewComponent);

		FAttachmentTransformRules rules = FAttachmentTransformRules(EAttachmentRule::KeepRelative, false);
		NewComponent->AttachToComponent(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->GetMesh()->GetAttachParent(), rules, "Shield");

		NewComponent->RegisterComponent();

		//Crieria of removal - 1. health = 0, 2. time = 0, 3. pickup new ability
	}
}

bool AAbilityShield::Activate_Validate()
{
	return true;
}

void AAbilityShield::Boom_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, "Booooooom");
}

bool AAbilityShield::Boom_Validate() {
	return true;
}