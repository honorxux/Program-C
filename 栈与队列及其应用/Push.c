#include "BeelzebubLang.h"


int Push(SqStack *S,SElemType e)
{//����Ԫ��eΪ�µ�ջ��Ԫ��
  if(S->top-S->base>=S->StackSize)      //ջ����׷�Ӵ洢�ռ�             //��ô��������� 
  {
  	S->base=(SElemType*)realloc(S->base,(S->StackSize+STACK_INCREMENT)*sizeof(SElemType));
  	if(!S->base)  return ERROR;
  	
  	S->top=S->base+S->StackSize;                                       //��ô������ӣ�
	S->StackSize+=STACK_INCREMENT; 
   } 
   
   *(S->top)++=e;
   
   return OK;	
}
