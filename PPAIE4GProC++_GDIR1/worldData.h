#ifndef _WORLDDATA_H
#define _WORLDDATA_H

#include	<windows.h>
#include	"dataTypes.h"		/* include file for custom data types */
#include	"graphics.h"		/* include file for graphics module */
#include	"input.h"			/* include file for user input module */
#include	"bulletObject.h"
#include	"PlayerObject.h"
#include    "EnemyObject.h"
#include	<string>
#include	<list>
class bulletObject;

class WorldData
	{
	private:
		//GraphicsM viewport;
		GraphicsM * pGraphicsModule;

		//ParticleModel* player;
		//Appearance* appearance;

		EnemyObject* enemy;
		PlayerObject* playerObject;
		float gameTime;
		float time;	
		bulletObject* bulletArray[5];
		int bulletDelay;
		POINT cursorPos;
		Point2D hillPos1, hillPos2, hillPos3, test, test1;
	public:

		// Constructors and destructor
		WorldData();
		~WorldData();

		int worldDataModuleInit();						// Initialise the world
		void worldCleanUp();							// Release objects, if applicable

		int update(keyEvent kEvent);					// Update the world's dynamics state
		void gameLoopDelay(float frameStartDelay);
		int draw(GraphicsM * pGraphicsModule);			// Draw the world

	private: 
		/* Apply physics formulae to particle */
		//int moveRight();			// Move particle towards right
		//int moveLeft();
		//void setShape2Square();		// Set shape of object to square

		/* Graphics data update (before actual display) */
		//int dispBufUpdate();		// Update display buffer
		float frameProcessingTime;
		float frameRateInterval;
		float frameStartTime;
		float oldFrameTime;
		float timeStep;
	};

#endif /* _WORLDDATA_H */
