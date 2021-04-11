// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "Components/TextBlock.h"
#include "Components/Button.h"

#include "Containers/UnrealString.h"


#include "W_ErrorWindow.generated.h"

/**
 * 
 */
UCLASS()
class GAME259PROD_SECB_API UW_ErrorWindow : public UUserWidget
{
	GENERATED_BODY()


public:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* ErrorText;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		UButton* OKButton;



	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void SetMessage(const FString& IncomingMessage);

};
