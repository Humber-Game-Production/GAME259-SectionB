// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilityAmbrosia.h"
#include "BuffAttack.h"
#include "BuffDefense.h"
#include "BuffSpeed.h"
#include "DebuffAttack.h"
#include "DebuffDefense.h"
#include "DebuffSpeed.h"

UAbilityAmbrosia::UAbilityAmbrosia(const FObjectInitializer& ObjectInitializer) {
	//Set time's here
	floatValue = 5.0f;
	debuffTime = 2.0f;

	type = Type::DEFENSIVE;
}

UAbilityAmbrosia::~UAbilityAmbrosia()
{
}

void UAbilityAmbrosia::Activate()
{
	//Apply the three Buffs
	UBuffAttack* buffOne = NewObject<UBuffAttack>(UGameplayStatics::GetPlayerController(GetWorld(), 0), TEXT("Attack"));
	UBuffDefense* buffTwo = NewObject<UBuffDefense>(UGameplayStatics::GetPlayerController(GetWorld(), 0), TEXT("Defense"));
	UBuffSpeed* buffThree = NewObject<UBuffSpeed>(UGameplayStatics::GetPlayerController(GetWorld(), 0), TEXT("Speed"));

	//Apply time
	buffOne->Start(false, floatValue);
	buffTwo->Start(false, floatValue);
	buffThree->Start(false, floatValue);

	//Apply Debuff
	FTimerHandle Timing;
	GetWorld()->GetTimerManager().SetTimer(Timing, this, &UAbilityAmbrosia::ApplyDebuff, 3.0f, false);
}

void UAbilityAmbrosia::ApplyDebuff()
{
	//Apply debuffs here
	UDebuffAttack* deOne = NewObject<UDebuffAttack>(UGameplayStatics::GetPlayerController(GetWorld(), 0), TEXT("Attack"));
	UDebuffDefense* deTwo = NewObject<UDebuffDefense>(UGameplayStatics::GetPlayerController(GetWorld(), 0), TEXT("Defense"));
	UDebuffSpeed* deThree = NewObject<UDebuffSpeed>(UGameplayStatics::GetPlayerController(GetWorld(), 0), TEXT("Speed"));

	deOne->Start(false, debuffTime);
	deTwo->Start(false, debuffTime);
	deThree->Start(false, debuffTime);
}
