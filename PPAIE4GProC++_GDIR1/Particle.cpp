#include "Particle.h"

Particle::Particle()
{
	pos.x = 0;
	pos.y = 0;
	initialForce.x = 0;
	initialForce.y = 0;
	active = false;
	first = true;
}

Particle::~Particle()
{

}

void Particle::setFirst(bool setFirst)
{
	first = setFirst;
}

bool Particle::getFirst()
{
	return first;
}

void Particle::setPosition(Point2D newPos)
{
	pos = newPos;
}

void Particle::setForce(Point2D newForce)
{
	initialForce = newForce;
}

void Particle::setActive(bool newActiveState)
{
	active = newActiveState;
}

bool Particle::getActive()
{
	return active;
}

int Particle::getLifeTime()
{
	return lifeTime;
}

void Particle::update()
{
	if(active == true)
	{
		pos.x += initialForce.x;
		pos.y += initialForce.y;
		lifeTime++;
	}
	else if(active == false)
	{
		pos.x = 0;
		pos.y = 0;
		lifeTime = 0;
	}
}

void Particle::setShape2Square()
{
	/* Load polygon (shape) data into vertex array */
	shape[0].x = 0.0F;	shape[0].y = 0.0F;
	shape[1].x = 5.0f;	shape[1].y = 0.0F;
	shape[2].x = 5.0f;	shape[2].y = 5.0f;
	shape[3].x = 0.0F;	shape[3].y = 5.0f;
}

void Particle::dispBufUpdate()
{
	// update displa object (content of display buffer (with calculated vertex coordinates of square at its current position))
	for (int vert = 0; vert < 4; ++vert)
    {
		dispBuffObj[vert].x = shape[vert].x + pos.x;
		dispBuffObj[vert].y = shape[vert].y + pos.y;
    }
}