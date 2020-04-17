#include "BeelzebubLang.h"

int InitStack(SqStack *S)
{
    S->base=(SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
    if(!S->base) return ERROR; //ÄÚ´æ·ÖÅäÊ§°Ü
	S->top=S->base;
	S->StackSize=STACK_INIT_SIZE;
    
	return OK;
}
