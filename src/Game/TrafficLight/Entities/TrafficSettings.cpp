//
// Created by danilasar on 24.12.2024.
//

#include "TrafficSettings.h"

namespace Game {
    namespace Entities {

        ::Game::Components::TrafficLightStatus TrafficSettings::GetMainColor() {
            return mainColor;
        }

        ::Game::Components::TrafficLightStatus TrafficSettings::GetSecondaryColor() {
            auto main = GetMainColor();
            switch (main) {
                case Components::TL_GREEN:
                    return Components::TL_RED;
                case Components::TL_RED:
                    return Components::TL_GREEN;
                default:
                    return main;
            }
        }

        void TrafficSettings::SetMainColor(::Game::Components::TrafficLightStatus status) {
            previousColor = mainColor;
            mainColor = status;
        }

        void TrafficSettings::NextColor() {
            switch (GetMainColor()) {
                case Components::TL_GREEN:
                case Components::TL_RED:
                    SetMainColor(Components::TL_YELLOW);
                    break;
                case Components::TL_YELLOW:
                    if(previousColor == Components::TL_GREEN) {
                        SetMainColor(Components::TL_RED);
                    } else {
                        SetMainColor(Components::TL_GREEN);
                    }
                    break;
            }
        }
    } // Entities
} // Game