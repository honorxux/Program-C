#include "maze.h"

int Pass(PosType seat, MazeType *maze)		 
{
	int x = seat.x;
	int y = seat.y;
    
    MazeType MAZE=*maze;
	

	
	if(!IsCross(seat,&MAZE) && (*maze).arr[x][y]==Way)	//结点不能越界
		return TRUE;
	else
		return ERROR;
}
