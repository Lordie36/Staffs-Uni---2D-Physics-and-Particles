#include "Appearance.h"
#include "ParticleModel.h"

Appearance::Appearance(ParticleModel* inPlayer, int objectWidth, int objectHeight)
{
	 player = inPlayer;
	 width = objectWidth;
	 height = objectHeight;
}

Appearance::~Appearance()
{
}

void Appearance::setShape2Square()
    {
    /* Load polygon (shape) data into vertex array */
    shape[0].x = 0.0F;	shape[0].y = 0.0F;
    shape[1].x = width;	shape[1].y = 0.0F;
    shape[2].x = width;	shape[2].y = height;
    shape[3].x = 0.0F;	shape[3].y = height;
    }

//void Appearance::setShape2Square(int x, int y)
//    {
//    /* Load polygon (shape) data into vertex array */
//    shape[0].x = 0.0F;	shape[0].y = 0.0F;
//    shape[1].x = width;	shape[1].y = 0.0F;
//    shape[2].x = width;	shape[2].y = y;
//    shape[3].x = 0.0F;	shape[3].y = y;
//    }

int Appearance::dispBufUpdate()
{
/* TO DO: add relevant code */

// update display object (content of display buffer (with calculated vertex coordinates of square at its current position))
for (int vert = 0; vert < 4; ++vert)
    {
		dispBuffObj[vert].x = shape[vert].x + player->getPos().x;
		dispBuffObj[vert].y = shape[vert].y + player->getPos().y;
    }

return 1;
}