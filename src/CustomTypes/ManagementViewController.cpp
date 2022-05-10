#include "Main.hpp"
#include "CustomTypes/ManagementViewController.hpp"

DEFINE_TYPE(SRM, ManagementViewController);

using namespace SRM;

DID_ACTIVATE(ManagementViewController,
    // create ui to clear, skip, ban, etc requests
)