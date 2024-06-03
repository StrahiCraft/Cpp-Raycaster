#include "Player.h"
#include "Map.h"
#include <math.h>

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
		rotation += rotationSpeed * GetFrameTime() * GetFrameTime();
	}
	if (IsKeyDown(KEY_D)) {
		rotation -= rotationSpeed * GetFrameTime() * GetFrameTime();
	}

	if (IsKeyDown(KEY_W)) {
		Move(1);
	}
	if (IsKeyDown(KEY_S)) {
		Move(-1);
	}
}

void Player::Move(int direction) {
	Vector2 movement;
	movement.x = sin(rotation) * direction * speed * GetFrameTime();
	movement.y = cos(rotation) * direction * speed * GetFrameTime();

	if (!Map::IsWall(position.x + movement.x, position.y)) {
		position.x += movement.x * GetFrameTime();
	}
	if (!Map::IsWall(position.x, position.y + movement.y)) {
		position.y += movement.y * GetFrameTime();
	}
}

Vector2 Player::GetPosition()
{
	return position;
}

float Player::GetRotation() {
	return rotation;
}

float Player::GetFov() {
	return fov;
}

void Player::SetPosition(Vector2 newPosition) {
	position = newPosition;
}
