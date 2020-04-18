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

Status InitList_L(LinkList *L);   //��ʼ��������L
Status ClearList_L(LinkList L);   //�ÿյ�����L��ͷ��㱣��
void DestroyList_L(LinkList *L);  //���ٵ�����L����ͬͨ���һ�����١� 
Status ListEmpty_L(LinkList L);   //�жϵ�����L�Ƿ�Ϊ��
int ListLength_L(LinkList L);     //���ص�����LԪ�ظ���
Status GetElem_L(LinkList L, int i, ElemType *e);       //��e���յ�����L�е�i��Ԫ��
Status ListInsert_L(LinkList L, int i, ElemType e);     //�ڵ�����L��i��λ��֮ǰ����e
Status ListDelete_L(LinkList L, int i, ElemType *e);    //ɾ��������L��i��λ�õ�ֵ������e����
Status CreateList_HL(LinkList *L, int n);        //ͷ�巨����������L(��������)
Status CreateList_TL(LinkList *L, int n);        //β�巨����������L(˳������)

Status InitList_L(LinkList *L)  //ͷ��� 
{
	(*L)=(LinkList)malloc(sizeof(Node));
	if(!(*L)){
		return ERROR;
	}
	(*L)->Next=NULL;
	return OK;
}

Status ClearList_L(LinkList L)   //����ͷ��� 
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

Status ListEmpty_L(LinkList L)  //���������ֻ��ͷ��� 
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
		p=L->Next;    //ͷ��㲻���ڳ����� 
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
	while(p&&j<i)     //Ѱ�ҵ�i-1����� 
	{
		p=p->Next;
		j++;
	}
	
	if(!p||j>i)          //��i-1����㲻���� 
	{
		return ERROR;
	 }
	  
	s=(LinkList)malloc(sizeof(Node));   //�����˷���һ���ڴ� 
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
	while(p&&j<i)     //Ѱ�ҵ�i-1����� 
	{
		p=p->Next;
		j++;
	}
	
	if(!p||j>i)          //��i-1����㲻���� 
	{
		return ERROR;
	 }
	
	s=p->Next;
	p->Next=s->Next;
	*e=s->data;
	free(s);
	return OK;
}
Status CreateList_HL(LinkList *L, int n)        //ͷ�巨����������L(��������)
{
	LinkList p;
	int i;
	srand(time(0));
	*L=(LinkList)malloc(sizeof(Node));        //�Ƚ���һ����ͷ���ĵ����� 
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
Status CreateList_TL(LinkList *L, int n)        //β�巨����������L(˳������)
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
	//���� 
}
