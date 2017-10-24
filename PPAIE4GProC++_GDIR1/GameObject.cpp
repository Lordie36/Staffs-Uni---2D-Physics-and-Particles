#include "GameObject.h"

GameObject::GameObject(int mass, int height, int width)
{
	objectHeight = height;
	objectWidth = width;
	 object = new ParticleModel(mass, objectHeight,objectWidth, true);
	 appearance = new Appearance(object, objectHeight, objectWidth);
	 objectMass = mass;
	 hasBeenFired = false;
	 object->setActive(true);
}

GameObject::~GameObject()
{

}

void GameObject::Update(float timeStep)
{
	object->update(timeStep);

	object->xCollisionCheck();
	object->yCollisionCheck();
}

void GameObject::setSize(int height, int width)
{
	objectWidth = width;
	objectHeight = height;
}

void GameObject::setMass(int mass)
{
	objectMass = mass;
}

int GameObject::getMass()
{
	return objectMass;
}

void GameObject::setNetForce(int force)
{
	netForce = force;
}

int GameObject::getNetForce()
{
	return netForce;
}

//probably need to sort inheritance out, other wise all collisions should be handled another latyer above.
//bool GameObject::collidesWith(GameObject*  g)
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

//bool GameObject::collidesWith(bulletObject  g)
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
//void GameObject::setFiredState(bool newFiredState)
//{
//	hasBeenFired = newFiredState;
//}
//
//bool GameObject::getFiredState()
//{
//	return hasBeenFired;
//}