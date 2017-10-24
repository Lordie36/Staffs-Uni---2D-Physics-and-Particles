#ifndef _ParticleModel_H
#define _ParticleModel_H

#include    <Windows.h>
#include	"input.h"
#include	"dataTypes.h"
#include	"graphics.h"
#include	<math.h>
	
class ParticleModel
{
private:
	Point2D 	pos, velocity, displacement, force, netForce, acceleration, sForce, prevPos;
	float		timeStep, theta, frCoef, gravity;
	int			particleMass, frictionForce, height, width, forceMag;
	bool		touchingFloor,active, jumping , isAffectedByGravity;

public:
	ParticleModel(int mass, int objectHeight, int objectWidth, bool affectedByGravity);
	~ParticleModel();
	void update(keyEvent kEvent, float timeStep1);
	void update(float timeStep);
	void updateState();
	void updateGravity();
	void setVelocity();
	Point2D getVelocity();
	void setForce(Point2D newForce);
	void setAcceleration(Point2D newAcceleration);
	void setDisplacement(int x, int y);
	Point2D getDisplacement();
	Point2D getPrevPos();
	void setDisplacementX(int x);
	void setDisplacementY(int y);

	void moveConstDisp(int direction);
	void moveConstDisp();

	void xCollisionCheck();
	void yCollisionCheck();

	void updateNetForce();
	void updateFriction();

	void updateVelocity();
	void moveConstVel();
	void setPosition(float xPos, float yPos);

	void updateAccel();

	Point2D getPos();

	void move();
	void moveRight();		
	void moveLeft();
	void moveUp();		
	void noInput();
	void setActive(bool newActive);
	bool getActiveState();

	void slidingMotion();
	void slidingForce(float theta, float frCoef);
};

#endif