// Fill out your copyright notice in the Description page of Project Settings.

#include "SteamGameInstance.h"
#include "W_HostMenu.h"

void USteamGameInstance::LaunchLobby_Implementation(int32  NumberOfPlayers_, bool EnableLan_, const FText& ServerName_, const FString& GameID_, bool InLobby_) 
{

	TArray<FSessionPropertyKeyPair> properties;
	
	properties.Emplace(UAdvancedSessionsLibrary::MakeLiteralSessionPropertyString("ServerName", ServerName.ToString()));
	properties.Emplace(UAdvancedSessionsLibrary::MakeLiteralSessionPropertyString("MaxPlayers", FString::FromInt(MaxPlayers)));
	properties.Emplace(UAdvancedSessionsLibrary::MakeLiteralSessionPropertyString("GameID", GameID));
	properties.Emplace(UAdvancedSessionsLibrary::MakeLiteralSessionPropertyString("MapName", MapName.ToString()));
	properties.Emplace(UAdvancedSessionsLibrary::MakeLiteralSessionPropertyBool("InLobby", InLobby));
	properties.Emplace(UAdvancedSessionsLibrary::MakeLiteralSessionPropertyInt("NumPlayers", NumPlayers));


	ServerSettings = properties;
	
	 UCreateSessionCallbackProxyAdvanced::CreateAdvancedSession(GetWorld(), ServerSettings, UGameplayStatics::GetPlayerController(GetWorld(), 0), 100, MaxPlayers, EnableLan);

	
	UGameplayStatics::OpenLevel(GetWorld(), FName("ThirdPersonExampleMap"), true, FString("?listen"));


}



void USteamGameInstance::Init()
{

}

void USteamGameInstance::SetLobbySettings(int32  MaxPlayers_, FText ServerName_, FString GameID_, bool EnableLan_, bool InLobby_, int32  NumPlayers_, FText MapName_)
{
	MaxPlayers = MaxPlayers_;
	ServerName = ServerName_;
	GameID = GameID_;
	EnableLan = EnableLan_;
	InLobby = InLobby_;
	NumPlayers = NumPlayers_;
	MapName = MapName_;

}







FString USteamGameInstance::NetErrorToString(ENetworkFailure::Type FailureType)
{
	
	FString ErrorString;
	switch (FailureType)
	{
	case ENetworkFailure::NetDriverAlreadyExists:
	case ENetworkFailure::NetDriverCreateFailure:
	case ENetworkFailure::NetDriverListenFailure:
	case ENetworkFailure::ConnectionLost:
	case ENetworkFailure::FailureReceived:
	case ENetworkFailure::OutdatedClient:
	case ENetworkFailure::OutdatedServer:
	case ENetworkFailure::PendingConnectionFailure:
		ErrorString = "Error: Lost Connecttion To Host";
		break;
	case ENetworkFailure::ConnectionTimeout:
		ErrorString = "Error: Connection Timed Out";
		break;
	default:
		break;
	}

	return ErrorString;
}

FString USteamGameInstance::TravelErrorToString(ETravelFailure::Type FailureType)
{
	FString ErrorString;


	return ErrorString.Append(StaticEnum<ENetworkFailure::Type>()->GetNameStringByValue(FailureType));
}



void USteamGameInstance::UpdateFriendList_Implementation(FBPFriendInfo FriendInfo, UTexture2D* Avatar)
{
	if (MainMenu != nullptr)
	{
		MainMenu->UpdateFriendWindow(FriendInfo, Avatar);
	}
}

void USteamGameInstance::MainMenuPlayerInfo_Implementation()
{
	if (MainMenu != nullptr)
	{
		MainMenu->SetPlayerInfo(PlayerInfo.SteamName, PlayerInfo.PlayerImage);
	}
}

void USteamGameInstance::ShowLoadingScreen_Implementation()
{
	LoadingScreen = Cast<UW_LoadingScreen>(CreateWidget(UGameplayStatics::GetPlayerController(GetWorld(), 0), UW_LoadingScreen::StaticClass()));

	LoadingScreen->AddToViewport();
}

void USteamGameInstance::ShowHostMenu_Implementation()
{
	HostMenu = Cast<UW_HostMenu>(CreateWidget(UGameplayStatics::GetPlayerController(GetWorld(), 0), UW_HostMenu::StaticClass()));

	HostMenu->AddToViewport();
}

void USteamGameInstance::ShowMainMenu_Implementation()
{
	//MainMenu = Cast<UW_MainMenu>(CreateWidget(UGameplayStatics::GetPlayerController(GetWorld(), 0), UW_MainMenu::StaticClass()));

	//MainMenu->AddToViewport();
}

void USteamGameInstance::ShowOptionsMenu_Implementation()
{
	
}

void USteamGameInstance::ShowServerMenu_Implementation()
{

}



void USteamGameInstance::JoinServer_Implementation(FBlueprintSessionResult SessionToJoin)
{
	CurrentSession = SessionToJoin;
	IBPI_GameInstance::Execute_ShowLoadingScreen(this);

	JoinSession(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetLocalPlayer(), CurrentSession.OnlineResult);
}


void USteamGameInstance::DestroySessionCaller_Implementation(APlayerController* playerController)
{

	IOnlineSubsystem* const OnlineSub = IOnlineSubsystem::Get();

	IOnlineSessionPtr Sessions = OnlineSub->GetSessionInterface();

	Sessions->DestroySession(FName(ServerName.ToString()));
}

USteamGameInstance* USteamGameInstance::SteamGameInstanceRef_Implementation()
{
	return this;
}

void USteamGameInstance::SavePlayerInfo_Implementation(FS_PlayerInfo PlayerInfo_)
{
	PlayerInfo = PlayerInfo_;
}

FS_PlayerInfo USteamGameInstance::GetPlayerInfo_Implementation()
{
	return PlayerInfo;
}

