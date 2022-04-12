#include "Main.hpp"
#include "CustomTypes/RequestsFlowCoordinator.hpp"

#include "HMUI/ViewController_AnimationDirection.hpp"

DEFINE_TYPE(SRM, RequestsFlowCoordinator);

using namespace SRM;

void RequestsFlowCoordinator::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling) {
    // present management and requests view controllers
}

void RequestsFlowCoordinator::BackButtonWasPressed(HMUI::ViewController* topViewController) {
    parentFlowCoordinator->DismissFlowCoordinator(this, HMUI::ViewController::AnimationDirection::Horizontal, nullptr, false);
}
