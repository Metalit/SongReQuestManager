#include "Main.hpp"
#include "CustomTypes/ManagementViewController.hpp"

DEFINE_TYPE(SRM, ManagementViewController);

using namespace SRM;

void ManagementViewController::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling) {
    // create ui to clear, skip, ban, etc requests
}