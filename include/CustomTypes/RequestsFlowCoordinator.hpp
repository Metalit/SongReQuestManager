#pragma once

#include "custom-types/shared/macros.hpp"

#include "HMUI/ViewController.hpp"
#include "HMUI/FlowCoordinator.hpp"

#define METHOD(...) il2cpp_utils::il2cpp_type_check::MetadataGetter<&__VA_ARGS__>::get()

DECLARE_CLASS_CODEGEN(SRM, RequestsFlowCoordinator, HMUI::FlowCoordinator,

    DECLARE_OVERRIDE_METHOD(void, DidActivate, METHOD(HMUI::FlowCoordinator::DidActivate), bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling);
    DECLARE_OVERRIDE_METHOD(void, BackButtonWasPressed, METHOD(HMUI::FlowCoordinator::BackButtonWasPressed), HMUI::ViewController* topViewController);
)