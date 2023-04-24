#pragma once

#include <SFML/Graphics.hpp>

#include "Wall.hpp"
#include "Pellet.hpp"

class Container
{
public:
	std::vector<Wall> makeWalls(float horizRes, float vertRes);
	std::vector<Pellet> makePellets(float horizRes, float vertRes);
private:
};