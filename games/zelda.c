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
	{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};


int main (int argc, char **argv) {
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Rpg game");
	
	Texture2D textures[2] = {
		LoadTexture(ASSETS_DIR"/grass.png"), // 0
		LoadTexture(ASSETS_DIR"/water.png")  // 1
	};
	
	int scale = 4;
	int width_map = MAP_WIDTH * TEXTURE_SIZE * scale;
	int height_map = MAP_HEIGHT * TEXTURE_SIZE * scale;
	int origin_x = (SCREEN_WIDTH / 2) - (width_map / 2);
	int origin_y = (SCREEN_HEIGHT / 2) - (height_map / 2);
	
	
	
	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(RAYWHITE);
		
		for (int r = 0; r < MAP_HEIGHT; r++) {
			for (int c = 0; c < MAP_WIDTH; c++) {
				int map_val = map[r][c];
				Texture2D texture = textures[map_val];	
				DrawTextureEx(
					texture,
					(Vector2) {
						origin_x + (c * TEXTURE_SIZE * scale),
						origin_y + (r * TEXTURE_SIZE * scale)
					}, 
					0.0f, 
					(float)scale,
					WHITE);
			}
		}
		
		EndDrawing();
	}


	CloseWindow();
	return 0;
}
