#include"Floor.h"
#include<cmath>
using namespace std;
Floor::Floor(float position):position(position), collidedLastFrame(false)
{

}
void Floor::draw(Interface& interface)
{
	interface.drawFloor(position);
 }
Vector2D Floor::collideWith(Ball& ball, float collisionTime, int& scorecounter)
{
	if (!collidedLastFrame && (abs(ball.getStatus().py) > 640) && (position < ball.getStatus().px) && ball.getStatus().px < (position + 275))
	{
		collidedLastFrame = true;
		scorecounter = scorecounter + 10;
		return Vector2D{ 0 , ball.getStatus().vy * -2 } / collisionTime;
	}
	else
	{
		collidedLastFrame = false;
		return Vector2D{ 0, 0 };
	}

}
