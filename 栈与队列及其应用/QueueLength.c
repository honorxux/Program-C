#include "BeelzebubLang.h"

//返回Q的元素个数,即队列的长度 
int QueueLength(SqQueue *Q)
{   
    int cnt;
	cnt=(Q->rear-Q->front+MAXQSIZE)%MAXQSIZE;
	
	
	return cnt;
}
