#include "BeelzebubLang.h"


int InitQueue(SqQueue *Q)
{
	Q->base=(QElemType*)malloc(MAXQSIZE*sizeof(QElemType));
	if(!Q->base)  return ERROR;
	Q->front=Q->rear=0;
	return OK;
}
