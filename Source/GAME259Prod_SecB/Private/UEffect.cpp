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
	//UTexture2D texture;
	//static ConstructorHelpers::FObjectFinder<UTexture2D> texture(TEXT("/Content/StarterContent/Textures/T_Brick_Clay_Beveled_D.uasset"));
	//image->SetBrushFromTexture(&texture);
	widget_->AddChildToHorizontalBox(image);
	widget = widget_;
}


