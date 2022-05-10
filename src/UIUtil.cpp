#include "Main.hpp"
#include "UIUtil.hpp"
#include "Settings.hpp"

using namespace SRM;
using namespace QuestUI;

UnityEngine::Transform* GetSubcontainer(UnityEngine::UI::VerticalLayoutGroup* vertical) {
    auto horizontal = QuestUI::BeatSaberUI::CreateHorizontalLayoutGroup(vertical);
    horizontal->GetComponent<UnityEngine::UI::LayoutElement*>()->set_minHeight(8);
    horizontal->set_childForceExpandHeight(true);
    horizontal->set_childAlignment(UnityEngine::TextAnchor::MiddleCenter);
    return horizontal->get_transform();
}

QuestUI::SliderSetting* CreateIncrementSlider(UnityEngine::Transform* parent, float& configValue, float increment, float min, float max, const std::string& name, const std::string& hoverHint) {
    SliderSetting* slider = BeatSaberUI::CreateSliderSetting(parent, name, 0.01, configValue, min, max, 0, [&configValue](float value) {
        configValue = value;
        SaveModConfig();
    });
    if(!hoverHint.empty())
        BeatSaberUI::AddHoverHint(slider->slider, hoverHint);

    ((UnityEngine::RectTransform*) slider->slider->get_transform())->set_anchoredPosition({-6, 0});

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

    return slider;
}
