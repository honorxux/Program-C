#include "maze.h"

void MarkPrint(PosType seat, MazeType *maze)
{
	int x = seat.x;
	int y = seat.y;
	
	(*maze).arr[x][y] = DeadLock;			    //���²���ͨ���ı�� 
}
