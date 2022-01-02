#include "stars.h"
#include "raylib.h"
#include "akinorandom.h"
#include <stddef.h>

void InitStars(Vector3 stars[], Vector2 windowDimensions)
{
	for (size_t i = 0; i < STARS_SIZE; ++i) {
		stars[i].x = akinorandom(windowDimensions.x);
		stars[i].y = akinorandom(windowDimensions.y);
		stars[i].z = akinorandom(255.0f - 1.0f) + 1.0f;
	}
}

void MoveStars(Vector3 stars[], Vector2 windowDimensions, float dT) {
	for (size_t i = 0; i < STARS_SIZE; ++i) {
		stars[i].x -= stars[i].z * dT;
		if (stars[i].x <= 0) {
			stars[i].x += windowDimensions.x;
			stars[i].y = akinorandom(windowDimensions.y);
		}
	}

}

void DrawStars(Vector3 stars[]) {
	for (size_t i = 0; i < STARS_SIZE; ++i) {
		Color colorStar = {
			(unsigned char)(stars[i].z),
			(unsigned char)(stars[i].z),
			(unsigned char)(stars[i].z),
			255
		};
		DrawPixelV((Vector2) { stars[i].x, stars[i].y }, colorStar);
	}
}

