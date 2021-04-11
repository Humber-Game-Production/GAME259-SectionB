// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "W_BaseMenu.h"
#include "SteamGameInstance.h"
#include "Components/EditableTextBox.h"

#include "W_HostMenu.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class GAME259PROD_SECB_API UW_HostMenu : public UW_BaseMenu
{
	GENERATED_BODY()
	
protected:

	UPROPERTY(BlueprintReadWrite)
		int32 NumberOfPlayers;

	UPROPERTY(BlueprintReadWrite)
		int32 MaxPlayers;

	UPROPERTY(BlueprintReadWrite)
		FText PlayModeText;

	UPROPERTY(BlueprintReadWrite)
		FText ServerNameText;

	UPROPERTY(BlueprintReadWrite)
		bool EnableLan;

	UPROPERTY(BlueprintReadWrite)
		bool AcceptIsEnabled;

	UPROPERTY(BlueprintReadWrite)
		 USteamGameInstance* GameInstance;



public:


	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		UButton* AcceptButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		UButton* BackButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		UButton* DecreasePlayers;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		UButton* IncreasePlayers;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UEditableTextBox* ServerName;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		UButton* ToggleLeft;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		UButton* ToggleRight;


};
