#include "maze.h"

void FootPrint(PosType seat, MazeType *maze)	//��ν�����㼣����������һ�η��ʷ��� 
{	
	(*maze).arr[seat.x][seat.y] = East; 					//��ʼ������̽�� 
} 
