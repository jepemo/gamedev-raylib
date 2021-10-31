#include "raylib.h"

int main(int argc, char **argv)
{
    const int screenWidth = 640;
    const int screenHeight = 480;

    InitWindow(screenWidth, screenHeight, "Raylib - basic 3D");

    SetTargetFPS(30);

    Camera3D camera = {0};
    camera.position = (Vector3){0.0f, 10.0f, 10.0f};
    camera.target = (Vector3){0.0f, 0.0f, 0.0f};
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    Vector3 cubePos = {0.0f, 0.0f, 0.0f};
    Vector3 cubeSize = {2.0f, 2.0f, 2.0f};

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_Q))
            camera.fovy++;
        else if (IsKeyPressed(KEY_W))
            camera.fovy--;
        else if (IsKeyPressed(KEY_ONE))
            camera.projection = CAMERA_PERSPECTIVE;
        else if (IsKeyPressed(KEY_TWO))
            camera.projection = CAMERA_THIRD_PERSON;
        else if (IsKeyPressed(KEY_THREE))
            camera.projection = CAMERA_CUSTOM;
        else if (IsKeyPressed(KEY_FOUR))
            camera.projection = CAMERA_FIRST_PERSON;
        else if (IsKeyPressed(KEY_FIVE))
            camera.projection = CAMERA_ORBITAL;
        else if (IsKeyPressed(KEY_SIX))
            camera.projection = CAMERA_ORTHOGRAPHIC;

        BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        DrawCubeV(cubePos, cubeSize, RED);
        DrawCubeWiresV(cubePos, cubeSize, MAROON);

        DrawGrid(10, 1.0f);

        EndMode3D();

        DrawFPS(10, 10);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}