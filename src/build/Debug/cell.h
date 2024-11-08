#ifndef CELL_H
#define CELL_H

#include <cstddef>  // Pour size_t

class Cell {
public:
    size_t x, y;
    bool topWall = true;
    bool bottomWall = true;
    bool leftWall = true;
    bool rightWall = true;
    bool visited = false;

    Cell(size_t x, size_t y);
};

#endif
