#include "akinomodels.h"
#include <math.h>
#define TIMEPERMODEL 10
#define MODELSIZE 6
#define TOTALTIME TIMEPERMODEL*MODELSIZE


void InitAkinoModels(Model models[]){
	models[0] = LoadModel(ASSETS_PATH"xmastree.glb");
	models[1] = LoadModel(ASSETS_PATH"torusknot03.glb");
	models[2] = LoadModel(ASSETS_PATH"sponge.glb");
	models[3] = LoadModel(ASSETS_PATH"twistedtorus.glb");
	models[4] = LoadModel(ASSETS_PATH"teapot.glb");
	models[5] = LoadModel(ASSETS_PATH"torusknot01.glb");

}

void UnloadAkinoModels(Model models[]) {
	UnloadModel(models[0]);
	UnloadModel(models[1]);
	UnloadModel(models[2]);
	UnloadModel(models[3]);
	UnloadModel(models[4]);
	UnloadModel(models[5]);
}

void DrawAkinoModels(Model models[], double time)
{
	Camera3D camera = { 0 };
	camera.position = (Vector3){ 30.0f, 20.0f, 30.0f };
	camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
	camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
	camera.fovy = 70.0f;
	camera.projection = CAMERA_PERSPECTIVE;

	float scale = (2.0f + (float)sinf((float)time)) * 1.7f;

	// Move camera around the scene
	float cameraTime = (float)time * 0.3f;
	camera.position.x = (float)cosf(cameraTime) * 40.0f;
	camera.position.z = (float)sinf(cameraTime) * 40.0f;

	Vector3 position = { 0.0f, 0.0f, 0.0f };    // Set model position

	double t2 = time / (double)TIMEPERMODEL;
	do {
		if (t2 >= (double)MODELSIZE) {
			t2 -= (double)MODELSIZE;
		} 
	} while (t2 >= (double)MODELSIZE);

	int model = (int)t2;

	if (model >= MODELSIZE) {
		model = MODELSIZE - 1;
	}
	if (model <= 0) {
		model = 0;
	}

	BeginMode3D(camera);

	DrawModelWires(models[model], position, scale, WHITE);

	EndMode3D();
}
