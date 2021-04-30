#include "../Public/HealOverTime.h"
#include "../GAME259Prod_SecBCharacter.h"

UHealOverTime::UHealOverTime() {

	imagePath = "/Game/ProjectAmulet/Art/EffectIcons/Health";
}

UHealOverTime::~UHealOverTime()
{

}

void UHealOverTime::Apply()
{
	GetWorld()->GetTimerManager().SetTimer(tickTimer, this, &UHealOverTime::TickEffect, 1.0f, true);
}

void UHealOverTime::TickEffect() {
	//Heal player

	Cast<AGAME259Prod_SecBCharacter>(GetOuter())->ChangeHealth(1.0f);
}

void UHealOverTime::Remove()
{

}

