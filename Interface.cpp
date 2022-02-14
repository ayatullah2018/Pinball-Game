#include "Interface.h"
#include<iostream>
using namespace std;

Interface::Interface()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;  // Remove this line if the game was too laggy
    window.create(sf::VideoMode(GAME_WIDTH, GAME_HEIGHT), "Pinball", sf::Style::Titlebar, settings);
    window.setVerticalSyncEnabled(true);
}

void Interface::getControls(bool & exit, bool & left, bool & right)
{
    sf::Event event;
    while (window.pollEvent(event));
    exit = sf::Keyboard::isKeyPressed(sf::Keyboard::Escape);
    left = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    right = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
}

void Interface::clear()
{
    window.clear(backgroundColor);
}

void Interface::display()
{
    window.display();
}
void Interface::drawThrustbumpers(float x, float y, float raduis)
{
	sf::CircleShape circle;
	circle.setRadius(raduis);
	circle.setPosition(x, y);
	circle.setFillColor(drawThrustbumpersFillColor);
	circle.setOutlineColor(outlineColor);
	circle.setOutlineThickness(outlineThickness);
	window.draw(circle);
}
void Interface::drawVibraniumbumpers(float x, float y, float raduis)
{
	sf::CircleShape circle;
	circle.setRadius(raduis);
	circle.setPosition(x, y);
	circle.setFillColor(VibraniumbumpersFillColor);
	circle.setOutlineColor(outlineColor);
	circle.setOutlineThickness(outlineThickness);
	window.draw(circle);
}

void Interface::drawGate(int x, int y, int length,int weidth)//position of the gate
{
	sf::RectangleShape Gate(sf::Vector2f(0, weidth));
	Gate.setPosition(sf::Vector2f(x, y));
	Gate.setOutlineColor(outlineColor);
	Gate.setOutlineThickness(outlineThickness);
	Gate.setFillColor(gateFillColor);
	window.draw(Gate);
}
void Interface::drawSwitch(Vector2D vertix1, Vector2D vertix2)//position of the gate
{
	
	sf::Vertex line[] =
	{
			sf::Vertex(sf::Vector2f(vertix1.px, vertix1.py), outlineColor),
			sf::Vertex(sf::Vector2f(vertix2.px, vertix2.py), outlineColor)
	};
	window.draw(line, 2, sf::Lines);
	
}
void Interface::drawspecialkicker(Vector2D vertix1, Vector2D vertix2, Vector2D vertix3)
{
	sf::ConvexShape convex;
	convex.setPointCount(3);
	convex.setPoint(0, sf::Vector2f(vertix1.px, vertix1.py));
	convex.setPoint(1, sf::Vector2f(vertix2.px, vertix2.py));
	convex.setPoint(2, sf::Vector2f(vertix3.px, vertix3.py));
	convex.setFillColor(kickerFillColor);
	convex.setOutlineColor(outlineColor);

	window.draw(convex);
}
void Interface::drawpopbumper(float x, float y, float raduis)
{
	sf::CircleShape circle;
	circle.setRadius(raduis);
	circle.setPosition(x, y);
	circle.setFillColor(POPpumberFillColor);
	circle.setOutlineColor(outlineColor);
	circle.setOutlineThickness(outlineThickness);
	window.draw(circle);
}
void Interface::drawspeedboosters(Vector2D center, float radius)
{
	sf::CircleShape circle;
	circle.setRadius(radius);
	circle.setPosition(center.px, center.py);
	circle.setFillColor(POPpumberFillColor);
	circle.setOutlineColor(outlineColor);
	circle.setOutlineThickness(outlineThickness);
	window.draw(circle);
}
void Interface::drawCeiling(float position)
{
    sf::Vertex line[] =
    {
            sf::Vertex(sf::Vector2f(0, position), outlineColor),
            sf::Vertex(sf::Vector2f(GAME_WIDTH, position), outlineColor)
    };
    window.draw(line, 2, sf::Lines);
}

