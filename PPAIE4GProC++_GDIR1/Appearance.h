#ifndef _Appearance_H
#define _Appearance_H

#include    <Windows.h>
#include	"input.h"
#include	"dataTypes.h"
#include	"graphics.h"
class ParticleModel;


class Appearance
{
private:
				// array to store a polygonal shape consisting of four vertices (e.g. a square) 
	ParticleModel* player;
	int height,width;
public:
	Point2D		dispBuffObj[4];	
	Point2D		shape[4];
private:
		

public:
	Appearance(ParticleModel* player, int objectWidth, int objectHeight);
		~Appearance();
		
	void setShape2Square();
	//void setShape2Square(int x, int y);
	int dispBufUpdate();

};
#endif
