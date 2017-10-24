#include "bulletAppearance.h"
#include "bulletParticleModel.h"

bulletAppearance::bulletAppearance(bulletParticleModel* inPlayer)
{
	 bullet = inPlayer;
}

bulletAppearance::~bulletAppearance()
{
}

void bulletAppearance::setShape2Square()
    {
    /* Load polygon (shape) data into vertex array */
    shape[0].x = 0.0F;	shape[0].y = 0.0F;
    shape[1].x = 10.0F;	shape[1].y = 0.0F;
    shape[2].x = 10.0F;	shape[2].y = 10.0F;
    shape[3].x = 0.0F;	shape[3].y = 10.0F;
    }

int bulletAppearance::dispBufUpdate()
{
/* TO DO: add relevant code */

// update display object (content of display buffer (with calculated vertex coordinates of square at its current position))
for (int vert = 0; vert < 4; ++vert)
    {
		dispBuffObj[vert].x = shape[vert].x + bullet->getPosition().x;
		dispBuffObj[vert].y = shape[vert].y + bullet->getPosition().y;
    }

return 1;
}