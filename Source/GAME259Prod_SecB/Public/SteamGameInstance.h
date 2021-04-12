// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BPI_GameInstance.h"

#include "W_MainMenu.h"
#include "W_LoadingScreen.h"
#include "W_ErrorWindow.h"


#include "AdvancedFriendsGameInstance.h"
#include "AdvancedSessionsLibrary.h"
#include "CreateSessionCallbackProxyAdvanced.h"
#include "UpdateSessionCallbackProxyAdvanced.h"

#include "Kismet/GameplayStatics.h"
#include "Engine/EngineBaseTypes.h"
#include "EngineUtils.h"

#include "SteamGameInstance.generated.h"



/**
 * 
 */
 

UCLASS()
class GAME259PROD_SECB_API USteamGameInstance : public UAdvancedFriendsGameInstance ,public IBPI_GameInstance
{
	GENERATED_BODY()

public:



	//Store's the current session that the server is connected too
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category = "Server Config")
		FBlueprintSessionResult CurrentSession;

	//Store's the ServerSettings that are being used
	 UPROPERTY(VisibleAnywhere,BlueprintReadWrite, Category = "Server Config")
		TArray<FSessionPropertyKeyPair> ServerSettings;
	
	 UPROPERTY(BlueprintReadWrite, Category = "Widgets")
		 UW_MainMenu*  MainMenu;

	 UPROPERTY(BlueprintReadWrite, Category = "Widgets")
		 class UW_HostMenu* HostMenu;

	 UPROPERTY(BlueprintReadWrite, Category = "Widgets")
		  UW_LoadingScreen* LoadingScreen;

	 UPROPERTY(BlueprintReadWrite, Category = "Widgets")
		 UW_ErrorWindow* ErrorWindow;

	// Store's the max players in the server 
	UPROPERTY(BlueprintReadOnly, Category = "Server Config")
		int32  MaxPlayers;

	// Store's the current selected/being played map of the server 
	UPROPERTY(BlueprintReadOnly, Category = "Server Config")
		FText MapName;
	
	// Store's the servers name
	UPROPERTY(BlueprintReadOnly, Category = "Server Config")
		FText ServerName;

	// Store's the players info that is connected to the gameinstance
	UPROPERTY(BlueprintReadOnly, Category = "Server Config")
		FS_PlayerInfo PlayerInfo;


	//Store's the unique ID that servers connected to this game used
	UPROPERTY(BlueprintReadOnly, Category = "Server Config")
		FString GameID;

	//Keeps track of if the players are in the lobby or in game 
	UPROPERTY(BlueprintReadOnly, Category = "Server Config")
		bool InLobby;

	//Keeps track of if the server is Lan or Internet server
	UPROPERTY(BlueprintReadOnly, Category = "Server Config")
		bool EnableLan;

	//Store's the current amount of players in the server
	UPROPERTY(BlueprintReadOnly, Category = "Server Config")
		int32 NumPlayers;

public:

	virtual void Init() override;


	UFUNCTION(BlueprintCallable, Category = "Helper Functions")
		void SetLobbySettings(int32  MaxPlayers_,FText ServerName_, FString GameID_, bool EnableLan_, bool InLobby_, int32  NumPlayers_ ,FText MapName_);

	UFUNCTION(BlueprintCallable, Category = "Server Functions")
		void ToggleNumPlayers(int32 NumPlayers_);

	UFUNCTION(BlueprintCallable, Category = "Server Functions")
		void ToggleInLobby(bool InLobby_);

	UFUNCTION(BlueprintCallable, Category = "Server Functions")
		void ToggleMapName(FText MapName_);

	UFUNCTION(BlueprintCallable, Category = "Error Functions")
		FString NetErrorToString(ENetworkFailure::Type FailureType);

	UFUNCTION(BlueprintCallable, Category = "Error Functions")
		FString TravelErrorToString(ETravelFailure::Type FailureType);

	

public:

	/*INTERFACE FUNCTIONS*/
	
	void ShowMainMenu_Implementation() override;

	void ShowHostMenu_Implementation() override;

	void ShowServerMenu_Implementation() override;

	void ShowOptionsMenu_Implementation() override;

	void ShowLoadingScreen_Implementation()override;


	void MainMenuPlayerInfo_Implementation() override;


	// Joins into the server with a specific session 
	 void JoinServer_Implementation(FBlueprintSessionResult SessionToJoin) override;

	// Launches a advanced sessions lobby with the specific parameters 
	void LaunchLobby_Implementation(int32 NumberOfPlayers_, bool EnableLan_, const FText& ServerName_, const FString& GameID_, bool InLobby_) override;

	// Removes a specific playercontroller from the session
	void DestroySessionCaller_Implementation(APlayerController* playerController) override;

	// Gets a reference to this game instance
	USteamGameInstance* SteamGameInstanceRef_Implementation() override;

	//Set's the player's info to the playerinfo passed in the parameters 
	void SavePlayerInfo_Implementation(FS_PlayerInfo PlayerInfo_) override;

	//Returns the players info
	FS_PlayerInfo GetPlayerInfo_Implementation() override;

	void UpdateFriendList_Implementation(FBPFriendInfo FriendInfo, UTexture2D* Avatar) override;



	/*INTERFACE FUNCTIONS*/
};

	

