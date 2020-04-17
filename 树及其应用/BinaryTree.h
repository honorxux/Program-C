#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <stdio.h>
#include <stdlib.h>

#define OK 1;
#define OVERFLOW -2
#define TRUE 1;
#define False 0;
#define ERROR 0;

typedef int Status;
typedef char TElemType;
typedef struct BiTNode{
	TElemType data; // 结点的值
	struct BiTNode *lchild, *rchild; //左右孩子指针 
}BiTNode,*BiTree;

typedef struct CSNode{
	TElemType data;
	struct CSNode *firstchild, *nextsibling;
}CSNode, *CSTree;

typedef CSTree QElemType_L;

typedef struct QNode				 
{
	QElemType_L Data;
	struct QNode *next;
}QNode;
typedef QNode* QueuePtr;
typedef struct
{
	QueuePtr front;					//头指针 
	QueuePtr rear;					//尾指针 
}LinkQueue;							//队列的链式存储表示 


void InitBiTree(BiTree *T);  //初始化 
Status CreateBiTree(BiTree *T);//创建二叉链表 
void PreOrderTraverse(BiTree T);//先序遍历 
void InOrderTraverse(BiTree T, void(*Visit)(TElemType));//中序遍历 
void PostOrderTraverse(BiTree T, void(Visit)(TElemType));//后序遍历 
void PrintElem(TElemType e);

void InitCSTree(CSTree *T);
void CreatTree(CSTree *Tree);

Status InitQueue_L(LinkQueue *Q);
Status GetHead_L(LinkQueue *Q, QElemType_L *e);
Status EnQueue_L(LinkQueue *Q, QElemType_L e);
Status DeQueue_L(LinkQueue *Q, QElemType_L *e);
void PreOrderTraverse_t(CSTree T);

#endif
