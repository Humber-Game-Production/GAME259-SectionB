// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "S_PlayerInfo.h"
#include "AdvancedSessionsLibrary.h"
#include "BPI_GameInstance.generated.h"


// This class does not need to be modified.
UINTERFACE()
class UBPI_GameInstance : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GAME259PROD_SECB_API IBPI_GameInstance
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interface")
		 void JoinServer(FBlueprintSessionResult SessionToJoin);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interface")
		 void UpdateFriendList(FBPFriendInfo FriendInfo, UTexture2D* Avatar);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interface")
		void ShowMainMenu();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interface")
		void ShowHostMenu();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interface")
		void ShowServerMenu();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interface")
		void ShowOptionsMenu();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interface")
		void LaunchLobby(int32 NumberOfPlayers_, bool EnableLan_, const FText& ServerName_, const FString& GameID_, bool InLobby_);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interface")
		void ShowLoadingScreen();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interface")
		void DestroySessionCaller(APlayerController* playerController);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interface")
		class USteamGameInstance* SteamGameInstanceRef();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interface")
		void SavePlayerInfo(FS_PlayerInfo& PlayerInfo_);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interface")
		FS_PlayerInfo GetPlayerInfo();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interface")
		void MainMenuPlayerInfo();

	
};
