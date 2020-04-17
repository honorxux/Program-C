#include "maze.h"

PosType NextPos(PosType seat, int di)
{	
	PosType tmp = seat;

	switch(di)
	{
		case East:  tmp.y++;			//�� 
			break;	
		case South: tmp.x++;			//����
			break;
		case West:  tmp.y--;			//���� 
			break;
		case North: tmp.x--;			//��
			break;
	}
	
	return tmp;
}
