#include "maze.h"

void FootPrint(PosType seat, MazeType *maze)	//所谓留下足迹即设置其下一次访问方向 
{	
	(*maze).arr[seat.x][seat.y] = East; 					//初始设置向东探索 
} 
