#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
typedef int Status;
typedef int ElemType;
typedef struct Node{
	ElemType data;
	struct Node *Next;
}Node;

typedef struct Node *LinkList;

Status InitList_L(LinkList *L);   //初始化单链表L
Status ClearList_L(LinkList L);   //置空单链表L，头结点保留
void DestroyList_L(LinkList *L);  //销毁单链表L，连同通结点一起销毁。 
Status ListEmpty_L(LinkList L);   //判断单链表L是否为空
int ListLength_L(LinkList L);     //返回单链表L元素个数
Status GetElem_L(LinkList L, int i, ElemType *e);       //用e接收单链表L中第i个元素
Status ListInsert_L(LinkList L, int i, ElemType e);     //在单链表L第i个位置之前插入e
Status ListDelete_L(LinkList L, int i, ElemType *e);    //删除单链表L第i个位置的值，并用e接收
Status CreateList_HL(LinkList *L, int n);        //头插法建立单链表L(逆序输入)
Status CreateList_TL(LinkList *L, int n);        //尾插法建立单链表L(顺序输入)

Status InitList_L(LinkList *L)  //头结点 
{
	(*L)=(LinkList)malloc(sizeof(Node));
	if(!(*L)){
		return ERROR;
	}
	(*L)->Next=NULL;
	return OK;
}

Status ClearList_L(LinkList L)   //保留头结点 
{
	LinkList pre,p;
	if(!L)
	{
		return ERROR;
	}
	pre=L->Next;
	while(pre)
	{
		p=pre->Next;
		free(pre);
		pre=p;
	}
	L->Next=NULL;
	return OK;
 } 
 
void DestroyList_L(LinkList *L)
{
	LinkList p=*L;
	while(p)
	{
		p=(*L)->Next;
		free(*L);
		(*L)=p; 
	}
}

Status ListEmpty_L(LinkList L)  //链表存在且只有头结点 
{
	if(L!=NULL&&L->Next==NULL)
	{
		return TRUE;
	}
	else{
		return 0; 
	}
}

int ListLength_L(LinkList L)
{
	int length;
	LinkList p;
	while(L)
	{
		length=0;
		p=L->Next;    //头结点不算在长度中 
		while(p)
		{
			length++;
			p=p->Next;
		 } 
	}
}

Status GetElem_L(LinkList L, int i, ElemType *e)
{
	if(i<1||i>ListLength_L(L))
	{
		return ERROR;
	}
	
	int j=1;
	LinkList p;
	p=L->Next;
	while(p&& j<i)
	{
		j++;
		p=p->Next;
	}
	if(!p||j>i)
	{
		return ERROR;
	 }
	
	*e=p->data;
	return OK;
}

Status ListInsert_L(LinkList L, int i, ElemType e)
{
	if(i<1||i>ListLength_L(L))
	{
		return ERROR;
	}
	
	int j=1;
	LinkList p,s;
	p=L;
	while(p&&j<i)     //寻找第i-1个结点 
	{
		p=p->Next;
		j++;
	}
	
	if(!p||j>i)          //第i-1个结点不存在 
	{
		return ERROR;
	 }
	  
	s=(LinkList)malloc(sizeof(Node));   //别忘了分配一块内存 
	s->data=e;
	s->Next=p->Next;
	p->Next=s;
	
	return OK;
}

Status ListDelete_L(LinkList L, int i, ElemType *e)
{
	if(i<1||i>ListLength_L(L))
	{
		return ERROR;
	}
	
	int j=1;
	LinkList p,s;
	p=L;
	while(p&&j<i)     //寻找第i-1个结点 
	{
		p=p->Next;
		j++;
	}
	
	if(!p||j>i)          //第i-1个结点不存在 
	{
		return ERROR;
	 }
	
	s=p->Next;
	p->Next=s->Next;
	*e=s->data;
	free(s);
	return OK;
}
Status CreateList_HL(LinkList *L, int n)        //头插法建立单链表L(逆序输入)
{
	LinkList p;
	int i;
	srand(time(0));
	*L=(LinkList)malloc(sizeof(Node));        //先建立一个带头结点的单链表 
	(*L)->Next=NULL;
	for(i=0;i<n;i++)
	{
		p=(LinkList)malloc(sizeof(Node));
		p->data=rand()%100+1;
		p->Next=(*L)->Next;
		(*L)->Next=p; 
	}
	 
	return OK;
}
Status CreateList_TL(LinkList *L, int n)        //尾插法建立单链表L(顺序输入)
{
	LinkList p,q;
	int i;
	srand(time(0));
	*L=(LinkList)malloc(sizeof(Node));        
	q=*L;
	for(i=0;i<n;i++)
	{
		p=(LinkList)malloc(sizeof(Node));
		p->data=rand()%100+1;
		q->Next=p;
		q=p;
	}
	q->Next=NULL;
	
	return OK;

}

int main()
{
	//测试 
}
