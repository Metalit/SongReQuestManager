#include "Main.hpp"

#include "GlobalNamespace/LevelFilteringNavigationController.hpp"

using namespace GlobalNamespace;

static ModInfo modInfo;

Logger& getLogger() {
    static Logger* logger = new Logger(modInfo);
    return *logger;
}

MAKE_HOOK_MATCH(LevelFilteringNavigationController_DidActivate, &LevelFilteringNavigationController::DidActivate,
        void, LevelFilteringNavigationController* self, bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling) {
    
    LevelFilteringNavigationController_DidActivate(self, firstActivation, addedToHierarchy, screenSystemEnabling);

    // create button to present requests
}

extern "C" void setup(ModInfo& info) {
    info.id = ID;
    info.version = VERSION;
    modInfo = info;
	
    LOG_INFO("Completed setup!");
}

extern "C" void load() {
    il2cpp_functions::Init();

    LOG_INFO("Installing hooks...");
    INSTALL_HOOK(getLogger(), LevelFilteringNavigationController_DidActivate);
    LOG_INFO("Installed all hooks!");
}