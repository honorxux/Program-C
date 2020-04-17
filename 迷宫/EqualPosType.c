#include "maze.h"

int EqualPosType(PosType seat1, PosType seat2)
{
	if(seat1.x==seat2.x && seat1.y==seat2.y)
   {
		printf("%d %d",seat1.x,seat1.y);
	     printf("%d %d",seat2.x,seat2.y);
		return TRUE;	//两通道块坐标相等返回1 
	}
	else
		return ERROR;
}
