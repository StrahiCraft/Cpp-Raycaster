#include "Map.h"

int Map::width = 0;
int Map::height = 0;
bool* Map::map;
Vector2 Map::playerSpawn;

bool Map::IsWall(int x, int y) {
	return map[x + y * width];
}

Vector2 Map::GetPlayerSpawn(){
	return playerSpawn;
}

void Map::SetupMap(string name) {
	ifstream mapFile(name);
	string mapFileLine = "";

	getline(mapFile, mapFileLine);
	width = stoi(mapFileLine);
	getline(mapFile, mapFileLine);
	height = stoi(mapFileLine);

	map = (bool*)calloc(width * height, sizeof(bool*));

	int i = 0;
	while (i < width * height) {
		if (mapFile.get() == '#') {
			map[i] = true;
		}
		i++;
	}

	playerSpawn.x = 1;
	playerSpawn.y = 2;

	// TODO handle loading color and texture data

	mapFile.close();
}

int Map::GetWidth() {
	return width;
}

int Map::GetHeight() {
	return height;
}
