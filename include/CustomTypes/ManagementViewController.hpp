#pragma once

#include "TypeUtil.hpp"

#include "HMUI/ViewController.hpp"

DECLARE_CLASS_CODEGEN(SRM, ManagementViewController, HMUI::ViewController,

    DECLARE_OVERRIDE_METHOD(void, DidActivate, METHOD(HMUI::ViewController::DidActivate), bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling);
)