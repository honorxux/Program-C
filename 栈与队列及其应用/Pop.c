#include "BeelzebubLang.h"


int Pop(SqStack *S,SElemType* e)
{
	if(S->top==S->base)
	return ERROR;
	*e=*(--S->top);
	return OK; 
	
	}    
