#include "Main.hpp"
#include "CustomTypes/SettingsFlowCoordinator.hpp"

#include "HMUI/ViewController_AnimationDirection.hpp"

DEFINE_TYPE(SRM, SettingsFlowCoordinator);

using namespace SRM;

void SettingsFlowCoordinator::DidActivate(DA_ARGS) {
    // present settings, blacklists, and filters view controllers
}

void SettingsFlowCoordinator::BackButtonWasPressed(HMUI::ViewController* topViewController) {
    parentFlowCoordinator->DismissFlowCoordinator(this, HMUI::ViewController::AnimationDirection::Horizontal, nullptr, false);
}
