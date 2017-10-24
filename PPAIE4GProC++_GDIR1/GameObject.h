#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "ParticleModel.h"
#include "Appearance.h"
//class ParticleModel;
//class Appearance;

class GameObject
{
private:

	int objectMass, objectHeight,objectWidth;
	float netForce;
	bool hasBeenFired;
public:
	ParticleModel* object;
	Appearance* appearance;

public:
	GameObject(int mass, int height, int width);
		~GameObject();
		void Update(float timeStep);
		void setSize(int height, int width);
		void setMass(int mass);
		int getMass();
		void setNetForce(int force);
		int getNetForce();
			bool collidesWith(GameObject*  g);
		//bool collidesWith(bulletObject  g);
};

#endif GAMEOBJECT_H

