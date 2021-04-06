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

void UEffect::SetupImage(UHorizontalBox* widget_,TSoftObjectPtr<UTexture2D> icon)
{
	FSlateBrush imageBrush{};
	imageBrush.ImageSize = FVector2D{ 6.0f,6.0f };
	imageBrush.SetResourceObject(icon.LoadSynchronous());
	UImage* win = NewObject<UImage>();

	win->SetBrush(imageBrush);
	
	//UTexture2D texture;
	//static ConstructorHelpers::FObjectFinder<UTexture2D> texture(TEXT("/Content/StarterContent/Textures/T_Brick_Clay_Beveled_D.uasset"));
	//image->SetBrushFromTexture(&texture);
	widget_->AddChildToHorizontalBox(win);
	//widget = widget_;
}


