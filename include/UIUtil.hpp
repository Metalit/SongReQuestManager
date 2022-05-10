#pragma once

#include "questui/shared/BeatSaberUI.hpp"

#define DA_ARGS bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling

#define DID_ACTIVATE(name, ...) \
void name::DidActivate(DA_ARGS) { if(firstActivation) { __VA_ARGS__ } }

UnityEngine::Transform* GetSubcontainer(UnityEngine::UI::VerticalLayoutGroup* vertical);

template<QuestUI::BeatSaberUI::HasTransform T>
requires(!std::is_convertible_v<T, UnityEngine::Transform*>)
QuestUI::SliderSetting* CreateIncrementSlider(T* parent, float& configValue, float increment, float min, float max, std::function<std::string(float)> format, const std::string& name, const std::string& hoverHint = "") {
    return CreateIncrementSlider(parent->get_transform(), configValue, increment, min, max, name, hoverHint);
}

QuestUI::SliderSetting* CreateIncrementSlider(UnityEngine::Transform* parent, float& configValue, float increment, float min, float max, std::function<std::string(float)> format, const std::string& name, const std::string& hoverHint = "");

template<QuestUI::BeatSaberUI::HasTransform T>
requires(!std::is_convertible_v<T, UnityEngine::Transform*>)
UnityEngine::UI::Button* CreateFitButton(T* parent, UnityEngine::Vector2 pos, const std::string& text, const std::function<void()>& callback = nullptr) {
    return CreateFitButton(parent->get_transform(), pos, text, callback);
}

UnityEngine::UI::Button* CreateFitButton(UnityEngine::Transform* parent, UnityEngine::Vector2 pos, const std::string& text, const std::function<void()>& callback = nullptr);
