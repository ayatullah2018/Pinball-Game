#include"peedbooster.h"
peedbooster::peedbooster(Vector2D center, float radius): center(center), radius(radius)
{}

Vector2D peedbooster::collideWith(Ball& ball, float collisionTime, int& scorecounter)
{
	if (!collidedLastFrame && (center.py < ball.getStatus().py) && (ball.getStatus().py < center.py + 2 * radius) && (center.px < ball.getStatus().px) && (ball.getStatus().px < center.px + radius * 2))
	{
		collidedLastFrame = true;
		scorecounter = scorecounter + 10;
		return Vector2D{ ball.getStatus().vx * float(10), ball.getStatus().vy * float(10), 0, 0 };
	}
	else
	{
		collidedLastFrame = false;
		return Vector2D{ 0, 0, 0, 0 };  // Should be replaced with the actual collision logic
	}
}
void peedbooster::draw(Interface& interface)
{
	interface.drawspeedboosters(center, radius);
}
