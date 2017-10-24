#ifndef PLAYEROBJECT_H
#define PLAYEROBJECT_H

#include "ParticleModel.h"
#include "Appearance.h"
#include "GameObject.h"
#include "EnemyObject.h"
//class ParticleModel;
//class Appearance;

class PlayerObject
	: public GameObject
{
private:
	int objectMass,timeBetweenJumps;
	float netForce;
public:
	ParticleModel* player;
	Appearance* appearance;

public:
	PlayerObject(int mass, int height, int width);
		~PlayerObject();
		void Update(keyEvent kEvent,float timeStep);
		bool collidesWith(EnemyObject* e);
		//void setMass(int mass);
		//int getMass();
		//void setNetForce(int force);
		//int getNetForce();
};

#endif PLAYEROBJECT_H

