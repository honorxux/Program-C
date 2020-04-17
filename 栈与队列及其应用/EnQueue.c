#include "BeelzebubLang.h"



//插入新元素e为Q的新队尾元素 
int EnQueue(SqQueue *Q, QElemType e)
{
	if((Q->rear+1)%MAXQSIZE==Q->front)  return ERROR;
	Q->base[Q->rear]=e;
	Q->rear=(Q->rear+1)%MAXQSIZE;
	return OK;
}
