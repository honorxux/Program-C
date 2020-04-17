#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define true 1
#define false 0
#define ERROR 0
#define OK 1

#define STACK_INIT_SIZE 100 //ջԪ�صĳ�ʼ�洢�ռ��С
#define STACK_INCREMENT 10 
typedef char SElemType,QElemType;
typedef struct { 
       SElemType *base; //˳��ջ��ջ��ָ��
       SElemType *top; //˳��ջ��ջ��ָ�� 
       int StackSize; //ջԪ�ؿռ�Ĵ�С 
    }SqStack; //�ṹ������˳��ջ 
    
#define MAXQSIZE 100 
typedef struct { 
       QElemType *base; //ָ��ѭ������Ԫ�ش洢�ռ��ָ�� 
       int front; //ѭ�����еĶ�ͷָ�� 
       int rear; //ѭ�����еĶ�βָ�� 
    }SqQueue; //�ṹ������ѭ������     


//����һ����ջ
int InitStack(SqStack *S); 

//����ջ,�ͷ�ջ��ռ�ڴ�ռ�
//void DestroyStack(SqStack *S);

//��ջSΪ��ջ,����true,���򷵻�false
int  StackEmpty(SqStack *S); 


//������Ԫ��eΪ�µ�ջ��Ԫ��
int Push(SqStack *S,SElemType e); 
//��ջ����,ɾ��S��ջ��Ԫ��,����e������ֵ,������true,���򷵻�false 
int Pop(SqStack *S,SElemType* e); 

//��ʼ��ѭ������  
int InitQueue(SqQueue *Q); 
//����Q��Ԫ�ظ���,�����еĳ��� 
int QueueLength(SqQueue *Q);
//������Ԫ��eΪQ���¶�βԪ�� 
int EnQueue(SqQueue *Q, QElemType e);
//�����в���,��ɾ��Q�Ķ�ͷԪ��,��e������ֵ,������true,���򷵻�false
int DeQueue(SqQueue *Q); 
 
#endif
