#include "Game.h"
#include "raylib.h"

Game::Game(int level) : maze(15, 15), player(1, 1), level(level) {
    srand(static_cast<unsigned>(time(0)));
    maze.Generate();
}

void Game::Update() {
    if (IsKeyPressed(KEY_UP)) player.Move(0, -1);
    if (IsKeyPressed(KEY_DOWN)) player.Move(0, 1);
    if (IsKeyPressed(KEY_LEFT)) player.Move(-1, 0);
    if (IsKeyPressed(KEY_RIGHT)) player.Move(1, 0);
}

void Game::Draw() {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    maze.Draw();
    player.Draw();

    EndDrawing();
}
