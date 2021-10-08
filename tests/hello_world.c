#include "raylib.h"

int main(void) {
	const int screenWidth = 640;
	const int screenHeight = 480;

	InitWindow(screenWidth, screenHeight, "Raylib - hello world");

	SetTargetFPS(30);

	while (!WindowShouldClose()) {
		BeginDrawing();
			ClearBackground(RAYWHITE);
			DrawText("Hello world", screenWidth / 2, screenHeight / 2, 20, LIGHTGRAY);
		EndDrawing();
	}

	CloseWindow();

	return 0;
}
