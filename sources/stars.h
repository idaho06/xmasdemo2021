#pragma once
#define STARS_SIZE 1000
#include "raylib.h"

void InitStars(Vector3 stars[], Vector2 windowDimensions);

void MoveStars(Vector3 stars[], Vector2 windowDimensions, float dT);

void DrawStars(Vector3 stars[]);
