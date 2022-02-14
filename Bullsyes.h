#pragma once

#include"GameObjects/Obstacles/Obstacle.h"
class Bullsyes :public Obstacle {

private:
	Vector2D vertix1;
	Vector2D vertix2;
	bool collidedLastFrame = false;
public:
	Bullsyes(Vector2D vertix1, Vector2D vertix2);
	Vector2D collideWith(Ball& ball, float collisionTime, int& scorecounter) override;
	void draw(Interface& interface) override;


};
