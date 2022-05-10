#include "Main.hpp"
#include "CustomTypes/RequestsViewController.hpp"

DEFINE_TYPE(SRM, RequestsViewController);

using namespace SRM;

DID_ACTIVATE(RequestsViewController,
    // generally steal ui from song downloader to display requests and allow downloading
)
