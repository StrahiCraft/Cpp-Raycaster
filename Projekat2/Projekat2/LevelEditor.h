#ifndef LEVELEDITOR_H_
#define LEVELEDITOR_H_
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "raylib.h"
#include "Map.h"

using namespace std;

class LevelEditor {
private:
	int mapHeight;
	int mapWidth;
	bool* map;
	Vector2 playerSpawn;

	Color* colors;
	int currentColorIndex;
	vector<Color> availableColors;

	bool settingPlayerPosition;
	bool colorMenuOpen;
public:
	LevelEditor();

	void SelectColor(int colorIndex);
	void RemoveColor(int colorIndex);

	void SaveColors();
	void LoadColors();

	bool gameStarted;

	void HandleMouseClick();
	void HandleRightClick();
	void ChangeColorSlider();
	void SetMap();

	void PlaceWall();
	void RemoveWall();

	int GetMapWidth();
	int GetMapHeight();
	Vector2 GetPlayerSpawn();

	void RenderUI();
};

#endif // !LEVELEDITOR_H_
