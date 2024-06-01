#ifndef RAYCASTRENDERER_H_
#define RAYCASTRENDERER_H_
#include "Renderer.h"
#include "Map.h"
#include "raylib.h"
#include <math.h>

class RaycastRenderer : public Renderer {
private:
	float playerFov;
	int rayCount;
	float Raycast(float angle);
public:
	RaycastRenderer(int pixelSize, Player* player);
	void RenderGame();
};

#endif // !RAYCASTRENDERER_H_
