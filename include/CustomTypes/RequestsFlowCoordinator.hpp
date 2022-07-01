#pragma once

#include "TypeUtil.hpp"
#include "UIUtil.hpp"

DECLARE_CLASS_CUSTOM(SRM, RequestsFlowCoordinator, SRM::FlowCoordinatorSingleton,

    DECLARE_INSTANCE_METHOD(void, DidActivateOverride, DA_ARGS);
    DECLARE_OVERRIDE_METHOD(void, BackButtonWasPressed, METHOD(HMUI::FlowCoordinator::BackButtonWasPressed), HMUI::ViewController* topViewController);
)
