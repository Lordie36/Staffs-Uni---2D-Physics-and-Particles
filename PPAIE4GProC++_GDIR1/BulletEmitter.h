#include	"dataTypes.h"
#include	"Particle.h"
class BulletEmitter
{
private:
	int spawningRate, particleLifetime, spawnTimer, explosionTimer;
	Point2D initialParticleForce, pos, offScreenPos, noForce;
	bool explodedState;
public:
	Particle* particles[15];

public:
	BulletEmitter();
	~BulletEmitter();
	void update(Point2D currentForce, Point2D newPos);
	void randomiseNextVector(Point2D currentForce);
	void randomiseNextLifetime();
};