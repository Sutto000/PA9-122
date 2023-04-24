#include "Pellet.hpp"

void Pellet::setEaten(bool eaten)
{
	this->isEaten = eaten;
}

bool Pellet::getEaten()
{
	return this->isEaten;
}