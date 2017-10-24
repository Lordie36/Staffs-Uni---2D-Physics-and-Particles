/*
 * File name:	worldData.cpp
 * Description:	World data module.
 *
 * Author: 			Claude C. Chibelushi
 * Date:			04/10/04
 *					Modified 27/09/06, by CCC: addition of function for setting object shape
 *					Modified 19/01/09 by CCC: porting to C++
 *							 06/02/09 by CCC: additional functionality required  
 *                           for illustrative examples of GDI drawing functionality.
 *
 */
 

#include "worldData.h"
#include "ParticleModel.h"
/*----------------------------------------------------------------------------\
 *                                                                            |
 *                       INITIALISATION AND CLEAN UP                   		  |
 *                                                                            |
 *----------------------------------------------------------------------------*/

/*
	Constructs and initialises a world data management module

	Parameter list
		none
 */

WorldData::WorldData()
	{
		//bulletObject = new GameObject(100);
		playerObject = new PlayerObject(1000, 20,20);
		enemy = new EnemyObject(200, 50,50, false);
		bulletDelay = 0;

		for(int i = 0; i < 5; i++)
		{
			bulletArray[i] = new bulletObject(100, 10,10);
		}
		frameRateInterval = 50;
	}



/**
    Initialises the world

	Parameter list
         none.
  */
int WorldData::worldDataModuleInit()
	{
		//Set the position of objects
		playerObject->player->setPosition(400.0f,400.0f);
		enemy->object->setPosition(500.0f,200.0f);

		// Initialise appearance parameters of game object
		playerObject->appearance->setShape2Square();
		enemy->appearance->setShape2Square();

		//bullet array initilaised in a for loop
		for(int i = 0; i < 5; i++)
		{
			bulletArray[i]->object->setPosition(0.0f,600.0f);
			bulletArray[i]->appearance->setShape2Square();

			for(int j = 0; j< 15; j++)
			{
				bulletArray[i]->emitter->particles[j]->setShape2Square();
			}
		}

		return 1;
	}


/*
	Destructs world data management module

	Parameter list
		none
 */
WorldData::~WorldData()
	{
	/* TO DO: add relevant code */

	worldCleanUp();

	return;			
	}



/*
 Releases objects

 Parameter list
 	none
 */

void WorldData::worldCleanUp()
	{
	/* TO DO: add relevant code */

	return;			
	}

		/*----------------------------------------------------------------------------\
		 *                                                                            |
		 *                  STATE ACCESS (get / set) FUNCTIONS                        |
		 *                                                                            |
		 *----------------------------------------------------------------------------*/
     
/* TODO: Add functions to set other particle model parameters, e.g. velocity, acceleration, ... */

/* TODO: Add functions to get other particle model parameters, e.g. velocity, acceleration, ... */

		/*----------------------------------------------------------------------------\
		 *                                                                            |
		 *                                  STATE UPDATE                              |
		 *                                                                            |
		 *----------------------------------------------------------------------------*/

int WorldData::update(keyEvent kEvent)
	{
		frameStartTime = GetTickCount();
		timeStep = frameStartTime - oldFrameTime;
		playerObject->player->updateNetForce();

		playerObject->Update(kEvent,timeStep);
		enemy->Update(timeStep);
		bulletDelay ++;

		if(playerObject->collidesWith(enemy) == true)
		{
			playerObject->player->setPosition(playerObject->player->getPrevPos().x, playerObject->player->getPrevPos().y);
		}

		for(int i =0;i <5;i++)
		{
			bulletArray[i]->Update(timeStep);
			if(bulletDelay >= 5)
			{
				if ((GetKeyState(VK_LBUTTON) & 0x8000) && bulletArray[i]->getFiredState() == false)
					{
					
						bulletArray[i]->object->setPosition(playerObject->player->getPos().x,playerObject->player->getPos().y);
						GetCursorPos(&cursorPos);
						bulletArray[i]->object->fired(cursorPos,playerObject->player->getPos());
						
						//spawns bullet in, bullet then takes trajectory path
						bulletArray[i]->setFiredState(true);
						bulletDelay = 0;
						bulletArray[i]->object->setActive(true);
					}

				if(bulletArray[4]->getFiredState() == true)
				{
					for(int j = 0; j < 5;j++)
					{
						bulletArray[j]->setFiredState(false);
					}
				}
			}

			for(int j = 0; j< 5; j++)
			{
				if(bulletArray[j]->collidesWith(enemy) == true)
				{
					enemy->object->setActive(false);
					enemy->object->setPosition(800,800);
				}
			}


		}

		

		gameLoopDelay(frameStartTime);

		oldFrameTime = frameStartTime;

		return 1;
	}


void WorldData::gameLoopDelay(float frameStartDelay)
{
	frameProcessingTime = GetTickCount() - frameStartDelay;

	if(frameProcessingTime < frameRateInterval)
	{
		Sleep(  frameRateInterval - frameProcessingTime);
	}
}
/*
	Updates particle position: move particle towards right.

	Parameter list
		none
 */

/* TO DO: Add functions to update other particle model parameters, e.g. velocity, acceleration, ... */


	/*----------------------------------------------------------------------------\
	 *                                                                            |
	 *                                   DISPLAY                                  |
	 *                                                                            |
	 *----------------------------------------------------------------------------*/

int WorldData::draw(GraphicsM * pGraphicsModule)
	{
	//   Draw the square.
    playerObject->appearance->dispBufUpdate();	// update content of display buffer (with outline of square at its current position)
	pGraphicsModule->drawPolygon(playerObject->appearance->dispBuffObj, 4, true); // display content of buffer

	enemy->appearance->dispBufUpdate();
	pGraphicsModule->drawPolygon(enemy->appearance->dispBuffObj, 4, true);
	for(int i =0;i <5;i++)
	{
		bulletArray[i]->appearance->dispBufUpdate();
		pGraphicsModule->drawPolygon(bulletArray[i]->appearance->dispBuffObj, 4, true);
		for(int j = 0; j< 15; j++)
		{
			bulletArray[i]->emitter->particles[j]->dispBufUpdate();
			pGraphicsModule->drawPolygon(bulletArray[i]->emitter->particles[j]->dispBuffObj, 4, true);
		}
	}
	return 1;
    }


/*
 * Updates content of display buffer.
 *
 * Parameter list
 *        none.
 */



