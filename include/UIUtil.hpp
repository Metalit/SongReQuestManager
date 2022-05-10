#pragma once

#include "questui/shared/BeatSaberUI.hpp"

#define DA_ARGS bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling

#define DID_ACTIVATE(name, ...) \
void name::DidActivate(DA_ARGS) { if(firstActivation) { __VA_ARGS__ } }

UnityEngine::Transform* GetSubcontainer(UnityEngine::UI::VerticalLayoutGroup* vertical);

template<QuestUI::BeatSaberUI::HasTransform T>
requires(!std::is_convertible_v<T, UnityEngine::Transform*>)
QuestUI::SliderSetting* CreateIncrementSlider(T* parent, float& configValue, float increment, float min, float max, const std::string& name, const std::string& hoverHint = "");

QuestUI::SliderSetting* CreateIncrementSlider(UnityEngine::Transform* parent, float& configValue, float increment, float min, float max, const std::string& name, const std::string& hoverHint = "");
