#include "Main.hpp"
#include "UIUtil.hpp"
#include "Settings.hpp"

DEFINE_TYPE(SRM, ViewControllerSingleton);
DEFINE_TYPE(SRM, FlowCoordinatorSingleton);

using namespace SRM;
using namespace QuestUI;
using namespace UnityEngine;

std::unordered_map<Il2CppClass*, HMUI::ViewController*> ViewControllerSingleton::instanceMap;
std::unordered_map<Il2CppClass*, HMUI::FlowCoordinator*> FlowCoordinatorSingleton::instanceMap;

void ViewControllerSingleton::dtor() {
    instanceMap.erase(this->klass);
}

void FlowCoordinatorSingleton::dtor() {
    instanceMap.erase(this->klass);
}

Transform* GetSubcontainer(UI::VerticalLayoutGroup* vertical) {
    auto horizontal = BeatSaberUI::CreateHorizontalLayoutGroup(vertical);
    horizontal->GetComponent<UI::LayoutElement*>()->set_minHeight(8);
    horizontal->set_childForceExpandHeight(true);
    horizontal->set_childAlignment(TextAnchor::MiddleCenter);
    return horizontal->get_transform();
}

SliderSetting* CreateIncrementSlider(Transform* parent, float& configValue, float increment, float min, float max, std::function<std::string(float)> format, const std::string& name, const std::string& hoverHint) {
    SliderSetting* slider = BeatSaberUI::CreateSliderSetting(parent, name, 0.01, configValue, min, max, 0, nullptr);
    if(!hoverHint.empty())
        BeatSaberUI::AddHoverHint(slider->slider, hoverHint);

    ((RectTransform*) slider->slider->get_transform())->set_anchoredPosition({-6, 0});

    auto leftButton = BeatSaberUI::CreateUIButton(slider->get_transform(), "", "DecButton", {-3.5, 0}, {6, 8}, [slider, increment](){
        float newValue = slider->slider->get_value() - increment;
        slider->slider->set_value(newValue);
        // get_value to let it handle min/max
        slider->OnChange(slider->slider, slider->slider->get_value());
    });
    auto rightButton = BeatSaberUI::CreateUIButton(slider->get_transform(), "", "IncButton", {41, 0}, {8, 8}, [slider, increment](){
        float newValue = slider->slider->get_value() + increment;
        slider->slider->set_value(newValue);
        // get_value to let it handle min/max
        slider->OnChange(slider->slider, slider->slider->get_value());
    });

    leftButton->set_interactable(configValue <= min);
    rightButton->set_interactable(configValue >= max);

    slider->OnValueChange = [&configValue, leftButton, rightButton, min, max](float value) {
        configValue = value;
        SaveModConfig();
        leftButton->set_interactable(value <= min);
        rightButton->set_interactable(value >= max);
    };

    return slider;
}

UI::Button* CreateFitButton(Transform* parent, Vector2 pos, const std::string& text, const std::function<void()>& callback) {
    auto button = BeatSaberUI::CreateUIButton(parent, text, pos, callback);

    static ConstString contentName("Content");
    Object::Destroy(button->get_transform()->Find(contentName)->GetComponent<UI::LayoutElement*>());
    auto sizeFitter = button->get_gameObject()->AddComponent<UI::ContentSizeFitter*>();
    sizeFitter->set_horizontalFit(UI::ContentSizeFitter::FitMode::PreferredSize);
    sizeFitter->set_verticalFit(UI::ContentSizeFitter::FitMode::PreferredSize);

    return button;
}
