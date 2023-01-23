#include "raylib.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define MAX_SENTENCES 3

const char *GREETING = "Welcome to this adventure.";

const char *SENTS_MOVE[MAX_SENTENCES][3] = {
    {"You are in the middle of a forest.", "Where do you decide to go?", ""},
    {"You see a bridge", "But doesn't look safe", ""},
    {"There is a golden path", "It ontinues into the mountains.", ""}};

const char *SENTS_IN_OUT[MAX_SENTENCES][3] = {
    {"You have reached the entrance of a cave.", "What will you do?", ""},
    {"There is a door", "in front of you", "It is made of wood"},
    {"Two trees join together", "to make a portal",
     "It  gives off a strong energy"}};

const char *SENTS_YES_NO[MAX_SENTENCES][3] = {
    {"You keep walking but you only", " see trees and more trees.",
     "Do you decide to continue?"},
    {"You see red monk", "Do you want to", "fight?"},
    {"You see a magic sword", "Do you want to pick it up?", ""}};

const char *RESPONSES[3][2] = {{"Go north", "Go south"},
                               {"Enter", "Continue on the outside"},
                               {"Yes", "No"}};

int key_pressed = 0;

typedef struct {
  int step;
  int sentence_index;
  int sentence_type; // 0 -> MOVE, 1 -> INOUT, 2 -> YESNO
  int health;
} GameState;

int step = 0;

void draw_gui() {
  int height_bar = SCREEN_HEIGHT / 10;
  DrawRectangle(0, 0, SCREEN_WIDTH, height_bar, BLACK);
  DrawRectangle(0, SCREEN_HEIGHT - height_bar, SCREEN_WIDTH, height_bar, BLACK);
}

const char *get_option(int type, int num) { return RESPONSES[type][num]; }

const char **get_sentence(int type, int idx) {
  if (type == 0) {
    return SENTS_MOVE[idx];
  } else if (type == 1) {
    return SENTS_IN_OUT[idx];
  } else if (type == 2) {
    return SENTS_YES_NO[idx];
  }

  return 0;
}

void draw_option(int type, int num, int height_diff) {
  // Options
  char option[128];
  sprintf(option, "%d - ", num + 1);
  strcat(option, get_option(type, num));

  const int font_size = 20;
  const int text_width = MeasureText(option, font_size);

  DrawText(option, (SCREEN_WIDTH / 2) - (text_width / 2),
           SCREEN_HEIGHT / 2 + height_diff, 15, BLACK);
}

void draw_texts(GameState *state) {
  const char **sentence_text =
      get_sentence(state->sentence_type, state->sentence_index);

  const int font_size = 24;
  const int text_width = MeasureText(sentence_text[0], font_size);
  const int text_x_pos = SCREEN_WIDTH / 2 - text_width / 2;
  const int text_y_pos = SCREEN_HEIGHT / 4;

  DrawText(sentence_text[0], text_x_pos, text_y_pos, font_size, BLACK);
  DrawText(sentence_text[1], text_x_pos, text_y_pos + 20, font_size, BLACK);
  DrawText(sentence_text[2], text_x_pos, text_y_pos + 40, font_size, BLACK);

  // Options
  draw_option(state->sentence_type, 0, 0);
  draw_option(state->sentence_type, 1, 20);
}

void update_state(GameState *state) {
  if (key_pressed == 0) {
    if (IsKeyDown(KEY_ONE) || IsKeyDown(KEY_TWO)) {
      key_pressed = 1;
      state->health -= 1;
      state->step += 1;
      state->sentence_type = rand() % 3;
      state->sentence_index = rand() % MAX_SENTENCES;
    }
  }

  if (IsKeyUp(KEY_ONE) && IsKeyUp(KEY_TWO)) {
    key_pressed = 0;
  }
}

int main(int argc, char **argv) {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "ADvEnTuRe GaMe");

  GameState game_state = {
      .health = 100, .sentence_index = 0, .sentence_type = 0, .step = 0};

  while (!WindowShouldClose()) {
    update_state(&game_state);

    BeginDrawing();
    ClearBackground(RAYWHITE);
    draw_gui();
    draw_texts(&game_state);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
