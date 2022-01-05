#include "../include/engine.h"

Engine::Engine() {
    for (uint i = 0; i < 5; i++) {
        m_enemies.push_back(Entity(1, 10, Shape::ELLIPSE));
    }
}

void Engine::init() {

}

void Engine::run() {
    const int screen_width = 800;
    const int screen_height = 450;

    InitWindow(screen_width, screen_height, "raylib [core] example - basic window");

    SetTargetFPS(60);

    m_player.size = 10;
    m_player.speed = 3;
    m_player.coordinates.x = 400;
    m_player.coordinates.y = 225;
    m_player.shape = Shape::CIRCLE;
    m_player.target = m_player.coordinates;

    Vector2 origin_of_drag;
    Vector2 size_of_drag;
    bool is_dragging = false;

    while (!WindowShouldClose()) {

        for (auto it = m_enemies.begin(); it != m_enemies.end(); it++)
            (*it).move(m_player.coordinates);

        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && (GetGestureDetected() == GESTURE_DRAG || GetGestureDetected() == GESTURE_HOLD)) {
            if (!is_dragging) {
                origin_of_drag = GetMousePosition();
                std::cout << "origin_of_drag = " << origin_of_drag.x << "/" << origin_of_drag.y << std::endl;
                is_dragging = true;
            }
        }

        if (is_dragging && (GetGestureDetected() == GESTURE_DRAG || GetGestureDetected() == GESTURE_HOLD)) {
            size_of_drag.x = screen_width * GetGestureDragVector().x;
            size_of_drag.y = screen_height * GetGestureDragVector().y;
            
            DrawRectangleLines((int)origin_of_drag.x,
                               (int)origin_of_drag.y,
                               (int)size_of_drag.x,
                               (int)size_of_drag.y,
                               RED);
        }

        else if (is_dragging && GetGestureDetected() != GESTURE_DRAG){
            is_dragging = false;
            std::cout << "Released drag" << std::endl;

            if (Tools::point_in_rectangle(origin_of_drag, size_of_drag, m_player.coordinates)) {
                m_player.selected = true;
            }
        }

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            if (Tools::clicked_in(GetMousePosition(), m_player.shape, m_player.size, m_player.coordinates)) {
                m_player.selected = true;
            }

            else {
                m_player.selected = false;
            }
        }

        if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
            if (m_player.selected)
                m_player.target = GetMousePosition();
        }

        m_player.moveToTarget();

        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        if (m_player.selected)
            DrawCircle(m_player.coordinates.x, m_player.coordinates.y, m_player.size, BLUE);
        else
            DrawCircle(m_player.coordinates.x, m_player.coordinates.y, m_player.size, RED);

        for (auto it = m_enemies.begin(); it != m_enemies.end(); it++)
            DrawEllipse((*it).coordinates.x, (*it).coordinates.y, 5, 10, BLUE);

        EndDrawing();
    }
    CloseWindow();
}