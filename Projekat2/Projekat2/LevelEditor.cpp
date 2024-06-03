#include "LevelEditor.h"

LevelEditor::LevelEditor() {
	mapHeight = Map::GetHeight();
	mapWidth = Map::GetWidth();
	playerSpawn = Map::GetPlayerSpawn();
	map = Map::map;

	currentColorIndex = 0;
	LoadColors();

	settingPlayerPosition = false;
	colorMenuOpen = false;
}

void LevelEditor::SelectColor(int colorIndex) {
	if (colorIndex == availableColors.size()) {
		Color newColor;
		newColor.r = 255;
		newColor.g = 255;
		newColor.b = 255;
		newColor.a = 255;
		availableColors.push_back(newColor);
		return;
	}
	try
	{
		if (colorIndex < availableColors.size()) {
			currentColorIndex = colorIndex;
		}
		else {
			throw(colorIndex);
		}
	}
	catch (const std::exception&)
	{
		cout << "COLOR NOT FOUND";
	}
}

void LevelEditor::RemoveColor(int colorIndex) {
	try
	{
		if (colorIndex < availableColors.size()) {
			availableColors.erase(availableColors.begin() + colorIndex);
			currentColorIndex = 0;
		}
		else {
			throw(colorIndex);
		}
	}
	catch (const std::exception&)
	{
		cout << "COLOR NOT FOUND";
	}
}

void LevelEditor::SaveColors() {
	ofstream colorFile("colors.txt");

	for (int i = 0; i < availableColors.size(); i++) {
		colorFile << (int)availableColors[i].r << endl <<
			(int)availableColors[i].g << endl <<
			(int)availableColors[i].b << endl;
	}

	colorFile.close();
}

void LevelEditor::LoadColors() {
	ifstream colorFile("colors.txt");
	string colorLine;

	while (getline(colorFile, colorLine))
	{
		Color currentColor;
		currentColor.a = 255;
		currentColor.r = stoi(colorLine);
		getline(colorFile, colorLine);
		currentColor.g = stoi(colorLine);
		getline(colorFile, colorLine);
		currentColor.b = stoi(colorLine);

		availableColors.push_back(currentColor);
	}

	colorFile.close();
}

void LevelEditor::HandleMouseClick() {
	int mouseX = GetMouseX();
	int mouseY = GetMouseY();

	if (colorMenuOpen) {

		return;
	}

	if (mouseX > GetScreenWidth() - 300 && mouseY > 50 && mouseY < 80) {
		Map::SetPlayerSpawn(playerSpawn);
		Map::SaveMap("map.txt");
		gameStarted = true;
		return;
	}
	if (mouseX > GetScreenWidth() - 300 && mouseY > 150 && mouseY < 180) {
		settingPlayerPosition = !settingPlayerPosition;
		return;
	}
	if (mouseX > GetScreenWidth() - 300 && mouseY > 300 && mouseY < 500) {
		SelectColor((mouseX - GetScreenWidth() + 300) / 50 + ((mouseY - 300) / 50) * 6);
	}
}

void LevelEditor::HandleRightClick() {
	int mouseX = GetMouseX();
	int mouseY = GetMouseY();
	if (mouseX > GetScreenWidth() - 300 && mouseY > 300 && mouseY < 500) {
		RemoveColor((mouseX - GetScreenWidth() + 300) / 50 + ((mouseY - 300) / 50) * 6);
	}
}

void LevelEditor::ChangeColorSlider() {
	int mouseX = GetMouseX();
	int mouseY = GetMouseY();

	if (mouseX < GetScreenWidth() - 300 || mouseX > GetScreenWidth() - 45) {
		return;
	}

	if (mouseY > 545 && mouseY < 585) {
		availableColors[currentColorIndex].r = mouseX + 300 - GetScreenWidth();
		return;
	}

	if (mouseY > 595 && mouseY < 635) {
		availableColors[currentColorIndex].g = mouseX + 300 - GetScreenWidth();
		return;
	}

	if (mouseY > 645 && mouseY < 685) {
		availableColors[currentColorIndex].b = mouseX + 300 - GetScreenWidth();
		return;
	}
}

void LevelEditor::SetMap() {
	map = Map::map;
}

void LevelEditor::PlaceWall() {
	int pixelSize = GetScreenWidth() / mapWidth / 2;
	if (pixelSize > mapHeight * GetScreenHeight()) {
		pixelSize = GetScreenHeight() / mapHeight / 2;
	}
	int mouseX = GetMouseX() / pixelSize;
	int mouseY = GetMouseY() / pixelSize;

	if (mouseX > mapWidth - 1 || mouseX < 0 || mouseY > mapHeight - 1 || mouseY < 0) {
		return;
	}

	if (settingPlayerPosition) {
		if (!map[mouseX + mapHeight * mouseY]){
			playerSpawn.x = mouseX;
			playerSpawn.y = mouseY;
		}
		return;
	}

	map[mouseX + mapHeight * mouseY] = true;
	Map::SetWallColor(mouseX, mouseY, availableColors[currentColorIndex]);
}

void LevelEditor::RemoveWall() {
	if (settingPlayerPosition) {
		return;
	}

	int pixelSize = GetScreenWidth() / mapWidth / 2;
	if (pixelSize > mapHeight * GetScreenHeight()) {
		pixelSize = GetScreenHeight() / mapHeight / 2;
	}
	int mouseX = GetMouseX() / pixelSize;
	int mouseY = GetMouseY() / pixelSize;

	if (mouseX > mapWidth - 1 || mouseX < 0 || mouseY > mapHeight - 1 || mouseY < 0) {
		return;
	}

	map[mouseX + mapHeight * mouseY] = false;
}

int LevelEditor::GetMapWidth()
{
	return mapWidth;
}

int LevelEditor::GetMapHeight()
{
	return mapHeight;
}

Vector2 LevelEditor::GetPlayerSpawn() {
	return playerSpawn;
}

void LevelEditor::RenderUI() {
	DrawText("START GAME", GetScreenWidth() - 300, 50, 30, WHITE);
	if (!settingPlayerPosition) {
		DrawText("MOVE PLAYER", GetScreenWidth() - 300, 150, 30, WHITE);
	}
	else {
		DrawText("MOVING PLAYER", GetScreenWidth() - 300, 150, 30, RED);
	}
	DrawText("COLORS", GetScreenWidth() - 300, 250, 30, availableColors[currentColorIndex]);

	for (int i = 0; i < availableColors.size(); i++) {
		DrawRectangle(GetScreenWidth() - 300 + (i % 6) * 50, 300 + (i / 6) * 50, 40, 40, availableColors[i]);
	}

	DrawRectangle(GetScreenWidth() - 305, 545, 265, 40, GRAY);
	DrawRectangle(GetScreenWidth() - 305, 595, 265, 40, GRAY);
	DrawRectangle(GetScreenWidth() - 305, 645, 265, 40, GRAY);

	DrawRectangle(GetScreenWidth() - 300, 550, (int)availableColors[currentColorIndex].r, 30, RED);
	DrawRectangle(GetScreenWidth() - 300, 600, (int)availableColors[currentColorIndex].g, 30, GREEN);
	DrawRectangle(GetScreenWidth() - 300, 650, (int)availableColors[currentColorIndex].b, 30, BLUE);

	if (availableColors.size() == 24) {
		return;
	}
	DrawText("[+]", GetScreenWidth() - 300 + (availableColors.size() % 6) * 50, 300 + (availableColors.size() / 6) * 50, 40, WHITE);
}
