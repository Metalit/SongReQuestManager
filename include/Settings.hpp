#pragma once

#include "HMUI/ViewController.hpp"

#include "songdownloader/shared/Types/BeatSaver/Beatmap.hpp"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmacro-redefined"
#include "rapidjson-macros/shared/macros.hpp"
#pragma GCC diagnostic pop

DECLARE_JSON_CLASS(SRM, Request,
    BeatSaver::Beatmap Map;
    std::string Date;
    std::string Requester;
    std::string NamePrefix;
    std::string Message;
)

DECLARE_JSON_CLASS(SRM, Database,
    std::vector<SRM::Request> Queue;
    std::vector<SRM::Request> History;
    std::vector<SRM::Request> SongBlacklist;
    std::vector<std::string> UserBlacklist;
    std::vector<std::string> MapperBlacklist;
)

DECLARE_JSON_CLASS(SRM, RequestFilters, 
    bool NoBeatSage = true;
    bool NPSMin = false;
    float NPSMinV = 0;
    bool NPSMax = false;
    float NPSMaxV = 30;
    bool NJSMin = false;
    float NPSMinV = 0;
    bool NJSMax = false;
    float NJSMaxV = 30;
    bool DurationMax = false;
    float DurationMaxV = 3;
    bool VoteMin = false;
    float VoteMinV = 0.5;
    bool DateMin = false;
    float DateMinV = 0;
    bool DateMax = false;
    float DateMaxV = 36;
)

DECLARE_JSON_CLASS(SRM, ModConfig,
    int UserMaxRequest = 2;
    int VipBonusRequest = 2;
    int SubBonusRequest = 3;
    int HistorySize = 50;
    bool QueueOpen = true;
    bool ModsManageQueue = true;
    int QueueCmdShowCount = 4;
    int QueueCmdCooldown = 10;
    SRM::RequestFilters Filters;
    SRM::Database Data;
)

SRM::ModConfig& GetModConfig();
void SaveModConfig();

void LoadDatabase();
void SaveDatabase();

void SettingsDidActivate(HMUI::ViewController* self, bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling);
