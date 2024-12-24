//
// Created by danilasar on 20.12.2024.
//

#ifndef CPP_04_CROSSROAD_CAR_H
#define CPP_04_CROSSROAD_CAR_H

#include "../../../utils.h"

namespace Game {
    namespace Components {

        enum Road {
            LEFT,
            RIGHT,
            BOTTOM,
            TOP
        };

        enum State {
            Begin,
            GoingToLaneChecker,
            CheckingLane,
            ChangingLane,
            GoingToCrossroad,
            StayingOnLight,
            Turning,
            Outgoing,
            End
        };

        class Car {
            float baseSpeed;
            float speed;
        public:
            Vector2 position;
            Road from;
            Road to;
            State state;
            Car(Road from, Road to, float baseSpeed);
            float GetSpeed();
            float GetBaseSpeed();
            void SetSpeed(float newSpeed);
            void SetBaseSpeed(float newSpeed);
        };

    } // Entities
} // Game

#endif //CPP_04_CROSSROAD_CAR_H
