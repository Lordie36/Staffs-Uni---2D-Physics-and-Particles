#include "BulletEmitter.h"

BulletEmitter::BulletEmitter()
{
	// spawn at current position
	pos.x = 0;
	pos.y = 0;
	explosionTimer = 0;
	initialParticleForce.x = 5;
	initialParticleForce.y = 5;
	explodedState = false;
	spawningRate = 1;
	spawnTimer = 0;
	particleLifetime = 2;
	offScreenPos.x = 600;
	offScreenPos.y = 600;
	noForce.x = 0;
	noForce.y = 0;

	for ( int i = 0; i < 15; i++)
	{
		particles[i] = new Particle();
	}
}
BulletEmitter::~BulletEmitter()
{

}
void BulletEmitter::update(Point2D currentForce, Point2D newPos)
{
	if(pos.y >= 450 && pos.y < 500)
	{
		explodedState = true;
	}
	//explodedState = exploded;
	//update- call all functions
	if(explodedState == false)
	{
		//keeps updating the pos, until it explodes
		pos.x = newPos.x;
		pos.y = newPos.y;
	}
	else if(explodedState == true)
	{
		explosionTimer ++;
		if(explosionTimer >= 10)
		{
			pos = offScreenPos;
			explodedState = false;
			explosionTimer = 0;
		}
	}
	

	for (int i = 0; i < 15; i++)
	{
		particles[i]->update();
		//delay
		if(/*spawnTimer >= spawningRate &&*/ particles[i]->getFirst() == true) 
		{
		//spawn -set active
			particles[i]->setFirst(false);
			particles[i]->setActive(true);
			particles[i]->setPosition(pos);
			particles[i]->setForce(initialParticleForce);
			//spawnTimer = 0;
		}

		if(particles[i]->getActive() == false)
		{
			particles[i]->setPosition(offScreenPos);
			particles[i]->setForce(noForce);
		}

		if(particles[i]->getActive() == true)
		{
			if(pos.y > 500)
			{
				particles[i]->setForce(noForce);
			}
		//if lifetime is up - active false- setpos
			if(particles[i]->getLifeTime() >= particleLifetime)
			{
				particles[i]->setFirst(true);
				particles[i]->setActive(false);
				particles[i]->setPosition(offScreenPos);
				particles[i]->setForce(noForce);
			}

	}
			//spawnTimer = 0;
		randomiseNextLifetime();
	randomiseNextVector(currentForce);
	}

	spawnTimer++;
}

void BulletEmitter::randomiseNextVector(Point2D currentForce)
{
	//randomise both x and y values of a point2D
	//if the bullet has not exploded, it is stull flying, - all vectors will have a negative of the current force
	if(explodedState == true)
	{
		initialParticleForce.x = 30 - rand() % 60;
		initialParticleForce.y = 10 - rand() % 60;
	}
	else if(explodedState == false)
	{
		initialParticleForce.x = (-currentForce.x) + 5 -(rand() % 10);
		initialParticleForce.y = (-currentForce.y) + 5 -(rand() % 10);
	}
}
void BulletEmitter::randomiseNextLifetime()
{
	// if exploded randomise an int between 20- 50 frames
	//else 10 - 30 frames
	if(explodedState == true)
	{
		particleLifetime = rand() % 50;
	}
	else if(explodedState == false)
	{
		particleLifetime = rand() % 20;
	}
}