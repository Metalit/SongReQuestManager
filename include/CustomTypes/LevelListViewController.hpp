#pragma once

#include "TypeUtil.hpp"
#include "UIUtil.hpp"

DECLARE_CLASS_CUSTOM(SRM, LevelListViewController, SRM::ViewControllerSingleton,

    DECLARE_OVERRIDE_METHOD(void, DidActivate, METHOD(HMUI::ViewController::DidActivate), DA_ARGS);
)
