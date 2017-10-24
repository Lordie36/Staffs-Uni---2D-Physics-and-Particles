#include "EnemyObject.h"
//#include "GameObject.h"

EnemyObject::EnemyObject(int mass, int height, int width,bool affectedByGravity)
	:GameObject(mass,height,width)
{
	objectHeight = height;
	objectWidth = width;
	 object = new ParticleModel(mass, objectHeight,objectWidth, affectedByGravity);
	 appearance = new Appearance(object, objectHeight, objectWidth);
	 objectMass = mass;
	 hasBeenFired = false;
	 object->setActive(true);
}

EnemyObject::~EnemyObject()
{

}

void EnemyObject::Update(float timeStep)
{
	object->update(timeStep);

	object->xCollisionCheck();
	object->yCollisionCheck();
}

void EnemyObject::setSize(int height, int width)
{
	objectWidth = width;
	objectHeight = height;
}

void EnemyObject::setMass(int mass)
{
	objectMass = mass;
}

int EnemyObject::getMass()
{
	return objectMass;
}

void EnemyObject::setNetForce(int force)
{
	netForce = force;
}

int EnemyObject::getNetForce()
{
	return netForce;
}

//probably need to sort inheritance out, other wise all collisions should be handled another latyer above.
//bool EnemyObject::collidesWith(EnemyObject*  g)
//{
//	//if((g.object->getPos().x + 10 > object->getPos().x) && (g.object->getPos().x < object->getPos().x +10)
//	//	&& (g.object->getPos().y < object->getPos().y + 10) && (g.object->getPos().y + 10 > object->getPos().y))
//	//	return true;
//	//else return false;
//	
//	//-----Re-create code, no inheritance, so this doesnt mess up!
//	if(object->getPos().x <= g->object->getPos().x)
//	{
//		return true;
//	}
//
//}

//bool EnemyObject::collidesWith(bulletObject  g)
//{
//	//if((g.object->getPos().x + 10 > object->getPos().x) && (g.object->getPos().x < object->getPos().x +10)
//	//	&& (g.object->getPos().y < object->getPos().y + 10) && (g.object->getPos().y + 10 > object->getPos().y))
//	//	return true;
//	//else return false;
//	
//	if(object->getPos().x <= 200 && object->getActiveState() == true && g.object->getActiveState() == true && g.object->getExploded() == false)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//void EnemyObject::setFiredState(bool newFiredState)
//{
//	hasBeenFired = newFiredState;
//}
//
//bool EnemyObject::getFiredState()
//{
//	return hasBeenFired;
//}