// Fill out your copyright notice in the Description page of Project Settings.
#include "Effect.h"
#include "MatchPlayerState.h"


UEffect::UEffect()
{
	
}

UEffect::~UEffect()
{
	//delete(effectIcon);
}

void UEffect::Start(bool isTimed, float duration) {

	Apply();

	if (isTimed) {
		GetWorld()->GetTimerManager().SetTimer(Timer, this, &UEffect::Remove, duration, false);
	}
}

void UEffect::Apply() {
	FSlateBrush imageBrush{};
	imageBrush.ImageSize = FVector2D{ 100.0f,100.0f };

	//Insert texture link.
	UTexture2D* texture = Cast<UTexture2D>(StaticLoadObject(UTexture2D::StaticClass(), nullptr, *imagePath));
	imageBrush.SetResourceObject(texture);
	effectIcon = NewObject<UImage>();

	effectIcon->SetBrush(imageBrush);

	//Test changing this to Match player state
	Cast<AMatchPlayerState>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0)->GetPlayerState())->GetEffectBox()->AddChildToHorizontalBox(effectIcon);
}

void UEffect::Remove() {
	//Generic Remove stuff here

	effectIcon->RemoveFromParent();

	//Clear everything
}


