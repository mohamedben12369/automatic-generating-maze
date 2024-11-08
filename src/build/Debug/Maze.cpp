#include "Maze.h"
#include <stack>
#include "raylib.h"

Maze::Maze(size_t rows, size_t cols) : rows(rows), cols(cols) {
    for (size_t y = 0; y < rows; ++y) {
        for (size_t x = 0; x < cols; ++x) {
            cells.push_back(Cell(x, y));
        }
    }
}

std::vector<Cell*> Maze::GetNeighbors(Cell& cell) {
    std::vector<Cell*> neighbors;
    size_t x = cell.x;
    size_t y = cell.y;

    if (y > 0 && !cells[(y - 1) * cols + x].visited) {
        neighbors.push_back(&cells[(y - 1) * cols + x]);
    }
    if (y < rows - 1 && !cells[(y + 1) * cols + x].visited) {
        neighbors.push_back(&cells[(y + 1) * cols + x]);
    }
    if (x > 0 && !cells[y * cols + (x - 1)].visited) {
        neighbors.push_back(&cells[y * cols + (x - 1)]);
    }
    if (x < cols - 1 && !cells[y * cols + (x + 1)].visited) {
        neighbors.push_back(&cells[y * cols + (x + 1)]);
    }

    return neighbors;
}

void Maze::RemoveWalls(Cell& current, Cell& next) {
    int dx = static_cast<int>(current.x) - static_cast<int>(next.x);
    int dy = static_cast<int>(current.y) - static_cast<int>(next.y);

    if (dx == 1) {
        current.leftWall = false;
        next.rightWall = false;
    } else if (dx == -1) {
        current.rightWall = false;
        next.leftWall = false;
    } else if (dy == 1) {
        current.topWall = false;
        next.bottomWall = false;
    } else if (dy == -1) {
        current.bottomWall = false;
        next.topWall = false;
    }
}

void Maze::Generate() {
    std::stack<Cell*> stack;
    cells[0].visited = true;
    stack.push(&cells[0]);

    while (!stack.empty()) {
        Cell* current = stack.top();
        std::vector<Cell*> neighbors = GetNeighbors(*current);

        if (!neighbors.empty()) {
            size_t index = static_cast<size_t>(rand()) % neighbors.size();
            Cell* next = neighbors[index];
            next->visited = true;
            RemoveWalls(*current, *next);
            stack.push(next);
        } else {
            stack.pop();
        }
    }
}

void Maze::Draw() {
    for (const Cell& cell : cells) {
        size_t x = cell.x * 20;
        size_t y = cell.y * 20;

        if (cell.topWall) {
            DrawLine(static_cast<int>(x), static_cast<int>(y), static_cast<int>(x + 20), static_cast<int>(y), BLACK);
        }
        if (cell.bottomWall) {
            DrawLine(static_cast<int>(x), static_cast<int>(y + 20), static_cast<int>(x + 20), static_cast<int>(y + 20), BLACK);
        }
        if (cell.leftWall) {
            DrawLine(static_cast<int>(x), static_cast<int>(y), static_cast<int>(x), static_cast<int>(y + 20), BLACK);
        }
        if (cell.rightWall) {
            DrawLine(static_cast<int>(x + 20), static_cast<int>(y), static_cast<int>(x + 20), static_cast<int>(y + 20), BLACK);
        }
    }
}
