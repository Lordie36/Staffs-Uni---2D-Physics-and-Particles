#ifndef _bulletParticleModel_H
#define _bulletParticleModel_H

#include    <Windows.h>
#include	"input.h"
#include	"dataTypes.h"
#include	"graphics.h"
#include	<math.h>
	
class bulletParticleModel
{
private:
	Point2D 	pos;
	Point2D		velocity;
	Point2D		displacement;
	float		timeStep, gravity;
	Point2D		force;
	Point2D		netForce;
	int			particleMass;
	Point2D		acceleration;
	bool		touchingFloor,active, exploded, inAir;
	int			frictionForce;
	POINT		targetPos;
	int distance,vX,vY;
		
	float angle;
	Point2D bulletVector;

public:
	bulletParticleModel(int mass);//GraphicsM * pGraphicsModule);
	~bulletParticleModel();
	void update(float timeStep1);
	void updateGravity();
	void setAcceleration(int x, int y);
	void setVelocity(int x, int y);
	Point2D getVelocity();
	void setForce(int forceX, int forceY);
	void setDisplacement(int x, int y);
	Point2D getDisplacement();

	void setDisplacementX(int x);
	void setDisplacementY(int y);

	void moveConstDisp(int direction);
	void moveConstDisp();

	void xCollisionCheck();
	void yCollisionCheck();

	void updateInAirMotion();
	//void updateNetForce();
	void updateFriction();

	void updateVelocity();
	void moveConstVel();//float timeStep);
	void setPosition(float xPos, float yPos);

	void updateAccel();

	Point2D getPosition();
	Point2D getNetForce();
	void move();

	void moveRight();//float timeStep);			
	void moveLeft();//float timeStep);
	void moveUp();//float timeStep);			
	void moveDown();//float timeStep);
	void noInput();

	void fired(POINT cursorPos, Point2D playerPos);

	void setActive(bool newActive);
	bool getActiveState();

	void setExploded(bool hasExploded);
	bool getExploded();
};

#endif