#pragma once
#include "GameObjects/Obstacles/Obstacle.h"
class peedbooster : public Obstacle
{
private:
	Vector2D center;
	float radius;
	bool collidedLastFrame = false;
public:
	void draw(Interface& interface) override;
	peedbooster(Vector2D center, float radius);
	Vector2D collideWith(Ball& ball, float collisionTime, int& scorecounter) override;


};
