#include "raylib.h"

int main(int argc, char **argv)
{
    int screenWidth = 640;
    int screenHeight = 480;

    InitWindow(screenWidth, screenHeight, "Raylib - Mouse Collision");

    SetTargetFPS(30);

    HideCursor();

    // ToggleFullscreen();

    float radius_cursor = 10;
    float radius_point = 20;

    Vector2 points_positions[4] = {
        (Vector2){screenWidth / 4, screenHeight / 4},
        (Vector2){(screenWidth / 4) * 3, screenHeight / 4},
        (Vector2){screenWidth / 4, (screenHeight / 4) * 3},
        (Vector2){(screenWidth / 4) * 3, (screenHeight / 4) * 3}};

    Vector2 mouse_position;

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        mouse_position = GetMousePosition();
        DrawCircle(mouse_position.x, mouse_position.y, radius_cursor, DARKBLUE);

        for (int i = 0; i < 4; ++i)
        {
            DrawCircleV(points_positions[i], radius_point, RED);

            if (CheckCollisionCircles(mouse_position, radius_cursor, points_positions[i], radius_point))
            {
                DrawText(TextFormat("%d", i + 1), screenWidth / 2, screenHeight / 2, 50, BLACK);
            }
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}