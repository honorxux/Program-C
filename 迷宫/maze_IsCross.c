#include "maze.h"

int IsCross(PosType seat,MazeType *maze)
{
	int x = seat.x;
	int y = seat.y;
	
	if(x<0 || y<0 || x>((*maze).M-1)|| y>((*maze).N-1))
		return TRUE;					//Ô½½ç 
	else
		return FALSE; 
}

