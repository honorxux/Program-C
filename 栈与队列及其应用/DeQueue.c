#include "BeelzebubLang.h"

//�����в���,��ɾ��Q�Ķ�ͷԪ��,������true,���򷵻�false
int DeQueue(SqQueue *Q)
{
	if(Q->front==Q->rear)  return false;
	Q->front=(Q->front+1)%MAXQSIZE;
	return true;
}
