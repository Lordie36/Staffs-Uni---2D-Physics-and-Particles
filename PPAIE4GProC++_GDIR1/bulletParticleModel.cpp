#include "bulletParticleModel.h"


bulletParticleModel::bulletParticleModel(int mass)//GraphicsM * pGraphicsModule)
{
	pos.x = 0;
	pos.y = 0;
	displacement.x = 10;
	displacement.y = 10;
	velocity.x = 0;
	velocity.y = 0;
	acceleration.x = 0;
	acceleration.y = 0;
	netForce.x = 0;
	netForce.y = 0;
	force.x = 0;
	force.y = 0;
	particleMass = mass;
	touchingFloor = false;
	frictionForce = 0;
	vX = 0;
	vY = 0;
	angle=0;
	gravity = 0;
	exploded = false;
	//inAir = false;
}

bulletParticleModel::~bulletParticleModel()
{
}

void bulletParticleModel::update(float timeStep1)
{
	if(pos.y <= 601)
	{
		timeStep = timeStep1;
		updateGravity();
		if(active)
		{
			
			updateInAirMotion();

		}
		updateAccel();

		move();
	}
}

void bulletParticleModel::updateGravity()
{
	if(netForce.y < 4 && active == true)//&& netForce.y < 5)
	{
		gravity += 0.5f;
	}
	if(active == false)
	{
		gravity = 0;
	}
}

void bulletParticleModel::setAcceleration(int x , int y)
{
	acceleration.x = x;
	acceleration.y = y;
}

void bulletParticleModel::setVelocity(int x, int y)
{
	velocity.x = x;
	velocity.y = y;
}

Point2D bulletParticleModel::getVelocity()
{
	return velocity;
}

void bulletParticleModel::setForce(int forceX, int forceY)
{
	netForce.x = forceX;
	netForce.y = forceY;
}
void bulletParticleModel::setPosition(float xPos, float yPos)
{
	pos.x = xPos; pos.y = yPos;
}

Point2D bulletParticleModel::getPosition()
{
	return pos;
}

void bulletParticleModel::setDisplacementX(int x)
{
	displacement.x = x;
}

void bulletParticleModel::setDisplacementY(int y)
{
	displacement.y = y;
}


Point2D bulletParticleModel::getDisplacement()
{
	return displacement;
}

Point2D bulletParticleModel::getNetForce()
{
	return netForce;
}
//void ParticleModel::updateVelocity()
//{
//	velocity.x = displacement.x * timeStep;
//	velocity.y = displacement.y * timeStep;
//}

void bulletParticleModel::updateInAirMotion()
{
	//Add all forces together, Push, friction, gravity
	//updateFriction();
	//netForce.x;// = 0;// + vX ;//- frictionForce + vX;
	netForce.y += gravity;//= 1;// + 1;// + vY

}

void bulletParticleModel::updateFriction()
{
	//Add all forces together, Push, friction, gravity
	if(touchingFloor == true)
	{
		//velocity.x *= 0.95; 
		frictionForce = force.x * 0.55;
	}
}

void bulletParticleModel::updateAccel()
{
		acceleration.x = netForce.x / particleMass;
		acceleration.y = netForce.y / particleMass;
}

void bulletParticleModel::move()
{
	pos.x = (pos.x + velocity.x * timeStep + 0.5 * acceleration.x * timeStep * timeStep);
	pos.y = (pos.y + velocity.y * timeStep + 0.5 * acceleration.y * timeStep * timeStep);

	velocity.x = acceleration.x * timeStep;
	velocity.y = acceleration.y * timeStep;
}

void bulletParticleModel::xCollisionCheck()
{
	if(pos.x >= 640 && active == true)
	{
		pos.x = 640;
		acceleration.x = 0;
		force.x = 0;
		velocity.x = 0;
		exploded = true;
	}
	else if(pos.x  <= 10 && active == true)
	{
		pos.x = 10;
		acceleration.x = 0;
		force.x = 0;
		velocity.x = 0;
		exploded = true;
	}
}

void bulletParticleModel::yCollisionCheck()
{
	if(pos.y <= 10 && active == true)
	{
		pos.y =  10;
		touchingFloor = false;
		/*acceleration.y = 0;
		force.y = 0;
		velocity.y = 0;*/
		exploded = true;
	}
	else if(pos.y >= 440 && active == true)
	{
		pos.y = 440;
		touchingFloor = true;
		active = false;
		//acceleration.y = 0;
		netForce.y = 0;
		netForce.x = 0;
		exploded = true;
		//velocity.y = 0;
		//Not sure about - probably use to make sure the explosion doesn't carry on
		//vY = 0;
		//vX = 0;
		//velocity.x = 0;
	}
}

void bulletParticleModel::fired(POINT cursorPos, Point2D playerPos)
{
	targetPos = cursorPos;

	angle = atan2((targetPos.y - playerPos.y),(targetPos.x - playerPos.x));
	bulletVector.x = cos(angle);
	bulletVector.y = sin(angle);

	bulletVector.x *= 3;
	bulletVector.y *= 3;

	netForce = bulletVector;
	updateAccel();
	move();
}

void bulletParticleModel::setActive(bool newActive)
{
	active = newActive;
}

bool bulletParticleModel::getActiveState()
{
	return active;
}

void bulletParticleModel::setExploded(bool hasExploded)
{
	exploded = hasExploded;
}

bool bulletParticleModel::getExploded()
{
	return exploded;
}