// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "AdvancedSessionsLibrary.h"


#include "W_Friend.generated.h"

/**
 * 
 */
UCLASS()
class GAME259PROD_SECB_API UW_Friend : public UUserWidget
{
	GENERATED_BODY()

public:


	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		UImage* FriendImage;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* FriendName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FBPFriendInfo friendInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTexture2D* Avatar;

	void UpdateInfo(FBPFriendInfo friendInfo_, UTexture2D* Avatar_);



};

