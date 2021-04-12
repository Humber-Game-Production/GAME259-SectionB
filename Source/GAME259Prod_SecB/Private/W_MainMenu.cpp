// Fill out your copyright notice in the Description page of Project Settings.


#include "W_MainMenu.h"
#include "Kismet/GameplayStatics.h"


void UW_MainMenu::SetPlayerInfo_Implementation(const FText& Playername, UTexture2D* Texture)
{
	PlayerImage->SetBrushFromTexture(Texture);

	PlayerNameText->SetText(Playername);
}

void UW_MainMenu::UpdateFriendWindow_Implementation(FBPFriendInfo Friend, UTexture2D* Texture2D)
{

}

