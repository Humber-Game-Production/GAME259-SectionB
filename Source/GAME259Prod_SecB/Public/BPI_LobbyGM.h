// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "BPI_LobbyGM.generated.h"

/**
 * 
 */
UINTERFACE(BlueprintType)
class GAME259PROD_SECB_API UBPI_LobbyGM : public UInterface
{
	GENERATED_BODY()
};

class GAME259PROD_SECB_API IBPI_LobbyGM {

	GENERATED_BODY()
public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "MyCategory")
		 ALobbyGM* GetLobbyGMRef();

};