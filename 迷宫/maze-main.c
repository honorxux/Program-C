#include "maze.h"


int main ()
{
    MazeType maze;
    printf("�������Թ��ĳ���\n");
	scanf("%d",&maze.N);
	printf("�������Թ��Ŀ�\n");
	scanf("%d",&maze.M); 
	PosType start, end;
	SElemType_Sq e;

	InitMaze(&maze,maze.N,maze.M,&start, &end);	//��ʼ���Թ������������ 
	PrintMaze(&maze,maze.N,maze.M);					//�������ɵ��Թ� 
	Mazepath(&maze,start,end);
	
	return 0;
}


