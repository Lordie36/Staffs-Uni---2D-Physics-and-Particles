#include "PlayerObject.h"

PlayerObject::PlayerObject(int mass, int height, int width):GameObject(mass, height, width)
{
	 player = new ParticleModel(mass, height, width, true);
	 appearance = new Appearance(player, height, width);
	 objectMass = mass;
	 player->setActive(true);
	 timeBetweenJumps = 0;
}

PlayerObject::~PlayerObject()
{

}

void PlayerObject::Update(keyEvent kEvent,float timeStep)
{
	timeBetweenJumps ++;
	switch(kEvent)
		{
		case RIGHT:
			player->moveRight();
			break;
		case LEFT:
            player->moveLeft();
			break;
		case UP:
			player->moveUp();	
			break;
		default:
			player->noInput();
			break;
	}
	player->update(kEvent,timeStep);

	player->xCollisionCheck();
	player->yCollisionCheck();
}

bool PlayerObject::collidesWith(EnemyObject* e)
{
	//X collision
		if(appearance->dispBuffObj[0].x > e->appearance->dispBuffObj[0].x  &&  appearance->dispBuffObj[0].x  <= e->appearance->dispBuffObj[1].x || appearance->dispBuffObj[1].x > e->appearance->dispBuffObj[0].x  &&  appearance->dispBuffObj[1].x  <= e->appearance->dispBuffObj[1].x)
		{
			//if(g->appearance->dispBuffObj[2].y <= appearance->dispBuffObj[0].y  &&   g->appearance->dispBuffObj[2].y >= appearance->dispBuffObj[2].y)
			//{
			if(appearance->dispBuffObj[0].y > e->appearance->dispBuffObj[0].y  &&  appearance->dispBuffObj[0].y  <= e->appearance->dispBuffObj[3].y || appearance->dispBuffObj[3].y > e->appearance->dispBuffObj[0].y  &&  appearance->dispBuffObj[3].y  <= e->appearance->dispBuffObj[3].y)
			{
				return true;
			}
		}
}
//void GameObject::setMass(int mass)
//{
//	objectMass = mass;
//}
//
//int GameObject::getMass()
//{
//	return objectMass;
//}
//
//void GameObject::setNetForce(int force)
//{
//	netForce = force;
//}
//
//int GameObject::getNetForce()
//{
//	return netForce;
//}