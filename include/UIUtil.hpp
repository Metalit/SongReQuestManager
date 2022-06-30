#pragma once

#include "questui/shared/BeatSaberUI.hpp"

#include "HMUI/NavigationController.hpp"

#define DA_ARGS bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling

#define DID_ACTIVATE(name, ...) \
void name::DidActivate(DA_ARGS) { if(firstActivation) { __VA_ARGS__ } }

DECLARE_CLASS_CODEGEN(SRM, ViewControllerSingleton, HMUI::ViewController,

    DECLARE_DTOR(dtor);

    public:
        template<class T> requires(std::is_base_of_v<HMUI::ViewController, T>)
        static T* GetInstance() {
            static auto type = classof(T*);
            if(!instanceMap.contains(type)) {
                auto instance = QuestUI::BeatSaberUI::CreateViewController(il2cpp_utils::GetSystemType(type));
                instanceMap.emplace(type, instance);
                return (T*) instance;
            } else
                return (T*) instanceMap[type];
        }
    private:
        static std::unordered_map<Il2CppClass*, HMUI::ViewController*> instanceMap;
)

DECLARE_CLASS_CODEGEN(SRM, NavigationControllerSingleton, HMUI::NavigationController,

    DECLARE_DTOR(dtor);

    public:
        template<class T> requires(std::is_base_of_v<HMUI::NavigationController, T>)
        static T* GetInstance() {
            static auto type = classof(T*);
            if(!instanceMap.contains(type)) {
                auto instance = QuestUI::BeatSaberUI::CreateViewController(il2cpp_utils::GetSystemType(type));
                instanceMap.emplace(type, (HMUI::NavigationController*) instance);
                return (T*) instance;
            } else
                return (T*) instanceMap[type];
        }
    private:
        static std::unordered_map<Il2CppClass*, HMUI::NavigationController*> instanceMap;
)

DECLARE_CLASS_CODEGEN(SRM, FlowCoordinatorSingleton, HMUI::FlowCoordinator,

    DECLARE_DTOR(dtor);

    public:
        template<class T> requires(std::is_base_of_v<HMUI::FlowCoordinator, T>)
        static T* GetInstance() {
            static auto type = classof(T*);
            if(!instanceMap.contains(type)) {
                auto instance = QuestUI::BeatSaberUI::CreateFlowCoordinator(il2cpp_utils::GetSystemType(type));
                instanceMap.emplace(type, instance);
                return (T*) instance;
            } else
                return (T*) instanceMap[type];
        }
    private:
        static std::unordered_map<Il2CppClass*, HMUI::FlowCoordinator*> instanceMap;
)

#define GET_SINGLETON(type) type::GetInstance<type>()

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
