#include "Game.h"

#include "raylib.h"

int main() {
    InitWindow(800, 600, "Labyrinthe généré avec POO");
    SetTargetFPS(60);

    int level = 1;  // Vous pouvez ajuster ce niveau pour tester différentes tailles de labyrinthe
    Game game(level);

    while (!WindowShouldClose()) {
        game.Update();
        game.Draw();
    }

    CloseWindow();
    return 0;
}