void Interface::drawFloor(float position)
{
    sf::Vertex line[] =
    {
            sf::Vertex(sf::Vector2f(position, 640), outlineColor),
            sf::Vertex(sf::Vector2f(position+275, 640), outlineColor)
    };
    window.draw(line, 2, sf::Lines);
}
void Interface::drawcollectables(int x, int y, int choice)
{
	sf::CircleShape circle;
	circle.setRadius(15);
	circle.setPosition(x, y);
	circle.setFillColor(sf::Color::Black);
	circle.setOutlineColor(sf::Color::Black);
	circle.setOutlineThickness(outlineThickness);
	window.draw(circle);
	sf::Texture texture1;
	sf::Sprite sprite1;
	switch (choice)
	{
	case 1:

	{
		if (!texture1.loadFromFile("C:/Users/LENOVO-PC/Desktop/project2020/imagespp/E.jpg"))
		{

			cout << "image1 load is failed" << endl;
		}

		sprite1.setTexture(texture1);
		sprite1.setPosition(x,y);
		sprite1.scale(0.1f, 0.1f);
		window.draw(sprite1);
		break;
	}
	case 2:
	{
		if (!texture1.loadFromFile("C:/Users/LENOVO-PC/Desktop/project2020/imagespp/I.jpg"))
		{

			cout << "image2 load is failed" << endl;
		}

		sprite1.setTexture(texture1);
		sprite1.setPosition(x, y);
		sprite1.scale(0.1f, 0.1f);
		window.draw(sprite1);
		break;
	}
	case 3:
	{
		if (!texture1.loadFromFile("C:/Users/LENOVO-PC/Desktop/project2020/imagespp/C.jpg"))
		{

			cout << "image3 load is failed" << endl;
		}
		sprite1.setTexture(texture1);
		sprite1.setPosition(x, y);
		sprite1.scale(0.1f, 0.1f);
		window.draw(sprite1);
		break;
	}
	case 4:
	{

		if (!texture1.loadFromFile("C:/Users/LENOVO-PC/Desktop/project2020/imagespp/22.jpg"))
		{

			cout << "image4 load is failed" << endl;
		}

		sprite1.setTexture(texture1);
		sprite1.setPosition(x,y);
		sprite1.scale(0.1f, 0.1f);
		window.draw(sprite1);
		break;
	}
	case 5:
	{
		if (!texture1.loadFromFile("C:/Users/LENOVO-PC/Desktop/project2020/imagespp/cd.jpg"))
		{

			cout << "image6 load is failed" << endl;
		}
		sprite1.setTexture(texture1);
		sprite1.setPosition(x, y);
		sprite1.scale(0.2f, 0.2f);
		window.draw(sprite1);
		break;
	}
	}
}
void Interface::drawGameOver(int scoreCounter)
{
	sf::Text text;

	sf::Font font;
	if (!font.loadFromFile("C:/Users/LENOVO-PC/Desktop/project2020/arial.ttf"))
	{

	}
	// select the font
	text.setFont(font); // font is a sf::Font

	// set the string to display
	text.setString("Game Over");
	sf::Text text2;
	sf::Font font1;
	if (!font1.loadFromFile("C:/Users/LENOVO-PC/Desktop/project2020/arial.ttf"))
	{
		cout << "error loading file" << endl;
		system("pause");
	}
	text2.setFont(font1);
	string scoreCounterText = to_string(scoreCounter);
	// set the character size
	text.setCharacterSize(40); // in pixels, not points!

	// set the color
	text.setFillColor(sf::Color::Red);

	// set the text style
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);

	text.setPosition((GAME_WIDTH / 2) - 100, (GAME_HEIGHT / 2) - 50);


	// inside the main loop, between window.clear() and window.display()
	window.draw(text);
	text2.setString(scoreCounterText);
	text2.setStyle(sf::Text::Italic);
	text2.setPosition(300,400);
	window.draw(text2);
}

void Interface::drawscore(int scoreCounter)
{
	
	string scoreCounterText = to_string(scoreCounter);
	sf::RectangleShape rectangle(sf::Vector2f(200, 100));
	rectangle.setPosition(sf::Vector2f(500, 5));
	rectangle.setFillColor(scoreFillColor);
	rectangle.setOutlineThickness(outlineThickness);
	rectangle.setOutlineColor(scoreOutlineColor);
	window.draw(rectangle);

	sf::Font font1;
	if (!font1.loadFromFile("C:/Users/LENOVO-PC/Desktop/project2020/arial.ttf"))
	{
		cout << "error loading file" << endl;
		system("pause");
	}
	sf::Text text1;
	sf::Text text2;
	text1.setFont(font1);
	text2.setFont(font1);
	text1.setString("live score:");
	text1.setStyle(sf::Text::Italic);
	text1.setPosition(510,5); 
	window.draw(text1);
	text2.setString(scoreCounterText);
	text2.setStyle(sf::Text::Italic);
	text2.setPosition(550, 50);
	window.draw(text2);
}
void Interface::drawBall(Vector2D stat, float radius)
{
    sf::CircleShape circle(radius);
    circle.setOrigin(radius, radius);
    circle.setOutlineThickness(outlineThickness);
    circle.setOutlineColor(outlineColor);
    circle.setFillColor(ballFillColor);
    circle.setPosition(stat.px, stat.py);
    window.draw(circle);
}
void Interface::drawkicker(Vector2D vertix1, Vector2D vertix2, Vector2D vertix3)
{
	sf::ConvexShape convex;
	convex.setPointCount(3);
	convex.setPoint(0, sf::Vector2f(vertix1.px, vertix1.py));
	convex.setPoint(1, sf::Vector2f(vertix2.px, vertix2.py));
	convex.setPoint(2, sf::Vector2f(vertix3.px, vertix3.py));
	convex.setFillColor(kickerFillColor);
	convex.setOutlineColor(outlineColor);

	window.draw(convex);
}
void Interface::drawBullsyes(Vector2D vertix1, Vector2D vertix2)
{
	sf::Vertex line[] =
	{
			sf::Vertex(sf::Vector2f(vertix1.px, vertix1.py), outlineColor),
			sf::Vertex(sf::Vector2f(vertix2.px, vertix2.py), outlineColor)
	};
	window.draw(line, 2, sf::Lines);
}

