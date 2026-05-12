// Copyright BIBBIT Michal Nowak.

#pragma once

#include "Modules/ModuleInterface.h"

class FBibbitUtilitiesEditorModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

protected:
	void RegisterDetailsCustomizationButton();
	void UnregisterDetailsCustomizationButton();
};
