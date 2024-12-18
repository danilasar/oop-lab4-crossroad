#ifndef CPP_04_CROSSROAD_CORE_H
#define CPP_04_CROSSROAD_CORE_H

namespace Game {

    class Core {
        Core()
        { }
    public:
        Core(const Core& ) = delete;
        static Core& GetInstance();
        void InitGame();
        void FinishGame();
    };

} // Game

#endif //CPP_04_CROSSROAD_CORE_H
