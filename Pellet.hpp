#pragma once

#include <SFML/Graphics.hpp>

class Pellet : public sf::CircleShape
{
public:
	Pellet(float newRadius, const sf::Vector2f& newPos, const sf::Color& newColor) :
		sf::CircleShape(newRadius)
	{
		this->setRadius(newRadius);
		this->setPosition(newPos);
		this->setFillColor(newColor);
		this->isEaten = false;
	}
	void setEaten(bool eaten);
	bool getEaten();
private:
	bool isEaten;
};
