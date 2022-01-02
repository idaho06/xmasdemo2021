#include "screw.h"
#include <math.h>


//void DrawScrew(Texture2D tower, Vector2 windowDimensions, float dT, float time)
void DrawScrew(Texture2D tower, Vector2 windowDimensions, const double time)
{
	float vel = 100.0f;
	float distortion = 0.0f;
	distortion = (cosf((float)time/3.5f) * 60.0f) + 100.0f;
	//DrawText(TextFormat("dist: %f", distortion), (int)windowDimensions.x / 2, (int)windowDimensions.y/2, 20, RED);
	//int towery = 0;
	Rectangle rec = { 0.0f, 0.0f, (float)tower.width, 1.0f };
	Vector2 pos = { 0.0f, 0.0f };

	for (int y = 0; y < windowDimensions.y; ++y) {
		// calculate vertical displacement
		//int apparenty = 0;
		int apparenty = y + (int)(time * vel);

		// calculate unrolling
		apparenty += (int)(sinf((float)y / distortion) * vel);

		// calculate speed changing
		apparenty += (int)(sinf((float)time)*vel);

		// 
		rec.y = (float)(apparenty % (int)(tower.height - 1));
		pos.y = (float)y;
		DrawTextureRec(tower, rec, pos, WHITE);
		pos.x = (float)(windowDimensions.x - (float)tower.width);
		pos.y = (float)(windowDimensions.y - (float)y - 1.0f);
		DrawTextureRec(tower, rec, pos, WHITE);
		pos.x = 0.0f;
	}
}

