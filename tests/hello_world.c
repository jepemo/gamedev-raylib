#include "raylib.h"

int main(void) {
	const int screenWidth = 640;
	const int screenHeight = 480;

	InitWindow(screenWidth, screenHeight, "Raylib - hello world");

	SetTargetFPS(30);

	const char* text = "Antistar!";
	const int font_size = 50;
	const int text_width = MeasureText(text, font_size);
	const int text_x_pos = screenWidth / 2 - text_width / 2;
	const int text_y_pos = screenHeight / 2;

	while (!WindowShouldClose()) {
		BeginDrawing();
			ClearBackground(RAYWHITE);
			DrawText(text, text_x_pos, text_y_pos, font_size, LIGHTGRAY);
		EndDrawing();
	}

	CloseWindow();

	return 0;
}
