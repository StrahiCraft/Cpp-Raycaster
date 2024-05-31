#ifndef RENDERER_H_
#define RENDERER_H_

#include "raylib.h"
#include "Player.h"

class Renderer {
protected:
	int pixelSize;
	Player *player;
public:
	Renderer(int pixelSize, Player* player);
	virtual void RenderGame() = 0;
};

#endif // !RENDERER_H_
