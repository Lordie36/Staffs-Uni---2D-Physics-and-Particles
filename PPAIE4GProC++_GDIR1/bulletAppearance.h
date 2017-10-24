#ifndef _bulletAppearance_H
#define _bulletAppearance_H

#include    <Windows.h>
#include	"input.h"
#include	"dataTypes.h"
#include	"graphics.h"
class bulletParticleModel;


class bulletAppearance
{
private:
				// array to store a polygonal shape consisting of four vertices (e.g. a square) 
	bulletParticleModel* bullet;
public:
	Point2D		dispBuffObj[4];	
	Point2D		shape[4];
private:
		

public:
	bulletAppearance(bulletParticleModel* player);
		~bulletAppearance();
		
	void setShape2Square();
	int dispBufUpdate();

};
#endif
