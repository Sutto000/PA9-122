#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>

class Pacman : public sf::CircleShape
{
public:
	Pacman(float newRadius, const sf::Vector2f& newPos, const sf::Color& newColor, float newSpeed) :
		sf::CircleShape(newRadius)
	{
		this->setRadius(newRadius);
		this->setPosition(newPos);
		this->setFillColor(newColor);
		this->speed = newSpeed;
		this->dead = false;
	}
	void setSpeed(float newSpeed);
	float getSpeed();
	void setDead(bool newDead);
	bool getDead();
private:
	float speed;
	bool dead;
};