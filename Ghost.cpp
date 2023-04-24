#include "Ghost.hpp"

void Ghost::setSpeed(float newSpeed)
{
	this->speed = newSpeed;
}

void Ghost::setMode(int newMode)
{
	this->mode = newMode;
}

int Ghost::getMode()
{
	return this->mode;
}

float Ghost::getSpeed()
{
	return this->speed;
}