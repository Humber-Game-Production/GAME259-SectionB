// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/PlayerController.h"
#include "AdvancedSessionsLibrary.h"
#include "S_PlayerInfo.h"
#include "BPI_LobbyGM.h"
#include "LobbyGM.generated.h"

class UTexture2D;
UCLASS()
class GAME259PROD_SECB_API ALobbyGM : public AGameModeBase, public IBPI_LobbyGM
{
	GENERATED_BODY()


public:
	APlayerController* ConnectedPlayer;

	TArray<APlayerController*> ConnectedPlayers;

	TArray<FSessionPropertyKeyPair*> Settings;

	TArray<FS_PlayerInfo> ConnectedPlayerInfos;

	FText ServerName;

	FText SelectedMapName;

	FText SelectedMapTime;

	int CurrentPlayers;

	int MaxPlayers;

	int SelectedMapID;

	UTexture2D* SelectedMapImage;

	bool CanWeStart;



public:
	ALobbyGM();
	~ALobbyGM();

	virtual void BeginPlay() override;
	
	virtual void PostLogin(APlayerController* newPlayer) override;

	virtual void Logout(AController* exitingController);

public:
	UFUNCTION(BlueprintCallable)
	void HostUpdateGameSettings(UTexture2D* SelectedMapImage_, FText& SelectedMapName_, FText& SelectedMapTime_, int SelectedMapID_);
	
	UFUNCTION(BlueprintCallable)
	void PlayerKicked(const int PlayerID);

	UFUNCTION(BlueprintCallable)
	void EveryoneUpdate();

	UFUNCTION(BlueprintCallable)
	void AddToKickList();

	UFUNCTION(BlueprintCallable)
	void StartLoadingScreen();

	UFUNCTION(Server, Reliable,BlueprintCallable)
	void UpdateServerPlayers(const int NumPlayers);


	UFUNCTION(Server, Reliable,BlueprintCallable)
	void UpdateInLobby(bool InLobby);


	ALobbyGM* GetLobbyGMRef_Implementation() override;

private:

	void LaunchGame();

	void LaunchUniqueGame(const int ID);
	

};
