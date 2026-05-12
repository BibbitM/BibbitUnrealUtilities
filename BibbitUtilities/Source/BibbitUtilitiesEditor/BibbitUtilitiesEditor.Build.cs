// Copyright BIBBIT Michal Nowak.

using UnrealBuildTool;

public class BibbitUtilitiesEditor : ModuleRules
{
	public BibbitUtilitiesEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicIncludePaths.AddRange([]);

		PrivateIncludePaths.AddRange([]);

		PublicDependencyModuleNames.AddRange([
			"Core"
		]);

		PrivateDependencyModuleNames.AddRange([]);

		DynamicallyLoadedModuleNames.AddRange([]);
	}
}
