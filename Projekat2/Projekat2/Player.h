#ifndef PLAYER_H_
#define PLAYER_H_
#include <raylib.h>
class Player {
private:
	Vector2 position;
	float rotation;
	float fov;

	float speed;
	float rotationSpeed;
public:
	Player();
	Player(Vector2 position, float rotation, float fov, float speed, float rotationSpeed);

	void HandleInput();
	void Move(int direction); // 1 for foreward -1 for backward
	Vector2 GetPosition();
	float GetRotation();
};

#endif // !PLAYER_H_
