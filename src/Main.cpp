#include "Main.hpp"
#include "CustomTypes/SettingsFlowCoordinator.hpp"
#include "CustomTypes/RequestsFlowCoordinator.hpp"

#include "questui/shared/QuestUI.hpp"

#include "beatsaber-hook/shared/config/config-utils.hpp"

#include "GlobalNamespace/LevelFilteringNavigationController.hpp"
#include "GlobalNamespace/MainFlowCoordinator.hpp"

#include "HMUI/ViewController_AnimationDirection.hpp"

using namespace GlobalNamespace;
using namespace SRM;

static ModInfo modInfo;

Logger& getLogger() {
    static Logger* logger = new Logger(modInfo);
    return *logger;
}

std::string& GetConfigPath() {
    static std::string configPath = Configuration::getConfigFilePath(modInfo);
    return configPath;
}

std::string& GetDatabasePath() {
    static std::string databasePath(getDataDir(modInfo) + "database.json");
    return databasePath;
}

MAKE_HOOK_MATCH(LevelFilteringNavigationController_DidActivate, &LevelFilteringNavigationController::DidActivate,
        void, LevelFilteringNavigationController* self, bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling) {
    
    LevelFilteringNavigationController_DidActivate(self, firstActivation, addedToHierarchy, screenSystemEnabling);

    CreateFitButton(self->selectLevelCategoryViewController, {0, 7}, "SRM", [] {
        UnityEngine::Resources::FindObjectsOfTypeAll<MainFlowCoordinator*>().First()->YoungestChildFlowCoordinatorOrSelf()->PresentFlowCoordinator(
            GET_SINGLETON(RequestsFlowCoordinator), nullptr, HMUI::ViewController::AnimationDirection::Horizontal, false, false);
    });
}

extern "C" void setup(ModInfo& info) {
    info.id = ID;
    info.version = VERSION;
    modInfo = info;
	
    LOG_INFO("Completed setup!");
}

extern "C" void load() {
    il2cpp_functions::Init();
    QuestUI::Init();

    QuestUI::Register::RegisterModSettingsFlowCoordinator<SRM::SettingsFlowCoordinator*>(modInfo);

    LOG_INFO("Installing hooks...");
    INSTALL_HOOK(getLogger(), LevelFilteringNavigationController_DidActivate);
    LOG_INFO("Installed all hooks!");
}