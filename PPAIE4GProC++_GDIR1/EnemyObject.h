#ifndef ENEMYOBJECT_H
#define ENEMYOBJECT_H

#include "ParticleModel.h"
#include "Appearance.h"
#include "GameObject.h"
//class ParticleModel;
//class Appearance;

class EnemyObject:
	public GameObject
{
private:

	int objectMass, objectHeight,objectWidth;
	float netForce;
	bool hasBeenFired;
public:
	ParticleModel* object;
	Appearance* appearance;

public:
	EnemyObject(int mass, int height, int width, bool affectedByGravity);
		~EnemyObject();
		void Update(float timeStep);
		void setSize(int height, int width);
		void setMass(int mass);
		int getMass();
		void setNetForce(int force);
		int getNetForce();
		bool collidesWith(GameObject*  g);
};

#endif ENEMYOBJECT_H

