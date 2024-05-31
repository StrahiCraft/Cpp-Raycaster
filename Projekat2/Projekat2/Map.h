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
	static bool* map;
	static Vector2 playerSpawn;
	// TODO add an array that holds color and texture info of map positions

public:
	static void SetupMap(string mapName);
	static bool IsWall(int x, int y);
	static Vector2 GetPlayerSpawn();
	static int GetWidth();
	static int GetHeight();
};

#endif // !MAP_H_
