#include "ParticleModel.h"


ParticleModel::ParticleModel(int mass, int objectHeight, int objectWidth, bool affectedByGravity)//GraphicsM * pGraphicsModule)
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
	height = objectHeight;
	width = objectWidth;
	gravity = 0;
	forceMag = 0;
	sForce.x = 0;
	sForce.y = 0;
	theta = 0;
	frCoef = 0;
	jumping = false;
	isAffectedByGravity = affectedByGravity;
}

ParticleModel::~ParticleModel()
{
}


void ParticleModel::update(keyEvent kEvent,float timeStep1)
{
	timeStep = timeStep1;

	updateState();
	//updateNetForce();

	//updateAccel();

	//move();
}

void ParticleModel::update(float timeStep1)
{
	timeStep = timeStep1;

	updateState();
}

void ParticleModel::updateState()
{
	prevPos = pos;
	updateNetForce();

	updateAccel();

	move();
}

void ParticleModel::setPosition(float xPos, float yPos)
{
	pos.x = xPos; pos.y = yPos;
}

Point2D ParticleModel::getPos()
{
	return pos;
}

Point2D ParticleModel::getPrevPos()
{
	return prevPos;
}

void ParticleModel::setDisplacement(int x, int y)
{
	displacement.x = x;
	displacement.y = y;
}

void ParticleModel::setDisplacementX(int x)
{
	displacement.x = x;
}

void ParticleModel::setDisplacementY(int y)
{
	displacement.y = y;
}


Point2D ParticleModel::getDisplacement()
{
	return displacement;
}

//void ParticleModel::updateVelocity()
//{
//	velocity.x = displacement.x * timeStep;// + vX;
//	velocity.y = displacement.y * timeStep;// + vY;
//}
void ParticleModel::setForce(Point2D newForce)
{
	force = newForce;
}

void ParticleModel::setVelocity()
{

}

void ParticleModel::setAcceleration(Point2D newVelocity)
{

}

void ParticleModel::updateNetForce()
{
	//Add all forces together, Push, friction, gravity
	slidingForce(theta,frCoef);
	updateFriction();
	updateGravity();
	netForce.x = force.x - frictionForce + sForce.x;// + vX;// + frictionForce;
	netForce.y = force.y  + gravity + sForce.y;//+ vY + 1;// + 0.25;
	
}

void ParticleModel::updateGravity()
{
	if(netForce.y < 10 && jumping == false && isAffectedByGravity == true)//&& netForce.y < 5)
	{
		gravity += 0.5;
	}

	if(isAffectedByGravity == false)
	{
		gravity = 0;
	}
}

void ParticleModel::updateFriction()
{
	//Add all forces together, Push, friction, gravity
	if(touchingFloor == true)
	{
		//velocity.x *= 0.95; 
		frictionForce = force.x * 0.55;
	}
}

void ParticleModel::updateAccel()
{
		acceleration.x = netForce.x / particleMass;
		acceleration.y = netForce.y / particleMass;
}

void ParticleModel::move()
{
	pos.x = (pos.x + velocity.x * timeStep + 0.5 * acceleration.x * timeStep * timeStep);
	pos.y = (pos.y + velocity.y * timeStep + 0.5 * acceleration.y * timeStep * timeStep);

	velocity.x = acceleration.x * timeStep;
	velocity.y = acceleration.y * timeStep;
}

void ParticleModel::moveRight()//float timeStep)
{
	force.x = 5;
}

void ParticleModel::moveLeft()//float timeStep)
{
	force.x = -5;
}

void ParticleModel::moveUp()//----------------------insert time ++ here if i cant swap the case select
{
	force.y = -2;
	jumping = true;
	gravity = 0;
}

void ParticleModel::noInput()
{
	force.x = 0;
	force.y = 0;
	jumping = false;
}


void ParticleModel::xCollisionCheck()
{
	if(pos.x >= 650 - width && active == true)
	{
		pos.x = 650 - width;
		acceleration.x = 0;
		force.x = 0;
		velocity.x = 0;
	}
	else if(pos.x  <= 10 && active == true)
	{
		pos.x = 10;
		acceleration.x = 0;
		force.x = 0;
		velocity.x = 0;
	}
}

void ParticleModel::yCollisionCheck()
{
	if(pos.y <= 10 && active == true)
	{
		pos.y = 10;
		touchingFloor = false;
		/*acceleration.y = 0;
		force.y = 0;
		velocity.y = 0;*/
	}
	else if(pos.y >= 450 - height && active == true)
	{
		pos.y = 450 - height;
		touchingFloor = true;
		acceleration.y = 0;
		force.y = 0;
		velocity.y = 0;
	}
}

void ParticleModel::setActive(bool newActive)
{
	active = newActive;
}

bool ParticleModel::getActiveState()
{
	return active;
}

/* Motion for object sliding down an inclined plane */
void ParticleModel::slidingMotion() { 
	// calculate net sliding force
	slidingForce(theta, frCoef);

	// calculate acceleration resulting from net external force  
	// use calculated acceleration to update position and velocity of object 
	updateState(); // Same as in Exercise 2.1
	move ();	      // Same as in Exercise 2.1
}

/* Compute sliding force acting on object
	theta: angle of inclined plane relative to x-axis
	frCoef: coefficient of friction
 */
void ParticleModel::slidingForce(float theta, float frCoef) {
	// calculate magnitude of force
	forceMag = particleMass * gravity * (sin(theta) - frCoef * cos(theta)); 

	// To do: check to ensure that magnitude is not negative

	// calculate x- and y-components of force
	// (note: x-axis assumed positive rightwards and 
	//	y-axis positive downwards)
	sForce.x = forceMag * cos(theta); 
	sForce.y = forceMag * sin(theta); 
}
