#include "BeelzebubLang.h"

//����Q��Ԫ�ظ���,�����еĳ��� 
int QueueLength(SqQueue *Q)
{   
    int cnt;
	cnt=(Q->rear-Q->front+MAXQSIZE)%MAXQSIZE;
	
	
	return cnt;
}
