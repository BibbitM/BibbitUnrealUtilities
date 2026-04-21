// Copyright BIBBIT Michal Nowak.

using UnrealBuildTool;

public class BibbitUtilities : ModuleRules
{
	public BibbitUtilities(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicIncludePaths.AddRange([]);

		PrivateIncludePaths.AddRange([]);

		PublicDependencyModuleNames.AddRange([
			"Core",
			"CoreUObject",
			"Engine"
		]);

		PrivateDependencyModuleNames.AddRange([]);

		DynamicallyLoadedModuleNames.AddRange([]);
	}
}
