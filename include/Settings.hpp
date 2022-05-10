#pragma once

#include "UIUtil.hpp"

#include "HMUI/ViewController.hpp"

#include "songdownloader/shared/Types/BeatSaver/Beatmap.hpp"

DECLARE_JSON_CLASS(SRM, Request,
    AUTO_VALUE(BeatSaver::Beatmap, Map);
    AUTO_VALUE(std::string, Date);
    AUTO_VALUE(std::string, Requester);
    AUTO_VALUE(std::string, NamePrefix);
    AUTO_VALUE(std::string, Message);
)

DECLARE_JSON_CLASS(SRM, Database,
    AUTO_VECTOR(SRM::Request, Queue);
    AUTO_VECTOR(SRM::Request, History);
    AUTO_VECTOR(SRM::Request, SongBlacklist);
    AUTO_VECTOR(std::string, UserBlacklist);
    AUTO_VECTOR(std::string, MapperBlacklist);
)

DECLARE_JSON_CLASS(SRM, RequestFilters,
    AUTO_VALUE_DEFAULT(bool, NoBeatSage, true);
    AUTO_VALUE_DEFAULT(bool, NPSMin, false);
    AUTO_VALUE_DEFAULT(float, NPSMinV, 0.0f);
    AUTO_VALUE_DEFAULT(bool, NPSMax, false);
    AUTO_VALUE_DEFAULT(float, NPSMaxV, 30.0f);
    AUTO_VALUE_DEFAULT(bool, NJSMin, false);
    AUTO_VALUE_DEFAULT(float, NJSMinV, 0.0f);
    AUTO_VALUE_DEFAULT(bool, NJSMax, false);
    AUTO_VALUE_DEFAULT(float, NJSMaxV, 30.0f);
    AUTO_VALUE_DEFAULT(bool, DurationMax, false);
    AUTO_VALUE_DEFAULT(float, DurationMaxV, 3.0f);
    AUTO_VALUE_DEFAULT(bool, VoteMin, false);
    AUTO_VALUE_DEFAULT(float, VoteMinV, 0.5f);
    AUTO_VALUE_DEFAULT(bool, DateMin, false);
    AUTO_VALUE_DEFAULT(float, DateMinV, 0.0f);
    AUTO_VALUE_DEFAULT(bool, DateMax, false);
    AUTO_VALUE_DEFAULT(float, DateMaxV, 36.0f);
)

DECLARE_JSON_CLASS(SRM, ModConfig,
    AUTO_VALUE_DEFAULT(int, UserMaxRequest, 2);
    AUTO_VALUE_DEFAULT(int, VipBonusRequest, 2);
    AUTO_VALUE_DEFAULT(int, SubBonusRequest, 3);
    AUTO_VALUE_DEFAULT(int, HistorySize, 50);
    AUTO_VALUE_DEFAULT(bool, QueueOpen, true);
    AUTO_VALUE_DEFAULT(bool, ModsManageQueue, true);
    AUTO_VALUE_DEFAULT(int, QueueCmdShowCount, 4);
    AUTO_VALUE_DEFAULT(int, QueueCmdCooldown, 10);
    AUTO_VALUE(SRM::RequestFilters, Filters);
)

SRM::ModConfig& GetModConfig();
void SaveModConfig();

SRM::Database& GetDatabase();
void SaveDatabase();

void SettingsDidActivate(HMUI::ViewController* self, DA_ARGS);
