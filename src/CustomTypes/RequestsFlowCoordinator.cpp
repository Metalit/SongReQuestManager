#include "Main.hpp"
#include "CustomTypes/RequestsFlowCoordinator.hpp"

#include "CustomTypes/RequestsNavigationController.hpp"
#include "CustomTypes/ManagementViewController.hpp"
#include "CustomTypes/DownloadToPlaylistViewController.hpp"

#include "HMUI/ViewController_AnimationDirection.hpp"
#include "HMUI/ViewController_AnimationType.hpp"

DEFINE_TYPE(SRM, RequestsFlowCoordinator);

using namespace SRM;

void RequestsFlowCoordinator::DidActivate(DA_ARGS) {
    if(addedToHierarchy)
        ProvideInitialViewControllers(GET_SINGLETON(RequestsNavigationController), GET_SINGLETON(ManagementViewController), GET_SINGLETON(DownloadToPlaylistViewController), nullptr, nullptr);
    set_showBackButton(true);
    SetTitle("Song Request Manager", HMUI::ViewController::AnimationType::In);
}

void RequestsFlowCoordinator::BackButtonWasPressed(HMUI::ViewController* topViewController) {
    parentFlowCoordinator->DismissFlowCoordinator(this, HMUI::ViewController::AnimationDirection::Horizontal, nullptr, false);
}
