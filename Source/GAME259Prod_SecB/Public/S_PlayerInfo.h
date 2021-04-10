// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/Texture2D.h"
#include "Internationalization/Text.h"
#include "CoreMinimal.h"
#include "S_PlayerInfo.generated.h"


/**
 * 
 */
USTRUCT(BlueprintType)
struct GAME259PROD_SECB_API FS_PlayerInfo
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText SteamName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText PlayerStatus;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* PlayerImage;



	FS_PlayerInfo()
	{
		SteamName = FText::FromString("");
		PlayerStatus = FText::FromString("");
		PlayerImage = nullptr;
	}


};
