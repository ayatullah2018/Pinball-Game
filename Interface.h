#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Defs.h"

// Represents the game interface
// This class is the ONLY one that interacts with the user
// This class is also the ONLY one aware of the graphics library being used
// That is, if the graphics library was to be changes, this class is the only thing to be changed
class Interface
{
private:
	sf::RenderWindow window;  // Represents the game window
	const sf::Color  // Colors used for drawing (can change the whole theme of the game)
		backgroundColor = sf::Color::Black,
		outlineColor = sf::Color::Red,
		scoreOutlineColor = sf::Color::White,
		ballFillColor = sf::Color::White,
		kickerFillColor = sf::Color::Blue,
		gateFillColor = sf::Color::Yellow,
		switchFillColor = sf::Color::Red,
		scoreFillColor = sf::Color::Transparent,
		flipperFillColor = sf::Color::White,
		VibraniumbumpersFillColor = sf::Color::Green,
		drawThrustbumpersFillColor= sf::Color::Red,
	    POPpumberFillColor = sf::Color::Magenta;
	

	const float outlineThickness = -2.0f;  // Negative sign means inwards

public:
	Interface();  // Constructor
	void getControls(bool& exit, bool& left, bool& right);  // Detects the buttons pressed

	void clear();  // Clears the frame (first step in rendering a new frame)
	void display();  // Displays the frame (last step in rendering a new frame)

	void drawBall(Vector2D center, float radius);  // Draws a ball
	void drawFlipper(FlipperType type, Vector2D center, float length, float angle, float majorRadius, float minorRadius);  // Draws a flipper
	void drawWall(float position);  // Draws a vertical wall
	void drawkicker(Vector2D vertix1, Vector2D vertix2, Vector2D vertix3);
	void drawpopbumper(float x, float y, float raduis);
	void drawGate(int x, int y, int length, int weidth);
	void drawSwitch(Vector2D vertix1, Vector2D vertix2);
	void drawscore(int scoreCounter);
	void drawVibraniumbumpers(float x, float y, float raduis);
	void drawThrustbumpers(float x, float y, float raduis);
	void drawspecialkicker(Vector2D vertix1, Vector2D vertix2, Vector2D vertix3);
	void drawcollectables(int x, int y, int choice);
	void drawspeedboosters(Vector2D center, float radius);
	void drawGameOver(int scoreCounter);
	void drawCeiling(float position);
	void drawFloor(float position);
	void drawPortals(Vector2D first1, Vector2D second1, float length1, float width1);
	void drawRamp(Vector2D position1, Vector2D position2);
	void drawBullsyes(Vector2D vertix1, Vector2D vertix2);
};

