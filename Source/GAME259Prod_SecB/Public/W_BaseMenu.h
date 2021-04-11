// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "Components/Button.h"
#include "Components/ScrollBox.h"
#include "Components/VerticalBox.h"
#include "Components/Image.h"
#include "Components/HorizontalBox.h"
#include "Components/TextBlock.h"

#include "W_BaseMenu.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateTest, int, MenuIndex);

UCLASS()
class GAME259PROD_SECB_API UW_BaseMenu : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintAssignable,BlueprintCallable)
		FDelegateTest TransitionToLinkedMenu;
	
};
