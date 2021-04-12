// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "W_BaseMenu.h"
#include "AdvancedSessionsLibrary.h"


#include "Internationalization/Text.h"


#include "W_MainMenu.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class GAME259PROD_SECB_API UW_MainMenu : public UW_BaseMenu
{
	GENERATED_BODY()
	

public:

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		UButton* ControlsButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		UScrollBox* FriendBox;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		UVerticalBox* FriendBoxContainer;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		UButton* PlayButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		UImage* PlayerImage;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		UHorizontalBox* PlayerInfoContainer;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* PlayerNameText;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		UButton* QuitButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		UButton* SettingsButton;


public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		 void SetPlayerInfo(const FText& Playername, UTexture2D* Texture);

	virtual void SetPlayerInfo_Implementation(const FText& Playername, UTexture2D* Texture);


	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		 void UpdateFriendWindow(FBPFriendInfo Friend, UTexture2D* Texture2D);

	virtual void UpdateFriendWindow_Implementation(FBPFriendInfo Friend, UTexture2D* Texture2D);


};
