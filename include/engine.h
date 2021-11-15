#ifndef _ENGINE_H
#define _ENGINE_H

#include <vector>
#include <random>

#include "grid.h"
#include "entity.h"

class Engine {
    public:
        Engine();
        void init();
        void run();

    private:
        Grid m_grid;
        Entity m_player;
        std::vector<Entity> m_enemies;
};

#endif