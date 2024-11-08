#ifndef GAME_H
#define GAME_H

#include "Maze.h"
#include "Player.h"

class Game {
private:
    Maze maze;
    Player player;
    int level;

public:
    Game(int level);
    void Update();
    void Draw();
};

#endif
