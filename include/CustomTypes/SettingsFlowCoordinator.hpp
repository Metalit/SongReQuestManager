#pragma once

#include "TypeUtil.hpp"
#include "UIUtil.hpp"

DECLARE_CLASS_CUSTOM(SRM, SettingsFlowCoordinator, SRM::FlowCoordinatorSingleton,

    DECLARE_OVERRIDE_METHOD(void, DidActivate, METHOD(HMUI::FlowCoordinator::DidActivate), DA_ARGS);
    DECLARE_OVERRIDE_METHOD(void, BackButtonWasPressed, METHOD(HMUI::FlowCoordinator::BackButtonWasPressed), HMUI::ViewController* topViewController);
)
