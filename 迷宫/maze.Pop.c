#include "maze.h"

int Pop_Sq(SqStack *S, SElemType_Sq *e)
{
	if((*S).top==(*S).base)
		return ERROR;

	(*S).top--;									//��ջջ��ָ���ȵݼ����ٸ�ֵ 
	*e = *((*S).top);

	return OK;
} 
