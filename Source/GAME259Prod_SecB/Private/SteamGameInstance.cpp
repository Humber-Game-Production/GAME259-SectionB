// Fill out your copyright notice in the Description page of Project Settings.

#include "SteamGameInstance.h"

void USteamGameInstance::LaunchLobby_Implementation(int32  NumberOfPlayers_, bool EnableLan_, const FText& ServerName_, const FString& GameID_, bool InLobby_) 
{
	SetLobbySettings(NumberOfPlayers_, ServerName_, GameID_, EnableLan_, InLobby_);

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


void USteamGameInstance::ToggleNumPlayers(int32 NumPlayers_)
{
	for (auto setting : ServerSettings)
	{
		if (setting.Key == FName("NumPlayers"))
		{
			setting.Data.SetValue(NumPlayers_);
		}

	}
	UUpdateSessionCallbackProxyAdvanced::UpdateSession(GetWorld(), ServerSettings, MaxPlayers, MaxPlayers, EnableLan);
}

void USteamGameInstance::ToggleInLobby(bool InLobby_)
{
	for (auto setting : ServerSettings)
	{
		if (setting.Key == FName("InLobby"))
		{
			setting.Data.SetValue(InLobby_);
		}

	}

	UUpdateSessionCallbackProxyAdvanced::UpdateSession(GetWorld(), ServerSettings, MaxPlayers, MaxPlayers, EnableLan);
}

void USteamGameInstance::ToggleMapName(FText MapName_)
{
	for (auto setting : ServerSettings)
	{
		if (setting.Key == FName("MapName"))
		{
			setting.Data.SetValue(MapName_.ToString());
		}

	}
	UUpdateSessionCallbackProxyAdvanced::UpdateSession(GetWorld(), ServerSettings, MaxPlayers, MaxPlayers, EnableLan);
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

FString USteamGameInstance::TravelErrorToString(ENetworkFailure::Type FailureType)
{
	FString ErrorString;


	return ErrorString.Append(StaticEnum<ENetworkFailure::Type>()->GetNameStringByValue(FailureType));
}

void USteamGameInstance::JoinServer_Implementation(FBlueprintSessionResult SessionToJoin)
{
	CurrentSession = SessionToJoin;
	ShowLoadingScreen();

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

void USteamGameInstance::SavePlayerInfo_Implementation(FS_PlayerInfo& PlayerInfo_)
{
	PlayerInfo = PlayerInfo_;
}

FS_PlayerInfo USteamGameInstance::GetPlayerInfo_Implementation()
{
	return PlayerInfo;
}

