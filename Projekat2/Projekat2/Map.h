#ifndef MAP_H_
#define MAP_H_
#include <iostream>
#include "raylib.h"
#include <fstream>
#include <string>

using namespace std;

class Map {
private:
	static int width;
	static int height;
	static Vector2 playerSpawn;
	static Color* mapColors;
public:
	static bool* map;
	static void SetupMap(string mapName);
	static void SaveMap(string name);
	static bool IsWall(int x, int y);
	static Color GetWallColor(int x, int y);
	static void SetWallColor(int x, int y, Color color);
	static Vector2 GetPlayerSpawn();
	static void SetPlayerSpawn(Vector2 value);
	static int GetWidth();
	static int GetHeight();
};

#endif // !MAP_H_
