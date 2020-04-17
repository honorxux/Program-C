#include "BeelzebubLang.h"

//若队列不空,则删除Q的队头元素,并返回true,否则返回false
int DeQueue(SqQueue *Q)
{
	if(Q->front==Q->rear)  return false;
	Q->front=(Q->front+1)%MAXQSIZE;
	return true;
}
