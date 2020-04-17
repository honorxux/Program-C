#include "maze.h"

int Pop_Sq(SqStack *S, SElemType_Sq *e)
{
	if((*S).top==(*S).base)
		return ERROR;

	(*S).top--;									//出栈栈顶指针先递减，再赋值 
	*e = *((*S).top);

	return OK;
} 
