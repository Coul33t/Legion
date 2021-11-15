#include "../include/engine.h"

Engine::Engine() {
    for (uint i = 0; i < 5; i++) {
        m_enemies.push_back(Entity(1, 10, Shape::ELLIPSE));
    }
}

void Engine::init() {

}

void Engine::run() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);


    while (!WindowShouldClose()) {

        m_player.move(GetMousePosition());

        for (auto it = m_enemies.begin(); it != m_enemies.end(); it++)
            (*it).move(m_player.getPosition());

        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        DrawCircle(m_player.getX(), m_player.getY(), m_player.getSize(), RED);

        for (auto it = m_enemies.begin(); it != m_enemies.end(); it++)
            DrawEllipse((*it).getX(), (*it).getY(), 5, 10, BLUE);

        EndDrawing();
    }
    CloseWindow();
}