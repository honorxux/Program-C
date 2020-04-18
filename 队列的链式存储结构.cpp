//有头结点    Q->front 
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

Status InitQueue_L(LinkQueue *Q);          //初始化链队Q
void ClearQueue_L(LinkQueue *Q);           //置空Q
void DestroyQueue_L(LinkQueue *Q);         //销毁Q
Status QueueEmpty_L(LinkQueue Q);          //判断Q是否为空
int QueueLength_L(LinkQueue Q);            //返回Q元素个数
Status GetHead_L(LinkQueue Q, QElemType_L *e);           //用e获取队头元素
Status EnQueue_L(LinkQueue *Q, QElemType_L e);           //元素e入队
Status DeQueue_L(LinkQueue *Q, QElemType_L *e);          //元素e出队

 
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
	}//循环的终点为 （*Q）.next=NULL 
	
	Q->rear=Q->front; //再让尾指针和头指针都指向头结点
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
	QueuePtr p =Q.front;   //用新的指针去遍历，不能破坏原队列的结构 
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
	if((*Q).rear==p)           //如果只有一个元素，则头指针和尾指针都指向头结点，队列为空 
		(*Q).rear = (*Q).front;
		
	free(p);
	
	return OK; 
 }
 
int main()
{
	//测试 
}
