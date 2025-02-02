// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ThroughTheFallout : ModuleRules
{
    public ThroughTheFallout(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "GameplayAbilities" });

        PrivateDependencyModuleNames.AddRange(new string[] { "GameplayTags", "GameplayTasks" ,"Niagara"});
    }
}
