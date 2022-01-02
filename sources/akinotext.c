#include "akinotext.h"
#include "raylib.h"
#define SPACING -2.0f
#define SPEED 360.0f

void InitAkinoText(char** text, Font *font, float* textWidth)
{
	*text = "Saludos de Idaho06 de AkinoSoft! Merry XMas and happy new year 2022! "
		"Another year, another deadline not reached. "
		"Feel ThE AkinoPoWeR - JuSt FrUiT It - "
		"GFX&code: Idaho06 - MUSIC: 'Related Memories' by edZeS & Auricom - Made with Raylib, GIMP and Blender. "
		"GREETINGS (in no particular order) GO TO: "
		"ikkante palo_power rivudo taml46 ouros reemplazable "
		"titonosfe Jesus Sue Brama Rheovarn Boni DavidBokeh "
		"malonsodos gamer314314 esteneitor22 itorres Qetu ruben3d "
		"- Press ESC any time to exit, F key to switch fullscreen mode. -"
		"                                                      "
		;

	*font = LoadFont(ASSETS_PATH"retrolaserfont.png");

	*textWidth = MeasureTextEx(*font, *text, (float)font->baseSize, SPACING).x;
}

void DrawAkinoText(const char* text, Font font, float textWidth, Vector2 winDim, const double time)
{
	double messageTime = (double)textWidth / SPEED;
	double t2 = time;
	do {
		if (t2 >= messageTime) {
			t2 -= messageTime;
		}
	} while (t2 > messageTime);

	Vector2 pos = {winDim.x - ((float)t2 * SPEED), winDim.y - (float)font.baseSize};
	DrawTextEx(font, text, pos, (float)font.baseSize, SPACING, WHITE);
}

//void UnloadAkinoText(Font* font)
//{
//	UnloadFont(*font);
//}

