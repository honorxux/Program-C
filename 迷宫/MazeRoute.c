#include "maze.h"


void MazeRoute(SqStack *S)
{
	SqStack SS;
	InitStack_Sq(&SS);
	SElemType_Sq node1,node2,route;
	while(!StackEmpty_Sq(*S)) 
	{
		Pop_Sq(S, &node1);
	
        SetSElemType(&node2, node1.ord, node1.seat, node1.di);	//设置通道块信息     
     	Push_Sq(&SS, node2);
	}
	while(!StackEmpty_Sq(SS))
	{
		Pop_Sq(&SS, &route);
		printf("(%d,%d,%d) ",route.seat.x+1,route.seat.y+1,route.di);
	}
}
