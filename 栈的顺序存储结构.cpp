#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0

#define STACK_INIT_SIZE	100				//˳��ջ�洢�ռ�ĳ�ʼ������
#define STACKINCREMENT	10 				//˳��ջ�洢�ռ�ķ�������

typedef int Status;
typedef int SElemType;

typedef struct
{
	SElemType *base;				//��ջ����֮ǰ������֮��base��ֵΪNULL 
	SElemType *top;			    	//ջ��ָ�� 
	int stacksize;					//��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ 
}SqStack;


Status InitStack_Sq(SqStack *S);       //�����ջS
Status DestroyStack_Sq(SqStack *S);    //����S
Status ClearStack_Sq(SqStack *S);      //�ÿ�ջS
Status StackEmpty_Sq(SqStack S);       //�ж�ջS�Ƿ�Ϊ��
Status StackLength_Sq(SqStack S);      //����ջS��Ԫ�صĸ���
Status GetTop_Sq(SqStack S, SElemType *e);      //��e��ȡջ��Ԫ��
Status Push_Sq(SqStack *S, SElemType e);        //Ԫ��e��ջ
Status Pop_Sq(SqStack *S, SElemType *e);        //Ԫ��e��ջ


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
			exit(ERROR);						//�洢����ʧ��
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
	//���� 
}


