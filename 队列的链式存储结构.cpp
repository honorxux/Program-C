//��ͷ���    Q->front 
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0

typedef int QElemType_L;
typedef int Status;

typedef struct QNode{
	QElemType_L data;
	struct QNode *next;
}QNode,*QueuePtr;

typedef struct{
	QueuePtr rear;
	QueuePtr front;
}LinkQueue;

Status InitQueue_L(LinkQueue *Q);          //��ʼ������Q
void ClearQueue_L(LinkQueue *Q);           //�ÿ�Q
void DestroyQueue_L(LinkQueue *Q);         //����Q
Status QueueEmpty_L(LinkQueue Q);          //�ж�Q�Ƿ�Ϊ��
int QueueLength_L(LinkQueue Q);            //����QԪ�ظ���
Status GetHead_L(LinkQueue Q, QElemType_L *e);           //��e��ȡ��ͷԪ��
Status EnQueue_L(LinkQueue *Q, QElemType_L e);           //Ԫ��e���
Status DeQueue_L(LinkQueue *Q, QElemType_L *e);          //Ԫ��e����

 
Status InitQueue_L(LinkQueue *Q)
{
	Q->front=Q->rear=(QueuePtr)malloc(sizeof(QNode));
	if(!Q->front)
	{
		return ERROR;
	}
	(*Q).front->next = NULL;
	return OK;
 }
 
void ClearQueue_L(LinkQueue *Q)
{
	Q->rear=Q->front->next;
	while(Q->rear)
	{
		Q->front->next=Q->rear->next;
		free(Q->rear);
		Q->rear=Q->front->next;
	}//ѭ�����յ�Ϊ ��*Q��.next=NULL 
	
	Q->rear=Q->front; //����βָ���ͷָ�붼ָ��ͷ���
}

void DestroyQueue_L(LinkQueue *Q)
{
	while(Q->front)
	{
		Q->rear=Q->front->next;
		free(Q->front);
		Q->front=Q->rear; 
	}
}

Status QueueEmpty_L(LinkQueue Q)
{
	if(Q.front==Q.rear)
	{
		return TRUE;
	}
	return FALSE; 
}

int QueueLength_L(LinkQueue Q)
{
	int count=0;
	QueuePtr p =Q.front;   //���µ�ָ��ȥ�����������ƻ�ԭ���еĽṹ 
	while(p!=Q.rear)
	{
		count++;
		p=p->next;
	}
	
	return count;
}

Status GetHead_L(LinkQueue Q, QElemType_L *e)
{
	if(Q.front==Q.rear)
	{
		return ERROR;
	}
	*e=Q.front->next->data;
	return OK;
}

Status EnQueue_L(LinkQueue *Q, QElemType_L e)
{
	QueuePtr p;
	p=(QueuePtr)malloc(sizeof(QNode));
	if(!p)
	{
		return ERROR;
	}
	p->data=e;
	p->next=NULL;
	Q->rear->next=p;
	Q->rear=p;
	return OK;
 }

Status DeQueue_L(LinkQueue *Q, QElemType_L *e)
{
	QueuePtr p;
	if(Q->front==Q->rear)
	{
		return ERROR;
	}
	p=Q->front->next;
	*e=p->data;
	(*Q).front->next = p->next;
	if((*Q).rear==p)           //���ֻ��һ��Ԫ�أ���ͷָ���βָ�붼ָ��ͷ��㣬����Ϊ�� 
		(*Q).rear = (*Q).front;
		
	free(p);
	
	return OK; 
 }
 
int main()
{
	//���� 
}
