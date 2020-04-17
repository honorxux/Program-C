#include "maze.h"

int StackEmpty_Sq(SqStack S)
{
	if(S.top==S.base)
		return TRUE;
	else
		return FALSE;
} 
