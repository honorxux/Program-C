#include "maze.h"


int main ()
{
    MazeType maze;
    printf("请输入迷宫的长：\n");
	scanf("%d",&maze.N);
	printf("请输入迷宫的宽：\n");
	scanf("%d",&maze.M); 
	PosType start, end;
	SElemType_Sq e;

	InitMaze(&maze,maze.N,maze.M,&start, &end);	//初始化迷宫，包括出入口 
	PrintMaze(&maze,maze.N,maze.M);					//画出生成的迷宫 
	Mazepath(&maze,start,end);
	
	return 0;
}


