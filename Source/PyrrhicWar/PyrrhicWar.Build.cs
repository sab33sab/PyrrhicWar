// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class PyrrhicWar : ModuleRules
{
    public PyrrhicWar(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "Paper2D" });

        PrivateDependencyModuleNames.AddRange(new string[] { });

        PublicIncludePaths.AddRange(new string[]
        {
            "PyrrhicWar/Public/Player",
            "PyrrhicWar/Public/Units",
            "PyrrhicWar/Public/Data",
            "PyrrhicWar/Public/UI",
            "PyrrhicWar/Public/Components",
            "PyrrhicWar/Public/Maps"
        });

        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
    }
}
