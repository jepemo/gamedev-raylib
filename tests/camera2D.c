#include "raylib.h"

int main(int argc, char **argv)
{
    int screenWidth = 640;
    int screenHeight = 480;

    InitWindow(screenWidth, screenHeight, "raylib - camera testing");

    float rotation = 0.0f;
    float zoom = 1.0f;

    float size = 20.0f;
    Vector2 ppSize = (Vector2){size, size};
    Vector2 pp = (Vector2){screenWidth / 2.0f, screenHeight / 2.0f};

    Camera2D camera = {0};
    camera.target = (Vector2){pp.x + size, pp.y + size};
    camera.offset = (Vector2){screenWidth / 2.0f, screenHeight / 2.0f};
    camera.rotation = rotation;
    camera.zoom = zoom;

    SetTargetFPS(30);

    while (!WindowShouldClose())
    {
        ClearBackground(RAYWHITE);

        if (IsKeyDown(KEY_R))
            rotation += 0.1f;
        if (IsKeyDown(KEY_Z))
            zoom += 0.1f;
        if (IsKeyDown(KEY_LEFT))
            pp.x -= 1.0f;
        if (IsKeyDown(KEY_RIGHT))
            pp.x += 1.0f;

        camera.rotation = rotation;
        camera.zoom = zoom;

        BeginDrawing();
        {
            BeginMode2D(camera);
            {
                DrawRectangleV(pp, ppSize, RED);
            }
            EndMode2D();
        }
        EndDrawing();
    }

    CloseWindow();

    return 0;
}