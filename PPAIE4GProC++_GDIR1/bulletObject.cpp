#include "bulletObject.h"

bulletObject::bulletObject(int mass, int height, int width):GameObject(mass, height, width)
{
	 object = new bulletParticleModel(mass);
	 appearance = new bulletAppearance(object);
	 emitter = new BulletEmitter();
	 objectMass = mass;
	 hasBeenFired = false;
	 object->setActive(false);

}

bulletObject::~bulletObject()
{

}

void bulletObject::Update(float timeStep)
{
	emitterPos.x = object->getPosition().x + 10;
	emitterPos.y = object->getPosition().y + 10;
	object->update(timeStep);
	object->xCollisionCheck();
	object->yCollisionCheck();
	emitter->update(object->getVelocity(),emitterPos);
}

void bulletObject::setMass(int mass)
{
	objectMass = mass;
}

int bulletObject::getMass()
{
	return objectMass;
}

void bulletObject::setNetForce(int force)
{
	netForce = force;
}

int bulletObject::getNetForce()
{
	return netForce;
}

void bulletObject::setFiredState(bool newFiredState)
{
	hasBeenFired = newFiredState;
}

bool bulletObject::getFiredState()
{
	return hasBeenFired;
}

bool bulletObject::collidesWith(EnemyObject* e)
{
	//X collision
		if(appearance->dispBuffObj[0].x > e->appearance->dispBuffObj[0].x  &&  appearance->dispBuffObj[0].x  <= e->appearance->dispBuffObj[1].x)// || appearance->dispBuffObj[1].x > e->appearance->dispBuffObj[0].x  &&  appearance->dispBuffObj[1].x  <= e->appearance->dispBuffObj[1].x)
		{
			if(appearance->dispBuffObj[0].y > e->appearance->dispBuffObj[0].y  &&  appearance->dispBuffObj[0].y  <= e->appearance->dispBuffObj[3].y)// || appearance->dispBuffObj[3].y > e->appearance->dispBuffObj[0].y  &&  appearance->dispBuffObj[3].y  <= e->appearance->dispBuffObj[3].y)
			{
				return true;
			}
		}
}