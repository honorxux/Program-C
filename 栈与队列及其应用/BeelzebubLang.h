#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define true 1
#define false 0
#define ERROR 0
#define OK 1

#define STACK_INIT_SIZE 100 //栈元素的初始存储空间大小
#define STACK_INCREMENT 10 
typedef char SElemType,QElemType;
typedef struct { 
       SElemType *base; //顺序栈的栈底指针
       SElemType *top; //顺序栈的栈顶指针 
       int StackSize; //栈元素空间的大小 
    }SqStack; //结构体类型顺序栈 
    
#define MAXQSIZE 100 
typedef struct { 
       QElemType *base; //指向循环队列元素存储空间的指针 
       int front; //循环队列的队头指针 
       int rear; //循环队列的队尾指针 
    }SqQueue; //结构体类型循环队列     


//构造一个空栈
int InitStack(SqStack *S); 

//销毁栈,释放栈所占内存空间
//void DestroyStack(SqStack *S);

//若栈S为空栈,返回true,否则返回false
int  StackEmpty(SqStack *S); 


//插入新元素e为新的栈顶元素
int Push(SqStack *S,SElemType e); 
//若栈不空,删除S的栈顶元素,并用e返回其值,并返回true,否则返回false 
int Pop(SqStack *S,SElemType* e); 

//初始化循环队列  
int InitQueue(SqQueue *Q); 
//返回Q的元素个数,即队列的长度 
int QueueLength(SqQueue *Q);
//插入新元素e为Q的新队尾元素 
int EnQueue(SqQueue *Q, QElemType e);
//若队列不空,则删除Q的队头元素,用e返回其值,并返回true,否则返回false
int DeQueue(SqQueue *Q); 
 
#endif
