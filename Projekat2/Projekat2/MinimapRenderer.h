#ifndef MINIMAPRENDERER_H_
#define MINIMAPRENDERER_H_
#include "Renderer.h"

class MinimapRenderer : public Renderer {
public:
	MinimapRenderer(int pixelSize, Player* player);
	void RenderGame();
};

#endif // !MINIMAPRENDERER_H_
