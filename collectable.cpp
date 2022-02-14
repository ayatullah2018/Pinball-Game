#include"collectable.h"
#include<iostream>
using namespace std;
collectable::collectable(int x, int y, int choice)
{
	this->x = x;
	this->y = y;
	this->choice = choice;
	collidedLastFrame = false;

}

Vector2D collectable::collideWith(Ball& ball, float collisionTime, int& scorecounter)
{
	if (!collidedLastFrame && abs((x + 15) - ball.getStatus().px) < 15 && abs((y + 15) - ball.getStatus().py) < 15)
	{
		collidedLastFrame = true;
		cout << "ddddddddddddddddddddd" << endl;
		scorecounter = scorecounter + 100;

		return Vector2D{ 0, 0 };  // Should be replaced with the actual collision logic
	}
	return Vector2D{ 0, 0 };
}
void collectable::draw(Interface& interface)
{
	interface.drawcollectables(x, y, choice);
}