#ifndef PLAYER_H
#define PLAYER_H

#include <cstddef>  // Pour size_t

class Player {
public:
    size_t x, y;

    Player(size_t startX, size_t startY);
    void Move(int dx, int dy);
    void Draw() const;
};

#endif
