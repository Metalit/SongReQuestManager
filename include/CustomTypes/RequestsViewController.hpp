#pragma once

#include "TypeUtil.hpp"
#include "UIUtil.hpp"

#include "HMUI/ViewController.hpp"

DECLARE_CLASS_CODEGEN(SRM, RequestsViewController, HMUI::ViewController,

    DECLARE_OVERRIDE_METHOD(void, DidActivate, METHOD(HMUI::ViewController::DidActivate), DA_ARGS);
)
