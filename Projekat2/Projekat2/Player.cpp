#include "Player.h"
#include <math.h>
#include <iostream>
#include <string>

Player::Player() {
	position = Vector2();
	rotation = 0;
	fov = 90;
	speed = 1;
	rotationSpeed = 90;
}

Player::Player(Vector2 position, float rotation, float fov, float speed, float rotationSpeed) {
	this->position = position;
	this->rotation = rotation;
	this->fov = fov;
	this->speed = speed;
	this->rotationSpeed = rotationSpeed;
}

void Player::HandleInput() {
	if (IsKeyDown(KEY_A)) {
		rotation -= rotationSpeed * GetFrameTime();
		DrawRectangle(0, 0, 10, 10, BLUE);
	}
	if (IsKeyDown(KEY_D)) {
		rotation += rotationSpeed * GetFrameTime();
		DrawRectangle(0, 0, 10, 10, BLUE);
	}
	if (rotation < 0) {
		rotation = 360 - rotation;
	}
	if (rotation > 360) {
		rotation -= 360;
	}

	if (IsKeyDown(KEY_W)) {
		Move(1);
		DrawRectangle(0, 0, 10, 10, BLUE);
	}
	if (IsKeyDown(KEY_S)) {
		Move(-1);
		DrawRectangle(0, 0, 10, 10, BLUE);
	}
}

void Player::Move(int direction) {
	position.x += sin(rotation) * direction * speed * GetFrameTime();
	position.y += cos(rotation) * direction * speed * GetFrameTime();

	std::string message = "X = " + std::to_string(position.x) + " Y = " + std::to_string(position.y);
	DrawText(message.c_str(), 100, 100, 20, BLUE);

	// check for collision, move back if colliding
}

Vector2 Player::GetPosition()
{
	
	return position;
}

float Player::GetRotation() {
	return rotation;
}