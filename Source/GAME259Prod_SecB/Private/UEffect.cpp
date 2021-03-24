// Fill out your copyright notice in the Description page of Project Settings.
#include "UEffect.h"

UEffect::UEffect()
{
	isTimed = true;
	duration = 5.0f;
}

UEffect::~UEffect()
{

}

void UEffect::Start() {

	Apply();

	if (isTimed) {
		GetWorld()->GetTimerManager().SetTimer(Timer, this, &UEffect::Remove, duration, false);
	}
}

void UEffect::Apply() {
}

void UEffect::Remove() {
}