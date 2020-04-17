#include "maze.h"

PosType NextPos(PosType seat, int di)
{	
	PosType tmp = seat;

	switch(di)
	{
		case East:  tmp.y++;			//向东 
			break;	
		case South: tmp.x++;			//向南
			break;
		case West:  tmp.y--;			//向西 
			break;
		case North: tmp.x--;			//向北
			break;
	}
	
	return tmp;
}
