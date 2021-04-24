// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilityAmbrosia.h"
#include "BuffAttack.h"
#include "BuffDefense.h"
#include "BuffSpeed.h"
#include "DebuffAttack.h"
#include "DebuffDefense.h"
#include "DebuffSpeed.h"
#include "HealOverTime.h"
#include "../GAME259Prod_SecBCharacter.h"

AAbilityAmbrosia::AAbilityAmbrosia(const FObjectInitializer& ObjectInitializer) {
	//Set values
	floatValue = 25.0f; //Heal amount
	buffTime = 5.0f;
	debuffTime = 2.0f;

	type = Type::DEFENSIVE;

	//Set image path

	imagePath = "/Game/ProjectAmulet/Art/AbilityIcons/Ambrosia_Icon";

}

void AAbilityAmbrosia::ApplyDebuff()
{
	//Apply debuffs here
	UDebuffAttack* deOne = NewObject<UDebuffAttack>(UGameplayStatics::GetPlayerController(GetWorld(), 0), TEXT("AttackDown"));
	UDebuffDefense* deTwo = NewObject<UDebuffDefense>(UGameplayStatics::GetPlayerController(GetWorld(), 0), TEXT("DefenseDown"));
	UDebuffSpeed* deThree = NewObject<UDebuffSpeed>(UGameplayStatics::GetPlayerController(GetWorld(), 0), TEXT("SpeedDown"));

	deOne->Start(true, debuffTime);
	deTwo->Start(true, debuffTime);
	deThree->Start(true, debuffTime);
}

void AAbilityAmbrosia::Activate_Implementation()
{
	//Heal player
	Cast<AGAME259Prod_SecBCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->ChangeHealth(floatValue);

	UHealOverTime* heal = NewObject<UHealOverTime>(UGameplayStatics::GetPlayerController(GetWorld(), 0), TEXT("Healing"));

	//Apply the three Buffs
	UBuffAttack* buffOne = NewObject<UBuffAttack>(UGameplayStatics::GetPlayerController(GetWorld(), 0), TEXT("AttackUp"));
	UBuffDefense* buffTwo = NewObject<UBuffDefense>(UGameplayStatics::GetPlayerController(GetWorld(), 0), TEXT("DefenseUp"));
	UBuffSpeed* buffThree = NewObject<UBuffSpeed>(UGameplayStatics::GetPlayerController(GetWorld(), 0), TEXT("SpeedUp"));

	//Apply time
	buffOne->Start(true, buffTime);
	buffTwo->Start(true, buffTime);
	buffThree->Start(true, buffTime);
	heal->Start(true, 20.0f);

	//Apply Debuff
	FTimerHandle Timing;
	GetWorld()->GetTimerManager().SetTimer(Timing, this, &AAbilityAmbrosia::ApplyDebuff, buffTime, false);
}

bool AAbilityAmbrosia::Activate_Validate()
{
	return true;
}