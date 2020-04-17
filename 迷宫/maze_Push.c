#include "maze.h"

int Push_Sq(SqStack *S, SElemType_Sq e)
{
	if((*S).top-(*S).base>=(*S).stacksize)		//Õ»Âú£¬×·¼Ó´æ´¢¿Õ¼ä
	{
		(*S).base = (SElemType_Sq *)realloc((*S).base, ((*S).stacksize+STACKINCREMENT)*sizeof(SElemType_Sq));
		if(!(*S).base)
			exit(OVERFLOW);						//´æ´¢·ÖÅäÊ§°Ü
		(*S).top = (*S).base + (*S).stacksize;
		(*S).stacksize += STACKINCREMENT;
	}
	
	*(S->top) = e;								//½øÕ»ÏÈ¸³Öµ£¬Õ»¶¥Ö¸ÕëÔÙ×ÔÔö 
	(S->top)++;

	return OK;
} 
