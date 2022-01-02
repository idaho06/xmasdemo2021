#pragma once
#include "raylib.h"


void InitAkinoText(char **text, Font *font, float *textWidth);
void DrawAkinoText(const char* text, Font font, float textWidth, Vector2 winDim, const double time);
//void UnloadAkinoText(Font* font);
