#include "Player.h"
#include "raylib.h"

Player::Player(size_t startX, size_t startY) : x(startX), y(startY) {}

void Player::Move(int dx, int dy) {
    x += dx;
    y += dy;
}

void Player::Draw() const {
    DrawRectangle(static_cast<int>(x * 20), static_cast<int>(y * 20), 20, 20, RED);
}
