#include "Main.hpp"
#include "Settings.hpp"

#include <filesystem>

SRM::ModConfig& GetModConfig() {
    static bool initialized = false;
    static auto config = SRM::ModConfig();
    if(!initialized) {
        try {
            ReadFromFile(GetConfigPath(), config);
        } catch (const std::exception& e) {
            LOG_ERROR("Error reading config file: %s", e.what());
            WriteToFile(GetConfigPath(), config);
        }
        initialized = true;
    }
    return config;
}

void SaveModConfig() {
    try {
        WriteToFile(GetConfigPath(), GetModConfig());
    } catch (const std::exception& e) {
        LOG_ERROR("Error saving config file: %s", e.what());
    }
}

void LoadDatabase() {
    try {
        ReadFromFile(GetDatabasePath(), GetModConfig().Data);
    } catch (const std::exception& e) {
        LOG_ERROR("Error reading database: %s", e.what());
        std::string backupPath = GetDatabasePath() + ".backup";
        LOG_INFO("Backing up invalid database at: %s", backupPath.c_str());
        std::filesystem::copy_file(GetDatabasePath(), backupPath);
        WriteToFile(GetDatabasePath(), GetModConfig().Data);
    }
}

void SaveDatabase() {
    try {
        WriteToFile(GetDatabasePath(), GetModConfig().Data);
    } catch (const std::exception& e) {
        LOG_ERROR("Error saving database: %s", e.what());
    }
}

void SettingsDidActivate(HMUI::ViewController* self, bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling) {
    
}
