#include "MinimapRenderer.h"
#include "Map.h"

MinimapRenderer::MinimapRenderer(int pixelSize, Player* player) : Renderer(pixelSize, player) {

}

void MinimapRenderer::RenderGame() {
	int mapWidth = Map::GetWidth();
	int mapHeight = Map::GetHeight();

	for (int x = 0; x < mapWidth; x++) {
		for (int y = 0; y < mapHeight; y++) {
			if (Map::IsWall(x, y)) {
				DrawRectangle(x * pixelSize, y * pixelSize, pixelSize, pixelSize, WHITE);
			}
		}
	}

	playerPos = (*player).GetPosition();
	playerPos.x = (int)playerPos.x;
	playerPos.y = (int)playerPos.y;


	// Draws player square
	DrawRectangle(playerPos.x * pixelSize + pixelSize / 4, playerPos.y * pixelSize + pixelSize / 4, pixelSize / 2, pixelSize / 2, RED);

	// Draws the players fov
	float playerFov = (*player).GetFov();
	int rayCount = GetScreenWidth() / pixelSize;;

	for (int i = 0; i < rayCount; i++) {
		float currentRayAngle = (*player).GetRotation() + 2 / playerFov - ((float)i * pixelSize / (float)GetScreenWidth()) + 0.5;
		
		DrawLine(playerPos.x * pixelSize + pixelSize / 2, playerPos.y * pixelSize + pixelSize / 2,
			playerPos.x * pixelSize + pixelSize / 2 + pixelSize * sin(currentRayAngle),
			playerPos.y * pixelSize + pixelSize / 2 + pixelSize * cos(currentRayAngle), BLUE);
	}

	// Draws player look direction
	DrawLine(playerPos.x * pixelSize + pixelSize / 2, playerPos.y * pixelSize + pixelSize / 2,
		playerPos.x * pixelSize + pixelSize / 2 + pixelSize * sin((*player).GetRotation()),
		playerPos.y * pixelSize + pixelSize / 2 + pixelSize * cos((*player).GetRotation()), GREEN);

}