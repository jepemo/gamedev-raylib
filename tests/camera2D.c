#include "raylib.h"
#include <stdio.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#define MAX_COLORS 11
#define SIZE_BLOCK 50
#define MAX_OBJECTS 256

Color COLOURS[MAX_COLORS] = {
    PURPLE,
    BLUE,
    YELLOW,
    GREEN,
    PINK,
    ORANGE,
    LIME,
    BROWN,
    BEIGE,
    MAGENTA,
    GOLD};

typedef struct
{
    Vector2 position;
    Vector2 size;
    Color color;

} Object;

typedef struct
{
    Object objects[MAX_OBJECTS];
    Object pointer;
} Scene;

Object CreatePointer()
{
    Object obj;

    obj.color = RED;
    obj.position = (Vector2){SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f};
    obj.size = (Vector2){SIZE_BLOCK + 2, SIZE_BLOCK + 2};

    return obj;
}

Scene CreateScene()
{
    Scene scene;

    scene.pointer = CreatePointer();

    int posX = 0;
    int posY = 0;
    int ind = 0;

    int X_BLOCKS = SCREEN_WIDTH / SIZE_BLOCK;
    int Y_BLOCKS = SCREEN_HEIGHT / SIZE_BLOCK;

    TraceLog(LOG_INFO, "Creating matrix of (%d, %d)", X_BLOCKS, Y_BLOCKS);

    for (int x = 0; x <= X_BLOCKS; ++x)
    {
        for (int y = 0; y <= Y_BLOCKS; ++y)
        {
            // TraceLog(LOG_WARNING, "(%d, %d)", posX, posY);
            scene.objects[ind].color = COLOURS[ind % MAX_COLORS];
            scene.objects[ind].position = (Vector2){x * SIZE_BLOCK, y * SIZE_BLOCK};
            scene.objects[ind].size = (Vector2){SIZE_BLOCK, SIZE_BLOCK};

            ind++;
        }
    }

    return scene;
}

void RenderScene(Scene *scene)
{
    for (int i = 0; i < MAX_OBJECTS; ++i)
    {
        DrawRectangleV(scene->objects[i].position, scene->objects[i].size, scene->objects[i].color);
    }

    DrawRectangleV(scene->pointer.position, scene->pointer.size, scene->pointer.color);
}

void UpdateMyCamera(Camera2D *camera, Scene *scene)
{
    camera->target = scene->pointer.position;
    // camera->offset = scene->pointer.position;
}

int main(int argc, char **argv)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "raylib - camera testing");

    float rotation = 0.0f;
    float zoom = 1.0f;
    const float desp = 2.f;

    Scene scene = CreateScene();

    Camera2D camera = {0};
    camera.target = (Vector2){scene.pointer.position.x, scene.pointer.position.y};
    camera.offset = (Vector2){SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f};
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
            scene.pointer.position.x -= desp;
        if (IsKeyDown(KEY_RIGHT))
            scene.pointer.position.x += desp;
        if (IsKeyDown(KEY_UP))
            scene.pointer.position.y -= desp;
        if (IsKeyDown(KEY_DOWN))
            scene.pointer.position.y += desp;

        camera.rotation = rotation;
        camera.zoom = zoom;

        UpdateMyCamera(&camera, &scene);

        BeginDrawing();
        {
            BeginMode2D(camera);
            {
                RenderScene(&scene);
            }
            EndMode2D();
        }
        EndDrawing();
    }

    CloseWindow();

    return 0;
}