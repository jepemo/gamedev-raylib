#include "raylib.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define MAX_SENTENCES 1

const char *GREETING = "Welcome to this adventure.";

const char *SENTS_MOVE[MAX_SENTENCES] = {
    "You are in the middle "
    "of a forest. Where do you decide to go?"};

const char *SENTS_IN_OUT[MAX_SENTENCES] = {
    "You have reached the entrance of a cave. What will you do?"};

const char *SENTS_YES_NO[MAX_SENTENCES] = {
    "You keep walking but you only see trees and more trees. Do you decide to "
    "continue?"};

const char *MOVE_RESPONSES[2] = {"Go north", "Go south"};
const char *IN_OUT_RESPONSES[2] = {"Enter", "Continue on the outside"};
const char *YES_NO_RESPONSES[2] = {"Yes", "No"};

typedef struct {
  int step;
  int sentence_index;
  int sentence_type; // 0 -> MOVE, 1 -> INOUT, 2 -> YESNO
  int health;
} GameState;

int step = 0;

void draw_gui() {
  int height_bar = SCREEN_HEIGHT / 10;
  DrawRectangle(0, 0, SCREEN_WIDTH, height_bar, GRAY);
  DrawRectangle(0, SCREEN_HEIGHT - height_bar, SCREEN_WIDTH, height_bar, GRAY);
}

const char *get_option(int type, int num) {
  if (type == 0) {
    return MOVE_RESPONSES[num];
  } else if (type == 1) {
    return IN_OUT_RESPONSES[num];
  } else if (type == 2) {
    return YES_NO_RESPONSES[num];
  }

  return 0;
}

void draw_texts(GameState *state) {
  const char *sentence_text = SENTS_MOVE[state->sentence_index];
  const int font_size = 18;
  const int text_width = MeasureText(sentence_text, font_size);
  const int text_x_pos = SCREEN_WIDTH / 2 - text_width / 2;
  const int text_y_pos = SCREEN_HEIGHT / 4;

  DrawText(sentence_text, text_x_pos, text_y_pos, font_size, BLACK);

  // Options
  DrawText(get_option(state->sentence_type, 0), SCREEN_WIDTH / 2,
           SCREEN_HEIGHT / 2, 15, BLACK);

  DrawText(get_option(state->sentence_type, 1), SCREEN_WIDTH / 2,
           (SCREEN_HEIGHT / 2) + 10, 15, BLACK);
}

int main(int argc, char **argv) {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "ADvEnTuRe GaMe");

  GameState game_state = {
      .health = 100, .sentence_index = 0, .sentence_type = 0, .step = 0};

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    draw_gui();
    draw_texts(&game_state);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
