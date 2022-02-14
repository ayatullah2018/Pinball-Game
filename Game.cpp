
#include "Game.h"
#include<iostream>

#define GRAVITY 400.0f

Game::Game(): leftFlipper(LEFT, Vector2D { 0, 0, GAME_WIDTH / 2.0f - (FLIPPER_LENGTH + FLIPPERS_DISTANCE / 2.0f), GAME_HEIGHT - 50.0f}, FLIPPER_LENGTH, 30.0f, FLIPPER_MAJOR_RADIUS, FLIPPER_MINOR_RADIUS),
              rightFlipper(RIGHT, Vector2D { 0, 0, GAME_WIDTH / 2.0f + (FLIPPER_LENGTH + FLIPPERS_DISTANCE / 2.0f), GAME_HEIGHT - 50.0f}, FLIPPER_LENGTH, -30.0f, FLIPPER_MAJOR_RADIUS, FLIPPER_MINOR_RADIUS)


{
	scoreCounter = 0;
	file.open("C:/Users/LENOVO-PC/Desktop/this is the project/wow_finalc++project/Pinball/input.txt");
	if(!file)
	{
		cout << "Unable to open file!";
	}
	
	string strin;
	Vector2D stat;
	file >> stat.px;
	file >> stat.py;
	file >> stat.vx;
	file >> stat.vy;

	file >> obstacles_size;
	pObs = NULL;
	pObs = new Obstacle * [obstacles_size];
		
	ball = new Ball(stat);

	for (int i = 0; i < obstacles_size; i++)
	{
		file >> strin;
		if (strin == "Wall")
		{
			float x;
			file >> x;
			pObs[i] = new Wall(x);
		}
		else if (strin == "Ceiling")
		{
			float y;
			file >> y;
			pObs[i] = new Ceiling(y);
		}
		else if (strin == "Floor")
		{
			float y;
			file >> y;
			pObs[i] = new Floor(y);
		}
		else if (strin == "PopBumper")
		{
			float x, y, radius;
			file >> x;
			file >> y;
			file >> radius;
			pObs[i] = new popbumper(x, y, radius);
		}
		else if (strin == "Bullsyes")
		{
			Vector2D vertix1;
			Vector2D vertix2;

			file >> vertix1.px;
			file >> vertix1.py;
			file >> vertix2.px;
			file >> vertix2.py;

			pObs[i] = new Bullsyes(vertix1, vertix2);
		}
		else if (strin == "Kicker")
		{
			Vector2D vertix1;
			Vector2D vertix2;
			Vector2D vertix3;
			file >> vertix1.px;
			file >> vertix1.py;
			file >> vertix2.px;
			file >> vertix2.py;
			file >> vertix3.px;
			file >> vertix3.py;
			pObs[i] = new kicker(vertix1, vertix2, vertix3);
		}
		else if (strin == "Gate")
		{
			float x, y, length, width;
			file >> x;
			file >> y;
			file >> length;
			file >> width;
			pObs[i] = new Gate(x, y, length, width);
		}
		else if (strin == "Switch")
		{
			Vector2D vertix1;
			Vector2D vertix2;
			file >> vertix1.px;
			file >> vertix1.py;
			file >> vertix2.px;
			file >> vertix2.py;
			pObs[i] = new Switch(vertix1,vertix2);
		}
		else if (strin == "VibraniumBumper")
		{
			float x, y, radius;
			file >> x;
			file >> y;
			file >> radius;
			pObs[i] = new Vibraniumbumpers(x, y, radius);
		}
		else if (strin == "ThrustBumpers")
		{
			float x, y, radius;
			file >> x;
			file >> y;
			file >> radius;
			pObs[i] = new Thrustbumpers(x, y, radius);
		}
		else if (strin == "SpecialKicker")
		{
			Vector2D vertix1;
			Vector2D vertix2;
			Vector2D vertix3;
			file >> vertix1.px;
			file >> vertix1.py;
			file >> vertix2.px;
			file >> vertix2.py;
			file >> vertix3.px;
			file >> vertix3.py;
			pObs[i] = new specialkicker(vertix1, vertix2, vertix3);
		}
		else if (strin == "Collectables")
		{
			float x, y, choice;
			file >> x;
			file >> y;
			file >> choice;
			pObs[i] = new collectable(x, y, choice);
		}
		else if (strin == "SpeedBoosters")
		{
			float radius;
			Vector2D center;
			file >> center.px;
			file >> center.py;
			file >> radius;
			pObs[i] = new peedbooster(center, radius);
		}
		else if (strin == "Portals")
		{
			Vector2D first;
			file >> first.px;
			file >> first.py;
			Vector2D second;
			file >> second.px;
			file >> second.py;
			float length;
			float width;
			file >> length;
			file >> width;
			pObs[i] = new Portals(first, second, length, width);
		}
		else if (strin == "Ramp")
		{
		Vector2D first, second;
		file >> first.px;
		file >> first.py;
		file >> second.px;
		file >> second.py;
		pObs[i] = new Ramp(first, second);
		}
	}
	
    lastFrame = high_resolution_clock::now();
    exit = left = right = false;
}

void Game::readInterfaceInput()
{
    interface.getControls(exit, left, right);
	leftFlipper.setangleleft(left);
	rightFlipper.setangleright(right);
}

void Game::simulate()
{
	gameoverDetector = ball->getStatus().py;
	if (gameoverDetector > 640 || over == 1)
	{
		over = true;
	}
	else
	{
		// Measuring time elapsed in-between frames
		high_resolution_clock::time_point thisFrame = high_resolution_clock::now();
		duration<float> timeSpan = duration_cast<duration<float>>(thisFrame - lastFrame);
		lastFrame = thisFrame;
		float deltaTime = timeSpan.count();  // Delta time in seconds

		Vector2D resultantAcceleration = { 0, GRAVITY };  // Starting with gravity as the first acceleration contributer

		for (int i = 0; i < obstacles_size; i++)
		{
			resultantAcceleration += pObs[i]->collideWith(*ball, deltaTime, scoreCounter);
		}


		ball->move(resultantAcceleration, deltaTime);

	}
}

void Game::updateInterfaceOutput()
{
	
	interface.clear();
	if (over)
	{

		interface.clear();
		interface.drawGameOver(scoreCounter);

	}
	else
	{
		for (int i = 0; i < obstacles_size; i++)
		{
			pObs[i]->draw(interface);
		}
		interface.drawscore(scoreCounter);
		leftFlipper.draw(interface);
		rightFlipper.draw(interface);

		ball->draw(interface);

		if (ball->getStatus().py > 675)
		{
			interface.clear();
			interface.drawGameOver(scoreCounter);
		}
	}
    interface.display();

}

bool Game::exited()
{
    return exit;
}
