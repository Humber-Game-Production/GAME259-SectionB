// Fill out your copyright notice in the Description page of Project Settings.
#include "Effect.h"
#include "MatchPlayerState.h"


UEffect::UEffect()
{

}

UEffect::~UEffect()
{
	delete(effectIcon);
}

void UEffect::Start(bool isTimed, float duration) {

	Apply();

	if (isTimed) {
		GetWorld()->GetTimerManager().SetTimer(Timer, this, &UEffect::Remove, duration, false);
	}
}

void UEffect::Apply() {
	//icon should be replaced by the TSoftObjectPtr<UTexture2D> / or what else can be used to get the image
	FSlateBrush imageBrush{};
	imageBrush.ImageSize = FVector2D{ 6.0f,6.0f };

	
	//Insert texture link.
	UTexture2D* texture = Cast<UTexture2D>(StaticLoadObject(UTexture2D::StaticClass(), NULL, *(imagePath)));
	imageBrush.SetResourceObject(texture);
	effectIcon = NewObject<UImage>();

	effectIcon->SetBrush(imageBrush);
	
	Cast<AMatchPlayerState>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0)->GetPlayerState())->GetEffectBox()->AddChildToHorizontalBox(effectIcon);

	//UTexture2D texture;
	//static ConstructorHelpers::FObjectFinder<UTexture2D> texture(TEXT("/Content/StarterContent/Textures/T_Brick_Clay_Beveled_D.uasset"));
	//image->SetBrushFromTexture(&texture);
	//widget = widget_;

	//NewObject<>(UGameplayStatics::GetPlayerController(GetWorld(), 0), FName("Attack"));
}

void UEffect::Remove() {
	//Generic Remove stuff here

	effectIcon->RemoveFromParent();

	//Clear everything
}


