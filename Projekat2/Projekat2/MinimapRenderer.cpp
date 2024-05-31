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

	Vector2 playerPos = (*player).GetPosition();


	// Draws player square
	DrawRectangle(playerPos.x * pixelSize + pixelSize / 4, playerPos.y * pixelSize + pixelSize / 4, pixelSize / 2, pixelSize / 2, RED);

	// Draws player look direction
	DrawLine(playerPos.x * pixelSize + pixelSize / 2, playerPos.y * pixelSize + pixelSize / 2,
		playerPos.x * pixelSize + pixelSize / 2 + pixelSize * sin((*player).GetRotation()),
		playerPos.y * pixelSize + pixelSize / 2 + pixelSize * cos((*player).GetRotation()), GREEN);
}