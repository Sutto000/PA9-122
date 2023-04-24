#pragma once

#include <SFML/Graphics.hpp>

class Wall : public sf::RectangleShape
{
public:
	Wall(const sf::Vector2f& newSize, const sf::Vector2f& newPos, const sf::Color& newColor) :
		sf::RectangleShape(newSize)
	{
		this->setSize(newSize);
		this->setPosition(newPos);
		this->setFillColor(newColor);
	}
private:
};