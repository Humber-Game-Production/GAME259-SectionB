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
	//Content/ThirdPersonCPP/Blueprints/Shield.uasset
}

void UAbilityShield::Activate()
{
	//Internal cool down.
	if (Cast<AGAME259Prod_SecBCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->isShielded == false) {
		//Turn shield on
		Cast<AGAME259Prod_SecBCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->isShielded = true;

		UShield* NewComponent = NewObject<UShield>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0), UShield::StaticClass(), "Shield");
		check(NewComponent);

		NewComponent->AttachTo(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->GetMesh()->GetAttachParent(), "Shield");

		NewComponent->RegisterComponent();

		//Crieria of removal - 1. health = 0, 2. time = 0, 3. pickup new ability
	}
}
