// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UEIntro_Dev_26 : ModuleRules
{
	public UEIntro_Dev_26(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"UEIntro_Dev_26"
		});
	}
}
