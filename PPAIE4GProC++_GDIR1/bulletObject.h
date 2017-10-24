#ifndef BULLETOBJECT_H
#define BULLETOBJECT_H

#include "bulletParticleModel.h"
#include "bulletAppearance.h"
#include "BulletEmitter.h"
#include "GameObject.h"
#include "EnemyObject.h"
//class bulletParticleModel;
//class bulletAppearance;

class bulletObject:
	public GameObject
{
private:

	int objectMass;
	float netForce;
	bool hasBeenFired;
	Point2D emitterPos;
public:
	bulletParticleModel* object;
	bulletAppearance* appearance;
	BulletEmitter* emitter;
public:
	bulletObject(int mass, int height, int width);
		~bulletObject();
		void Update(float timeStep);
		void setMass(int mass);
		int getMass();
		void setNetForce(int force);
		int getNetForce();
		void setFiredState(bool newFiredState);
		bool getFiredState();
		bool collidesWith(EnemyObject* e);
};

#endif BULLETOBJECT_H

