#include "Ceiling.h"

#include <cmath>
using namespace std;

Ceiling::Ceiling(float position) : position(position), collidedLastFrame(false) {}

void Ceiling::draw(Interface& interface)
{
	interface.drawCeiling(position);
}

Vector2D Ceiling::collideWith(Ball& ball, float collisionTime, int& scorecounter)
{
	if (!collidedLastFrame && abs(position - ball.getStatus().py) < ball.getRadius())
	{
		collidedLastFrame = true;
		scorecounter = scorecounter + 10;
		return Vector2D{ 0 , ball.getStatus().vy * float (-2) } / collisionTime;
	}
	else
	{
		collidedLastFrame = false;
		return Vector2D{ 0, 0 };
	}
}
