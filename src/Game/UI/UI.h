//
// Created by danilasar on 20.12.2024.
//

#ifndef CPP_04_CROSSROAD_UI_H
#define CPP_04_CROSSROAD_UI_H

#include "Workspace.h"
#include "Menu.h"

namespace Game {

    class UI {
        Menu *menu;
        Workspace *workspace;
    public:
        UI();
        void InitUI();
        void RedrawUI();
    };

} // Game

#endif //CPP_04_CROSSROAD_UI_H
