#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define MAXQSIZE 1000					//最大队列长度

typedef int Status;

typedef int QElemType_CSq;
typedef struct							//队列的顺序存储结构
{
	QElemType_CSq *base;				//初始化的动态分配存储空间 
	int front;							//头指针，若队列不空，指向队头元素 
	int rear;							//尾指针，若队列不空，指向队列尾元素的下一个位置 
}CSqQueue;

Status InitQueue_CSq(CSqQueue *Q);      //初始化循环队列Q
void ClearQueue_CSq(CSqQueue *Q);       //置空Q
void DestroyQueue_CSq(CSqQueue *Q);     //销毁Q
Status QueueEmpty_CSq(CSqQueue Q);      //判断Q是否为空
int QueueLength_CSq(CSqQueue Q);        //返回Q元素个数
Status GetHead_CSq(CSqQueue Q, QElemType_CSq *e);               //用e获取队头元素
Status EnQueue_CSq(CSqQueue *Q, QElemType_CSq e);               //元素e入队
Status DeQueue_CSq(CSqQueue *Q, QElemType_CSq *e);              //元素e出队

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

void ClearQueue_CSq(CSqQueue *Q)      //顺序结构的清空和销毁区别比较大，需要特别注意一下 
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

//顺序队列（循环队列）不能像顺序表、顺序栈一样在分配之后扩大存储空间，因为它是循环的，增加后会乱序
Status EnQueue_CSq(CSqQueue *Q, QElemType_CSq e)      //对于顺序结构插入之前需要先判断 满没满 
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
    if((*Q).front==(*Q).rear)					//队列空
		return ERROR;
		
	*e = (*Q).base[(*Q).front];
	(*Q).front = ((*Q).front+1)%MAXQSIZE;
	
	return OK;
}

int main()
{
	//测试 
}
