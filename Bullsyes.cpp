#include"Bullsyes.h"
#include<iostream>
using namespace std;
Bullsyes::Bullsyes(Vector2D vertix1, Vector2D vertix2)
{
	this->vertix1 = vertix1;
	this->vertix2 = vertix2;
	cout << vertix1.px << " " << vertix1.py << endl;
	cout << vertix2.px << " " << vertix2.py << endl;

}
Vector2D Bullsyes::collideWith(Ball& ball, float collisionTime, int& scorecounter)
{

	if (!collidedLastFrame && abs((vertix1.px - ball.getStatus().px) < ball.getRadius()) && (ball.getStatus().py <= vertix1.py) && (ball.getStatus().py >= vertix2.py))
	{
		collidedLastFrame = true;
		float middlepoint = (vertix1.py - vertix2.py) / 2;


		if ((ball.getStatus().py < abs(middlepoint) + 10) && (ball.getStatus().py > abs(middlepoint) - 10))
		{
			cout << abs(middlepoint) << endl;
			cout << ball.getStatus().py << endl;
			cout << "centreeeeeeee" << endl;
			scorecounter = scorecounter *4;
			//put here the virtual function of resultantlive score
		}
		else
		{
			cout << "noooot centreeeeeeee" << endl;
			scorecounter = scorecounter *2;
			//put here the virtual function of resultantlive score
		}

		return Vector2D{ ball.getStatus().vx * -2 ,ball.getStatus().vy * -2 } / collisionTime;
	}
	else
	{
		collidedLastFrame = false;
		return { 0,0,0,0 };
	}


}

void Bullsyes::draw(Interface& interface)
{
	interface.drawBullsyes(vertix1, vertix2);
}
