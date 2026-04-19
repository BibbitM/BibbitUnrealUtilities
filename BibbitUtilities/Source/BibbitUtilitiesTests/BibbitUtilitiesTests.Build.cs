// Copyright BIBBIT Michal Nowak.

using UnrealBuildTool;

public class BibbitUtilitiesTests : ModuleRules
{
	public BibbitUtilitiesTests(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicIncludePaths.AddRange([]);

		PrivateIncludePaths.AddRange([]);

		PublicDependencyModuleNames.AddRange(["BibbitUtilities", "Core"]);

		PrivateDependencyModuleNames.AddRange([]);

		DynamicallyLoadedModuleNames.AddRange([]);
	}
}
