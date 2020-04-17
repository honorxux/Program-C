#include "BeelzebubLang.h"


int Push(SqStack *S,SElemType e)
{//插入元素e为新的栈顶元素
  if(S->top-S->base>=S->StackSize)      //栈满，追加存储空间             //怎么可以相减？ 
  {
  	S->base=(SElemType*)realloc(S->base,(S->StackSize+STACK_INCREMENT)*sizeof(SElemType));
  	if(!S->base)  return ERROR;
  	
  	S->top=S->base+S->StackSize;                                       //怎么可以相加？
	S->StackSize+=STACK_INCREMENT; 
   } 
   
   *(S->top)++=e;
   
   return OK;	
}
