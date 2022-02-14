#pragma once


#include "GameObjects/Obstacles/Obstacle.h"

// Represents a thin vertically infinite wall, on which the ball can bounce
class Floor : public Obstacle
{
private:
	float position;  // The horizontal position of the wall
	bool collidedLastFrame = false;  // Whether or not the last frame was a collision (to prevent flapping)

public:
	explicit Floor(float position);
	void draw(Interface& interface) override;
	Vector2D collideWith(Ball& ball, float collisionTime, int& scorecounter) override;
};