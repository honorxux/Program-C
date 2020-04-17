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
	TElemType data; // ����ֵ
	struct BiTNode *lchild, *rchild; //���Һ���ָ�� 
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
	QueuePtr front;					//ͷָ�� 
	QueuePtr rear;					//βָ�� 
}LinkQueue;							//���е���ʽ�洢��ʾ 


void InitBiTree(BiTree *T);  //��ʼ�� 
Status CreateBiTree(BiTree *T);//������������ 
void PreOrderTraverse(BiTree T);//������� 
void InOrderTraverse(BiTree T, void(*Visit)(TElemType));//������� 
void PostOrderTraverse(BiTree T, void(Visit)(TElemType));//������� 
void PrintElem(TElemType e);

void InitCSTree(CSTree *T);
void CreatTree(CSTree *Tree);

Status InitQueue_L(LinkQueue *Q);
Status GetHead_L(LinkQueue *Q, QElemType_L *e);
Status EnQueue_L(LinkQueue *Q, QElemType_L e);
Status DeQueue_L(LinkQueue *Q, QElemType_L *e);
void PreOrderTraverse_t(CSTree T);

#endif
