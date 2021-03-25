// Fill out your copyright notice in the Description page of Project Settings.
#include "UEffect.h"

UEffect::UEffect()
{

}

UEffect::~UEffect()
{

}

void UEffect::Start(bool isTimed, float duration) {

	Apply();

	if (isTimed) {
		GetWorld()->GetTimerManager().SetTimer(Timer, this, &UEffect::Remove, duration, false);
	}
}

void UEffect::Apply() {
}

void UEffect::Remove() {
}

void UEffect::SetupImage(UHorizontalBox* widget_)
{
	UImage* image = NewObject<UImage>(UImage::StaticClass());
	widget_->AddChildToHorizontalBox(image);
}


