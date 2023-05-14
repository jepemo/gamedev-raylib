#include "raylib.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#define GRASS 0
#define WATER 1

#define MAP_WIDTH 16
#define MAP_HEIGHT 16

#define ASSETS_DIR "games/assets"

#define TEXTURE_SIZE 8

int map[MAP_HEIGHT][MAP_WIDTH] = {
    {2, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {2, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
};

typedef struct {
  int x;
  int y;
} Link;

int main(int argc, char **argv) {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Rpg game");

  Texture2D textures[3] = {
      LoadTexture(ASSETS_DIR "/grass.png"), // 0
      LoadTexture(ASSETS_DIR "/water.png"), // 1
      LoadTexture(ASSETS_DIR "/bridge.png") // 2
  };

  Texture2D texture_link = LoadTexture(ASSETS_DIR "/man.png");

  int scale = 4;
  int width_map = MAP_WIDTH * TEXTURE_SIZE * scale;
  int height_map = MAP_HEIGHT * TEXTURE_SIZE * scale;
  int origin_x = (SCREEN_WIDTH / 2) - (width_map / 2);
  int origin_y = (SCREEN_HEIGHT / 2) - (height_map / 2);

  Link link = {.x = 10, .y = 10};

  int keydown = 0;

  while (!WindowShouldClose()) {
    if (keydown == 0 && GetKeyPressed() > 0) {
      if (IsKeyDown(KEY_RIGHT)) {
        if (map[link.y][link.x + 1] != 1) {
          link.x += 1;
        }
      }
      if (IsKeyDown(KEY_LEFT)) {
        if (map[link.y][link.x - 1] != 1) {
          link.x -= 1;
        }
      }
      if (IsKeyDown(KEY_UP)) {
        if (map[link.y - 1][link.x] != 1) {
          link.y -= 1;
        }
      }
      if (IsKeyDown(KEY_DOWN)) {
        if (map[link.y + 1][link.x] != 1) {
          link.y += 1;
        }
      }
      keydown = 1;
    }

    if (GetKeyPressed() == 0) {
      keydown = 0;
    }

    BeginDrawing();
    ClearBackground(RAYWHITE);

    for (int r = 0; r < MAP_HEIGHT; r++) {
      for (int c = 0; c < MAP_WIDTH; c++) {
        int map_val = map[r][c];
        Texture2D texture = textures[map_val];
        DrawTextureEx(texture,
                      (Vector2){origin_x + (c * TEXTURE_SIZE * scale),
                                origin_y + (r * TEXTURE_SIZE * scale)},
                      0.0f, (float)scale, WHITE);

        if (link.x == c && link.y == r) {
          DrawTextureEx(texture_link,
                        (Vector2){origin_x + (link.x * TEXTURE_SIZE * scale),
                                  origin_y + (link.y * TEXTURE_SIZE * scale)},
                        0.0f, (float)scale, WHITE);
        }
      }
    }

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
