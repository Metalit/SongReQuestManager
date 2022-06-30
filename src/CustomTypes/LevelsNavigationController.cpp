#include "Main.hpp"
#include "CustomTypes/LevelsNavigationController.hpp"

#include "CustomTypes/LevelListViewController.hpp"

DEFINE_TYPE(SRM, LevelsNavigationController);

using namespace SRM;

void LevelsNavigationController::DidActivate(DA_ARGS) {
    orientation = Orientation::Horizontal;
    if(addedToHierarchy)
        SetChildViewController((HMUI::ViewController*) GET_SINGLETON(LevelListViewController));
}
