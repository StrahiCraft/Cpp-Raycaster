#include "Map.h"

int Map::width = 0;
int Map::height = 0;
bool* Map::map;
Color* Map::mapColors;
Vector2 Map::playerSpawn;

bool Map::IsWall(int x, int y) {
	return map[x + y * width];
}

Color Map::GetWallColor(int x, int y)
{
	return mapColors[x + y * width];
}

void Map::SetWallColor(int x, int y, Color color) {
	mapColors[x + y * width] = color;
}

Vector2 Map::GetPlayerSpawn(){
	return playerSpawn;
}

void Map::SetPlayerSpawn(Vector2 value) {
	playerSpawn = value;
}

void Map::SetupMap(string name) {
	ifstream mapFile(name);
	string mapFileLine = "";

	getline(mapFile, mapFileLine);
	width = stoi(mapFileLine);
	getline(mapFile, mapFileLine);
	height = stoi(mapFileLine);

	map = (bool*)calloc(width * height, sizeof(bool*));
	mapColors = (Color*)calloc(width * height, sizeof(Color*));

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			if (mapFile.get() == '#') {
				map[x + y * height] = true;
			}
			else {
				map[x + y * height] = false;
			}
		}
		getline(mapFile, mapFileLine);
	}

	getline(mapFile, mapFileLine);
	playerSpawn.x = stoi(mapFileLine);
	getline(mapFile, mapFileLine);
	playerSpawn.y = stoi(mapFileLine);

	int i = 0;
	while (getline(mapFile, mapFileLine))
	{
		if (mapFileLine != "" && mapFileLine != "\n") {
			mapColors[i].r = stoi(mapFileLine);
			getline(mapFile, mapFileLine);
			mapColors[i].g = stoi(mapFileLine);
			getline(mapFile, mapFileLine);
			mapColors[i].b = stoi(mapFileLine);
			mapColors[i].a = 255;
		}
		i++;
	}

	mapFile.close();
}

void Map::SaveMap(string name) {
	ofstream mapFile(name);
	
	mapFile << width << endl << height << endl;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (map[j + i * width]) {
				mapFile << '#';
			}
			else {
				mapFile << ' ';
			}
		}
		mapFile << endl;
	}

	mapFile << playerSpawn.x << endl << playerSpawn.y << endl;

	for (int i = 0; i < width * height; i++) {
		mapFile << (int)mapColors[i].r << endl <<
			(int)mapColors[i].g << endl <<
			(int)mapColors[i].b << endl;
	}

	mapFile.close();
}

int Map::GetWidth() {
	return width;
}

int Map::GetHeight() {
	return height;
}