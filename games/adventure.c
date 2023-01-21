#include "raylib.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main(int argc, char **argv) {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "ADvEnTuRe GaMe");

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    // DrawText(text, text_x_pos, text_y_pos, font_size, LIGHTGRAY);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
