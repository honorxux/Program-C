#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define MAXQSIZE 1000					//�����г���

typedef int Status;

typedef int QElemType_CSq;
typedef struct							//���е�˳��洢�ṹ
{
	QElemType_CSq *base;				//��ʼ���Ķ�̬����洢�ռ� 
	int front;							//ͷָ�룬�����в��գ�ָ���ͷԪ�� 
	int rear;							//βָ�룬�����в��գ�ָ�����βԪ�ص���һ��λ�� 
}CSqQueue;

Status InitQueue_CSq(CSqQueue *Q);      //��ʼ��ѭ������Q
void ClearQueue_CSq(CSqQueue *Q);       //�ÿ�Q
void DestroyQueue_CSq(CSqQueue *Q);     //����Q
Status QueueEmpty_CSq(CSqQueue Q);      //�ж�Q�Ƿ�Ϊ��
int QueueLength_CSq(CSqQueue Q);        //����QԪ�ظ���
Status GetHead_CSq(CSqQueue Q, QElemType_CSq *e);               //��e��ȡ��ͷԪ��
Status EnQueue_CSq(CSqQueue *Q, QElemType_CSq e);               //Ԫ��e���
Status DeQueue_CSq(CSqQueue *Q, QElemType_CSq *e);              //Ԫ��e����

Status InitQueue_CSq(CSqQueue *Q)
{
	Q->base=(QElemType_CSq *)malloc(sizeof(QElemType_CSq));
	if(!Q->base)
	{
		return ERROR;
	}
	Q->front=Q->rear=0;
	return OK;
}

void ClearQueue_CSq(CSqQueue *Q)      //˳��ṹ����պ���������Ƚϴ���Ҫ�ر�ע��һ�� 
{
	(*Q).front = (*Q).rear = 0;
}

void DestroyQueue_CSq(CSqQueue *Q)
{
	if(Q->base)
		free(Q->base);
		
	(*Q).base = NULL;
	(*Q).front = (*Q).rear = 0;
}

Status QueueEmpty_CSq(CSqQueue Q)
{
	if(Q.front==Q.rear)
	{
		return TRUE;
	}
	else
	{
		return FALSE; 
	}
}

int QueueLength_CSq(CSqQueue Q)
{
	return (Q.rear-Q.front+MAXQSIZE)%MAXQSIZE;
}

Status GetHead_CSq(CSqQueue Q, QElemType_CSq *e)
{
	if(Q.front==Q.rear)
	{
		return ERROR;
	}
	*e=Q.base[Q.front];
	return OK;
}

//˳����У�ѭ�����У�������˳���˳��ջһ���ڷ���֮������洢�ռ䣬��Ϊ����ѭ���ģ����Ӻ������
Status EnQueue_CSq(CSqQueue *Q, QElemType_CSq e)      //����˳��ṹ����֮ǰ��Ҫ���ж� ��û�� 
{
	if((Q->rear+1)%MAXQSIZE==Q->front)
	{
		return ERROR;
	}
	Q->base[Q->rear]=e;
	Q->rear=(Q->rear+1)%MAXQSIZE;
	return OK; 
}

Status DeQueue_CSq(CSqQueue *Q, QElemType_CSq *e)
{
    if((*Q).front==(*Q).rear)					//���п�
		return ERROR;
		
	*e = (*Q).base[(*Q).front];
	(*Q).front = ((*Q).front+1)%MAXQSIZE;
	
	return OK;
}

int main()
{
	//���� 
}
