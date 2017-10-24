#include    <Windows.h>
#include	"input.h"
#include	"dataTypes.h"
#include	"graphics.h"
//class Particle;


class Particle
{
private:
				// array to store a polygonal shape consisting of four vertices (e.g. a square) 
	//ParticleModel* player;
	int lifeTime;
	Point2D pos, initialForce;
	bool active, first;
public:
	Point2D		dispBuffObj[4];	
	Point2D		shape[4];
private:
		

public:
	Particle();
		~Particle();
	void update();
	void setPosition(Point2D newPos);
	void setForce(Point2D newForce);
	void setShape2Square();
	void dispBufUpdate();
	void setActive(bool newActiveState);
	bool getActive();
	int getLifeTime();
	void setFirst(bool setFirst);
	bool getFirst();
};