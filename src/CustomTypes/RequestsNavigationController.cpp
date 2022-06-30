#include "Main.hpp"
#include "CustomTypes/RequestsNavigationController.hpp"

#include "CustomTypes/RequestsHeaderViewController.hpp"
#include "CustomTypes/LevelsNavigationController.hpp"

DEFINE_TYPE(SRM, RequestsNavigationController);

using namespace SRM;

void RequestsNavigationController::DidActivate(DA_ARGS) {
    orientation = Orientation::Vertical;
    if(addedToHierarchy)
        SetChildViewControllers({(HMUI::ViewController*) GET_SINGLETON(RequestsHeaderViewController), (HMUI::ViewController*) GET_SINGLETON(LevelsNavigationController)});
}
