// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "Components/Image.h"
#include "Components/CircularThrobber.h"
#include "Components/TextBlock.h"



#include "W_LoadingScreen.generated.h"

/**
 * 
 */
UCLASS()
class GAME259PROD_SECB_API UW_LoadingScreen : public UUserWidget
{
	GENERATED_BODY()
	

public:

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* TipText;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		UImage* MapImage;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		UCircularThrobber* Loading;
};
