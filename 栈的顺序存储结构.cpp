#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0

#define STACK_INIT_SIZE	100				//顺序栈存储空间的初始分配量
#define STACKINCREMENT	10 				//顺序栈存储空间的分配增量

typedef int Status;
typedef int SElemType;

typedef struct
{
	SElemType *base;				//在栈构造之前和销毁之后，base的值为NULL 
	SElemType *top;			    	//栈顶指针 
	int stacksize;					//当前已分配的存储空间，以元素为单位 
}SqStack;


Status InitStack_Sq(SqStack *S);       //构造空栈S
Status DestroyStack_Sq(SqStack *S);    //销毁S
Status ClearStack_Sq(SqStack *S);      //置空栈S
Status StackEmpty_Sq(SqStack S);       //判断栈S是否为空
Status StackLength_Sq(SqStack S);      //返回栈S中元素的个数
Status GetTop_Sq(SqStack S, SElemType *e);      //用e获取栈顶元素
Status Push_Sq(SqStack *S, SElemType e);        //元素e进栈
Status Pop_Sq(SqStack *S, SElemType *e);        //元素e出栈


Status InitStack_Sq(SqStack *S)
{
	(*S).base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if(!(*S).base)
	{
		exit(ERROR);
	}
	(*S).top=(*S).base;
	(*S).stacksize=STACK_INIT_SIZE;
	return OK;
 } 

Status DestoryStack_Sq(SqStack *S)
{
	free((*S).base);
	(*S).base=NULL;
	(*S).top=NULL;
	(*S).stacksize=0;
	return OK;
}

Status ClearStack_Sq(SqStack *S)
{
	(*S).top=(*S).base;
	return OK;
}

Status StackEmpty_Sq(SqStack S)
{
	if(S.base==S.top)
	{
		return TRUE;
	}
	return FALSE; 
}

Status StackLength_Sq(SqStack S)
{
	return S.top-S.base;
}

Status GetTop_Sq(SqStack S, SElemType *e)
{
	if(S.base==S.top)
	{
		return ERROR; 
	}
	*e=*(S.top-1);
	return OK;
}

Status Push_Sq(SqStack *S, SElemType e)
{
	if((*S).top-(*S).base>=(*S).stacksize)
	{
		(*S).base = (SElemType *)realloc((*S).base, ((*S).stacksize+STACKINCREMENT)*sizeof(SElemType));
		if(!(*S).base)
			exit(ERROR);						//存储分配失败
		(*S).top = (*S).base + (*S).stacksize;
		(*S).stacksize += STACKINCREMENT;
	}
	*((*S).top)=e;
	(*S).top++;
	return OK;
}

Status Pop_Sq(SqStack *S, SElemType *e)
{
	if(S->base==S->top)
	{
		return ERROR;
	}
	S->top--;
	*e=*(S->top);
	return OK;
}

int main()
{
	//测试 
}


