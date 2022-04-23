#pragma once

#include "TypeUtil.hpp"

#include "HMUI/FlowCoordinator.hpp"

DECLARE_CLASS_CODEGEN(SRM, SettingsFlowCoordinator, HMUI::FlowCoordinator,

    DECLARE_OVERRIDE_METHOD(void, DidActivate, METHOD(HMUI::FlowCoordinator::DidActivate), bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling);
    DECLARE_OVERRIDE_METHOD(void, BackButtonWasPressed, METHOD(HMUI::FlowCoordinator::BackButtonWasPressed), HMUI::ViewController* topViewController);
)
