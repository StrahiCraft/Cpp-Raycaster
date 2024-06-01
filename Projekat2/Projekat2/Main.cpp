#include "raylib.h"
#include "Player.h"
#include "Map.h"
#include "MinimapRenderer.h"
#include "RaycastRenderer.h"

int main() {
	const int screenWidth = 1280;
	const int screenHeight = 720;

	InitWindow(screenWidth, screenHeight, "Projekat 2");

	SetTargetFPS(144);

	Map::SetupMap("map.txt");
	Player player(Map::GetPlayerSpawn(), 0, 60, 100, 180);

	MinimapRenderer minimapRenderer(20, &player);
	RaycastRenderer raycastRenderer(5, &player);

	Renderer* renderer = &raycastRenderer;

	bool renderingMinimap = false;

	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(BLACK);

		if (IsKeyPressed(KEY_R)) {
			if (renderingMinimap) {
				renderer = &raycastRenderer;
			}
			else {
				renderer = &minimapRenderer;
			}
			renderingMinimap = !renderingMinimap;
		}

		renderer->RenderGame();
		player.HandleInput();

		EndDrawing();
	}

	CloseWindow();

	return 0;
}