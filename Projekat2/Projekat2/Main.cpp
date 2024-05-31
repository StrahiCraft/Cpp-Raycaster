#include "raylib.h"
#include "Player.h"
#include "Map.h"
#include "MinimapRenderer.h"

int main() {
	const int screenWidth = 800;
	const int screenHeight = 600;

	InitWindow(screenWidth, screenHeight, "Projekat 2");

	SetTargetFPS(144);

	Map::SetupMap("map.txt");
	Player player(Map::GetPlayerSpawn(), 0, 90, 5, 5);

	MinimapRenderer minimapRenderer(20, &player);

	Renderer* renderer = &minimapRenderer;

	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(BLACK);

		renderer->RenderGame();
		player.HandleInput();

		EndDrawing();
	}

	CloseWindow();

	return 0;
}