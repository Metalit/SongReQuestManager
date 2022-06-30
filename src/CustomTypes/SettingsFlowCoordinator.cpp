#include "Main.hpp"
#include "CustomTypes/SettingsFlowCoordinator.hpp"

#include "CustomTypes/SettingsViewController.hpp"
#include "CustomTypes/FiltersViewController.hpp"
#include "CustomTypes/BlacklistViewController.hpp"

#include "HMUI/ViewController_AnimationDirection.hpp"
#include "HMUI/ViewController_AnimationType.hpp"

DEFINE_TYPE(SRM, SettingsFlowCoordinator);

using namespace SRM;

void SettingsFlowCoordinator::DidActivate(DA_ARGS) {
    if(addedToHierarchy)
        ProvideInitialViewControllers(GET_SINGLETON(SettingsViewController), GET_SINGLETON(FiltersViewController), GET_SINGLETON(BlacklistViewController), nullptr, nullptr);
    set_showBackButton(true);
    SetTitle("SRM Settings", HMUI::ViewController::AnimationType::In);
}

void SettingsFlowCoordinator::BackButtonWasPressed(HMUI::ViewController* topViewController) {
    parentFlowCoordinator->DismissFlowCoordinator(this, HMUI::ViewController::AnimationDirection::Horizontal, nullptr, false);
}
