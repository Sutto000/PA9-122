#include "Pacman.hpp"

void Pacman::setSpeed(float newSpeed)
{
	this->speed = newSpeed;
}

float Pacman::getSpeed()
{
	return this->speed;
}

void Pacman::setDead(bool newDead)
{
	this->dead = newDead;
}

bool Pacman::getDead()
{
	return this->dead;
}