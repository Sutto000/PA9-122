#pragma once

#include <SFML/Graphics.hpp>

#include <cstdlib>
#include <cmath>

class Ghost : public sf::RectangleShape
{

public:
	Ghost(const sf::Vector2f& newSize, const sf::Vector2f& newPos, const sf::Color& newColor, float newSpeed, int newMode) :
		sf::RectangleShape(newSize)
	{
		this->setSize(newSize);
		this->setPosition(newPos);
		this->setFillColor(newColor);
		this->speed = newSpeed;
		this->mode = newMode;
	}
	void setSpeed(float newSpeed);
	void setMode(int newMode);
	int getMode();
	float getSpeed();


private:
	float speed;
	int mode; // 0 - scatter , 1 - chase , 2 - frightened
};
