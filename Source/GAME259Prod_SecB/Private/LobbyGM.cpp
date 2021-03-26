// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGM.h"
#include "Engine/Texture2D.h"




ALobbyGM::ALobbyGM()
{
	// SET THE SERVER NAME AND MAX PLAYERS FROM THE STEAMGAMEINSTANCE AFTER ITS CONVERTED TO C++

}

ALobbyGM::~ALobbyGM()
{

}

void ALobbyGM::BeginPlay()
{

}

void ALobbyGM::PostLogin(APlayerController* newPlayer)
{
	ConnectedPlayer = newPlayer;

	ConnectedPlayers.AddUnique(ConnectedPlayer);

	// GET LOBBY PLAYER CONTROLLER REF AND CALL THE INITIAL SETUP FUNCTION
	
}

void ALobbyGM::Logout(AController* exitingController)
{
	int32 arrayIndex = 0;
	for(auto player : ConnectedPlayers)
	{
		if (player == exitingController) {
			break;
		}
		arrayIndex++;
	}

	ConnectedPlayers.RemoveAt(arrayIndex);
	
	// REMOVE PLAYERS INFO ALSO
	ConnectedPlayerInfos.RemoveAt(arrayIndex);

	EveryoneUpdate();
}

void ALobbyGM::HostUpdateGameSettings(UTexture2D* SelectedMapImage_, FText& SelectedMapName_, FText& SelectedMapTime_, int SelectedMapID_)
{

	SelectedMapImage = SelectedMapImage_;
	SelectedMapName = SelectedMapName_;
	SelectedMapTime = SelectedMapTime_;
	SelectedMapID = SelectedMapID_;

	for (auto player : ConnectedPlayers)
	{
		// GET LOBBY PC REF AND CALL UPDATE LOBBY SETTINGS
	}

}

void ALobbyGM::PlayerKicked(const int PlayerID)
{
	// GET LOBBY PC REF THEN CALL THE KICKED FUNCTION
	//ConnectedPlayers.FindByKey(PlayerID);

}

void ALobbyGM::EveryoneUpdate()
{
	CurrentPlayers = ConnectedPlayers.Num();

	UpdateServerPlayers(CurrentPlayers);

	if (CurrentPlayers > 0)
	{
		ConnectedPlayerInfos.Empty();
		for (auto player : ConnectedPlayers)
		{
			// GET LOBBY PC REF AND ADD EACH PLAYER SETTINGS TO THE CONNECTED PLAYERS INFO TARRAY AND THEN CALL THE UPDATE NUMBER OF PLAYERS THROUGH LOBBY PC REF FUNCTION
		}

		for (auto player : ConnectedPlayers)
		{
			// GET LOBBY PC REF AND CALL THE ADD PLAYER INFO FUNCTION

			AddToKickList();
		}

	}

}

void ALobbyGM::AddToKickList()
{
	// GET LOBBY PC REF AND CALL THE ADD PLAYER TO KICK WINDOW FUNCTION

}

void ALobbyGM::StartLoadingScreen()
{
	for (auto player: ConnectedPlayers)
	{
		// GET LOBBY PC REF AND CALL SHOW LOADING SCREEN


	}
	
	// CRATE FADE WIDGET AND THEN PLAY THE ANIMATION FROM IT AND THE ADD IT TO VIEWPORT

	LaunchGame();
}

void ALobbyGM::UpdateServerPlayers_Implementation(const int NumPlayers)
{
	// GET STEAM GAME INSTANCE REF AND CALL THE TOGGLE NUM PLAYERS FUNCTION
}

void ALobbyGM::UpdateInLobby_Implementation(bool InLobby)
{
	// GET STEAM GAME INSTANCE REF AND CALL THE TOGGLE IN LOBBY FUNCTION

}



void ALobbyGM::LaunchGame()
{

	switch (SelectedMapID)
	{
	case 0:
		GetWorld()->Exec(GetWorld(), TEXT("ServerTravel L_Adventure_JAA_JSH_004"));
		break;
	case 1:
		GetWorld()->Exec(GetWorld(), TEXT("ServerTravel L_Adventure_TSDL_JSH_002"));
		break;
	case 2:
		
		SelectedMapID = FMath::RandRange(0, 1);
		LaunchUniqueGame(SelectedMapID);
		break;
	default:
		break;
	}

}

void ALobbyGM::LaunchUniqueGame(const int ID)
{
	switch (ID)
	{
	case 0:
		GetWorld()->Exec(GetWorld(), TEXT("ServerTravel L_Adventure_JAA_JSH_004"));
		break;
	case 1:
		GetWorld()->Exec(GetWorld(), TEXT("ServerTravel L_Adventure_TSDL_JSH_002"));
		break;
	default:
		break;
	}
}
ALobbyGM* ALobbyGM::GetLobbyGMRef_Implementation() 
{
	return this;
}