#ifndef _GRID_H
#define _GRID_H

#include <vector>

#include "tools.h"
#include "tile.h"

class Grid {
    public:
        Grid();
        Grid(size_t width, size_t height);

    private:
        void initGrid();

        Size m_size;
        std::vector<Tile> m_grid;
};

#endif