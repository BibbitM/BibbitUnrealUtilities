// Copyright BIBBIT Michal Nowak.

#include "BibbitUtilitiesEditor.h"

#include "PropertyEditorModule.h"
#include "Modules/ModuleManager.h"

#define LOCTEXT_NAMESPACE "BibbitUtilitiesEditorModule"

void FBibbitUtilitiesEditorModule::StartupModule()
{
	// We want to register any editor visual extension only in the interactive mode.
	// In commandlet mode, we want to save CPU cycles, e.g., by skipping the loading of dependent modules.
	if (!IsRunningCommandlet())
	{
		RegisterDetailsCustomizationButton();
	}
}

void FBibbitUtilitiesEditorModule::ShutdownModule()
{
	if (!IsRunningCommandlet())
	{
		UnregisterDetailsCustomizationButton();
	}
}

void FBibbitUtilitiesEditorModule::RegisterDetailsCustomizationButton()
{
	// Add the "Bibbit" filter button to property widgets for all actors and components.
	FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
	{
		TSharedRef<FPropertySection> Section = PropertyModule.FindOrCreateSection("Actor", "Bibbit", LOCTEXT("BibbitSection", "Bibbit"));
		Section->AddCategory("Bibbit");
	}
	{
		TSharedRef<FPropertySection> Section = PropertyModule.FindOrCreateSection("ActorComponent", "Bibbit", LOCTEXT("BibbitSection", "Bibbit"));
		Section->AddCategory("Bibbit");
	}
	PropertyModule.NotifyCustomizationModuleChanged();
}

void FBibbitUtilitiesEditorModule::UnregisterDetailsCustomizationButton()
{
	if (FModuleManager::Get().IsModuleLoaded(TEXT("PropertyEditor")))
	{
		FPropertyEditorModule& PropertyModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");
		PropertyModule.RemoveSection("Actor", "Bibbit");
		PropertyModule.RemoveSection("ActorComponent", "Bibbit");
		PropertyModule.NotifyCustomizationModuleChanged();
	}
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FBibbitUtilitiesEditorModule, BibbitUtilitiesEditor)
