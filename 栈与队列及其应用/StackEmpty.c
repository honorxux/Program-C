#include "BeelzebubLang.h"


//��ջSΪ��ջ,����true,���򷵻�false
int StackEmpty(SqStack *S)
{
    if(S->top==S->base)
	return true;
	else 
	return 0;	
}
