#pragma once

#include <chrono>
using namespace std::chrono;
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#include"Bullsyes.h"
#include "Interface.h"
#include "Defs.h"
#include "GameObjects/Ball.h"
#include "GameObjects/Obstacles/Wall.h"
#include "GameObjects/Flipper.h"
#include"Ceiling.h"
#include"Floor.h"
#include"GameObjects/Obstacles/Portals.h"
#include"GameObjects/Obstacles/Ramp.h"
#include"GameObjects/Obstacles/Kicker.h"
#include"GameObjects/Obstacles/Gate.h"
#include"GameObjects/Obstacles/Switch.h"
#include"peedbooster.h"
#include"collectable.h"
#include"GameObjects/Obstacles/poppumber.h"
#include"GameObjects/Obstacles/Vibraniumbumpers.h"
#include"GameObjects/Obstacles/Thrustbumpers.h"
#include"GameObjects/Obstacles/specialkicker.h"
// Represents a game, keeps track of everything relevant to the game and delegates the tasks to their proper objects
class Game
{
private:
	int scoreCounter;
    bool over;
    double gameoverDetector;
    high_resolution_clock::time_point lastFrame;  // Time point of the last rendered frame
    Interface interface;  // An object representing the game interface
    bool exit, left, right;  // Flags about the user's current controls

    Ball *ball;  // The ball (obviously :D)
    Flipper leftFlipper, rightFlipper;  // The right and left flippers
	int obstacles_size = 1;
	ifstream file;
	Obstacle** pObs;
//  Wall leftWall, rightWall;  // This line should be replaced by an array of obstacles
//	kicker leftKicker, rightKicker;
//	peedbooster firepeedbooster;
//	collectable collectable1, collectable2, collectable3, collectable4, collectable6 , collectable5;
//	Gate firstGate, secondGate, thirdGate;
//	Switch firstSwitch, secondSwitch;
	//popbumper popbumper1;
//	Thrustbumpers Thrustbumpersint1;
//	Vibraniumbumpers Vibraniumbumpers1;
//	specialkicker specialkicker1;
public:
    Game();
    void readInterfaceInput();
    void simulate();
    void updateInterfaceOutput();
    bool exited();
};