void Interface::drawFlipper(FlipperType type, Vector2D center, float length, float angle, float majorRadius, float minorRadius)
{
    float flip = type == LEFT ? 1.0f : -1.0f;

    // Draw the major circle outline
    sf::CircleShape majorCircleOutline(majorRadius);
    majorCircleOutline.setOutlineThickness(outlineThickness);
    majorCircleOutline.setOutlineColor(outlineColor);
    majorCircleOutline.setFillColor(flipperFillColor);
    majorCircleOutline.setOrigin(majorRadius, majorRadius);
    majorCircleOutline.setPosition(center.px, center.py);
    window.draw(majorCircleOutline);

    // Draw the minor circle outline
    sf::CircleShape minorCircleOutline(minorRadius);
    minorCircleOutline.setOutlineThickness(outlineThickness);
    minorCircleOutline.setOutlineColor(outlineColor);
    minorCircleOutline.setFillColor(flipperFillColor);
    minorCircleOutline.setOrigin(minorRadius - length, minorRadius);
    minorCircleOutline.setPosition(center.px, center.py);
    minorCircleOutline.rotate(angle);
    minorCircleOutline.setScale(flip, 1.0f);
    window.draw(minorCircleOutline);

    // Draw the convex shape connecting the two circles
    sf::ConvexShape convexBody(4);
    convexBody.setPoint(0, sf::Vector2f(0, -outlineThickness));
    convexBody.setPoint(1, sf::Vector2f(0, 2 * majorRadius + outlineThickness));
    convexBody.setPoint(2, sf::Vector2f(length, majorRadius + minorRadius + outlineThickness));
    convexBody.setPoint(3, sf::Vector2f(length, majorRadius - minorRadius - outlineThickness));
    convexBody.setFillColor(flipperFillColor);
    convexBody.setOrigin(0, majorRadius);
    convexBody.setPosition(center.px, center.py);
    convexBody.setRotation(angle);
    convexBody.setScale(flip, 1.0f);
    window.draw(convexBody);

    // Draw the inside circle
    sf::CircleShape insideCircle(minorRadius);
    insideCircle.setFillColor(outlineColor);
    insideCircle.setOrigin(minorRadius, minorRadius);
    insideCircle.setPosition(center.px, center.py);
    window.draw(insideCircle);

    // Draw the top line
    sf::ConvexShape topLine(4);
    topLine.setPoint(0, sf::Vector2f(0, -outlineThickness));
    topLine.setPoint(1, sf::Vector2f(0, 0));
    topLine.setPoint(2, sf::Vector2f(length, majorRadius - minorRadius));
    topLine.setPoint(3, sf::Vector2f(length, majorRadius - minorRadius - outlineThickness));
    topLine.setFillColor(outlineColor);
    topLine.setOrigin(0, majorRadius);
    topLine.setPosition(center.px, center.py);
    topLine.setRotation(angle);
    topLine.setScale(flip, 1.0f);
    window.draw(topLine);

    // Draw the bottom line
    sf::ConvexShape bottomLine(4);
    bottomLine.setPoint(0, sf::Vector2f(0, 2 * majorRadius));
    bottomLine.setPoint(1, sf::Vector2f(0, 2 * majorRadius + outlineThickness));
    bottomLine.setPoint(2, sf::Vector2f(length, majorRadius + minorRadius + outlineThickness));
    bottomLine.setPoint(3, sf::Vector2f(length, majorRadius + minorRadius));
    bottomLine.setFillColor(outlineColor);
    bottomLine.setOrigin(0, majorRadius);
    bottomLine.setPosition(center.px, center.py);
    bottomLine.setRotation(angle);
    bottomLine.setScale(flip, 1.0f);
    window.draw(bottomLine);
}

void Interface::drawWall(float position)
{
    sf::Vertex line[] =
            {
                    sf::Vertex(sf::Vector2f(position, 0), outlineColor),
                    sf::Vertex(sf::Vector2f(position, GAME_HEIGHT), outlineColor)
            };
    window.draw(line, 2, sf::Lines);
}

void Interface::drawPortals(Vector2D first, Vector2D second, float length, float width)
{
	sf::RectangleShape rectangle(sf::Vector2f(length, width));
	rectangle.setPosition(sf::Vector2f(first.px, first.py));
	rectangle.setFillColor(gateFillColor);
	rectangle.setOutlineThickness(outlineThickness);
	rectangle.setOutlineColor(outlineColor);
	window.draw(rectangle);


	sf::RectangleShape rectangl(sf::Vector2f(length, width));
	rectangl.setPosition(sf::Vector2f(second.px, second.py));
	rectangl.setFillColor(gateFillColor);
	rectangl.setOutlineThickness(outlineThickness);
	rectangl.setOutlineColor(outlineColor);
	window.draw(rectangl);
}
void Interface::drawRamp(Vector2D position1, Vector2D position2)
{
	sf::Vertex line[] =
	{
			sf::Vertex(sf::Vector2f(position1.px, position1.py), outlineColor),
			sf::Vertex(sf::Vector2f(position2.px, position2.py), outlineColor)
	};
	window.draw(line, 2, sf::Lines);
}
