#include "Main.hpp"
#include "CustomTypes/RequestsViewController.hpp"

DEFINE_TYPE(SRM, RequestsViewController);

using namespace SRM;

void RequestsViewController::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling) {
    // generally steal ui from song downloader to display requests and allow downloading
}
