#include "RaycastRenderer.h"

RaycastRenderer::RaycastRenderer(int pixelSize, Player* player) : Renderer(pixelSize, player) {
	playerFov = (*player).GetFov();
	playerPos = (*player).GetPosition();
	rayCount = GetScreenWidth() / pixelSize;
}

void RaycastRenderer::RenderGame() {
	playerPos = (*player).GetPosition();

	for (int i = 0; i < rayCount; i++) {
		float currentRayAngle = (*player).GetRotation() + 2 / playerFov - ((float)i * pixelSize / (float)GetScreenWidth()) + 0.45;

		float rayDistance = Raycast(currentRayAngle);
		float wallHeight = (float)pixelSize / rayDistance;
		if (wallHeight < 0) {
			wallHeight = 0;
		}

		Vector2 rayDirection;
		rayDirection.x = sin(currentRayAngle);
		rayDirection.y = cos(currentRayAngle);

		Color lineColor = Map::GetWallColor(playerPos.x + rayDirection.x * rayDistance,
			playerPos.y + rayDirection.y * rayDistance);

		lineColor.r = lineColor.r * (1 / rayDistance) > 255? 255 : lineColor.r * (1 / rayDistance);
		lineColor.g = lineColor.g * (1 / rayDistance) > 255? 255 : lineColor.g * (1 / rayDistance);
		lineColor.b = lineColor.b * (1 / rayDistance) > 255? 255 : lineColor.b * (1 / rayDistance);

		DrawRectangle(i * pixelSize, GetScreenHeight() / 2 - wallHeight * 2 * 100 / pixelSize, pixelSize, wallHeight * 4 * 100 / pixelSize, lineColor);
	}
}

float RaycastRenderer::Raycast(float angle) {
	Vector2 rayDirection;
	float distanceToWall = 0;

	rayDirection.x = sin(angle);
	rayDirection.y = cos(angle);

	while (distanceToWall < 16)
	{
		distanceToWall += 0.001 * pixelSize;
		if (Map::IsWall(playerPos.x + rayDirection.x * distanceToWall, playerPos.y + rayDirection.y * distanceToWall)) {
			return distanceToWall;
		}
	}

	return -1;
}