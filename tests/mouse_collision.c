#include "raylib.h"

int
main (int argc, char **argv)
{
  int screenWidth = 640;
  int screenHeight = 480;

  InitWindow (screenWidth, screenHeight, "Raylib - Mouse Collision");

  SetTargetFPS (30);

  HideCursor ();

  float radiusCursor = 10;
  float radiusPoint = 20;

  Vector2 points_positions[4]
      = { (Vector2){ screenWidth / 4, screenHeight / 4 },
          (Vector2){ (screenWidth / 4) * 3, screenHeight / 4 },
          (Vector2){ screenWidth / 4, (screenHeight / 4) * 3 },
          (Vector2){ (screenWidth / 4) * 3, (screenHeight / 4) * 3 } };

  Vector2 mousePosition;

  while (!WindowShouldClose ())
    {
      BeginDrawing ();

      ClearBackground (RAYWHITE);

      mousePosition = GetMousePosition ();
      DrawCircleV (mousePosition, radiusCursor, DARKBLUE);

      for (int i = 0; i < 4; ++i)
        {
          DrawCircleV (points_positions[i], radiusPoint, RED);

          if (CheckCollisionCircles (mousePosition, radiusCursor,
                                     points_positions[i], radiusPoint))
            {
              DrawText (TextFormat ("%d", i + 1), screenWidth / 2,
                        screenHeight / 2, 50, BLACK);
            }
        }

      EndDrawing ();
    }

  CloseWindow ();

  return 0;
}