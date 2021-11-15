#include "../include/grid.h"

Grid::Grid() {
    m_size.w = 3;
    m_size.h = 5;
    initGrid();
}

Grid::Grid(size_t width, size_t height) {
    m_size.w = width;
    m_size.h = height;
    initGrid();
}

void Grid::initGrid() {
    m_grid.reserve(m_size.w * m_size.h);
}