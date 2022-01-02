#include <stdlib.h>
#include "raylib.h"
#include "akinorandom.h"
#include "stars.h"
#include "screw.h"
#include "akinomodels.h"
#include "akinotext.h"

#ifdef _WIN32
#ifndef _DEBUG
int WinMain(void) {
#else
int main(void) {
#endif
#else
int main(void) {
#endif
	// VSync
	SetConfigFlags(FLAG_VSYNC_HINT);

	// Window init
	Vector2 windowDimensions = { 0,0 };
	windowDimensions.x = 1280.0f;
	windowDimensions.y = 720.0f;
	InitWindow((int)windowDimensions.x, (int)windowDimensions.y, "XMas Demo 2021");
	Image icon = LoadImage(ASSETS_PATH"akinoico_small.png");
	SetWindowIcon(icon);
	//ToggleFullscreen();

	// Audio init
	InitAudioDevice();

	Music music = LoadMusicStream(ASSETS_PATH"related_memories.xm");

	Vector3 stars[STARS_SIZE] = { 0 };
	InitStars(stars, windowDimensions);

	// Textures must be loaded after InitWindow, they require opengl context
	Texture2D logo = LoadTexture(ASSETS_PATH"akinosoft_logo.png");
	Vector2 logoPos = { (float)((windowDimensions.x / 2) - (logo.width * 1 / 2)), (float)(0) };
	Texture2D tower = LoadTexture(ASSETS_PATH"candy02.png");

	// Models must be loaded after InitWindow, they require opengl context
	Model models[6] = { 0 };
	InitAkinoModels(models);

	//Texts
	// NOTE: Textures/Fonts MUST be loaded after Window initialization (OpenGL context is required)
	char *text01 = NULL;
	Font akinoFont = {0};
	float textWidth = 0.0f;
	InitAkinoText(&text01, &akinoFont, &textWidth);


	SetTargetFPS(90);
	PlayMusicStream(music);

	while (!WindowShouldClose()) {
		// check keyboard
		if (IsKeyPressed(KEY_F)) ToggleFullscreen();

		// Update Music
		UpdateMusicStream(music);

		// delta time (time since last frame)
		const float dT = GetFrameTime();
		const double T = GetTime();

		MoveStars(stars, windowDimensions, dT);

		BeginDrawing();

		ClearBackground(BLACK);
		
		DrawStars(stars);

		DrawScrew(tower, windowDimensions, T);

		DrawTextureEx(logo, logoPos, 0.0f, 1.0f, WHITE);

		DrawAkinoModels(models, T);

		DrawAkinoText(text01, akinoFont, textWidth, windowDimensions, T);

		EndDrawing();
	}

	UnloadMusicStream(music);
	CloseAudioDevice();

	UnloadImage(icon);
	UnloadTexture(logo);
	UnloadTexture(tower);
	UnloadAkinoModels(models);
	UnloadFont(akinoFont);
	//UnloadAkinoText(&akinoFont);

	CloseWindow();
	return EXIT_SUCCESS;
}
