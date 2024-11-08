#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include "Cell.h"

class Maze {
private:
    size_t rows, cols;
    std::vector<Cell> cells;

    std::vector<Cell*> GetNeighbors(Cell& cell);
    void RemoveWalls(Cell& current, Cell& next);

public:
    Maze(size_t rows, size_t cols);
    void Generate();
    void Draw();
};

#endif
