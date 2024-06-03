#include "raylib.h"
#include "Player.h"
#include "Map.h"
#include "MinimapRenderer.h"
#include "RaycastRenderer.h"
#include "LevelEditor.h"

void GameLoop() {
	Player player(Map::GetPlayerSpawn(), 0, 90, 100, 180);

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
}

int main() {
	const int screenWidth = 1280;
	const int screenHeight = 720;

	InitWindow(screenWidth, screenHeight, "Projekat 2");

	SetTargetFPS(144);
	Map::SetupMap("map.txt");
	Player player(Map::GetPlayerSpawn(), 0, 90, 100, 180);
	
	LevelEditor levelEditor;
	MinimapRenderer minimapRenderer(GetScreenWidth() / levelEditor.GetMapWidth() / 2, &player);

	if (levelEditor.GetMapHeight() < levelEditor.GetMapWidth()) {
		minimapRenderer = MinimapRenderer(GetScreenHeight() / levelEditor.GetMapHeight(), &player);
	}

	while (!WindowShouldClose()) {
		BeginDrawing();

		ClearBackground(BLACK);

		minimapRenderer.RenderGame();
		levelEditor.RenderUI();
		
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			levelEditor.HandleMouseClick();
		}
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
			levelEditor.ChangeColorSlider();
			levelEditor.PlaceWall();
			player.SetPosition(levelEditor.GetPlayerSpawn());
		}
		if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
			levelEditor.RemoveWall();
		}
		if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
			levelEditor.HandleRightClick();
		}
		if (levelEditor.gameStarted) {
			GameLoop();
			levelEditor.gameStarted = false;
			levelEditor.SetMap();
		}

		EndDrawing();
	}

	levelEditor.SaveColors();

	CloseWindow();

	return 0;
}