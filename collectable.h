#pragma once
#include "GameObjects/Obstacles/Obstacle.h"
class collectable : public Obstacle
{
private:
	int x, y,choice;
	bool collidedLastFrame;

public:
	void draw(Interface& interface) override;
	collectable(int x, int y, int choice);
	Vector2D collideWith(Ball& ball, float collisionTime, int& scorecounter) override;

};
