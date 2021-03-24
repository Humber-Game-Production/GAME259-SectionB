// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GAME259Prod_SecB : ModuleRules
{
	public GAME259Prod_SecB(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "AdvancedSessions", "AdvancedSteamSessions" });
	}
}
