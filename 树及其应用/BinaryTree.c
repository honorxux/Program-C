#include "BinaryTree.h"

void InitBiTree(BiTree *T)
{
	*T=NULL;
}

Status CreateBiTree(BiTree *T)
{//�������������������н���ֵ(��Ϊ�ַ��ͻ����ͣ��������ж���)�� 
 // ������������ʾ�Ķ�����T���ո��ַ���ʾ������ 
 TElemType ch; 
 scanf("%c",&ch); // �������ֵ 
// getchar();
 if(ch=='#') // ����ֵΪ�� 
    *T=NULL; 
   else // ����ֵ��Ϊ�� 
   { *T=(BiTree)malloc(sizeof(BiTNode)); // ���ɸ���� 
   if(!(*T)) 
    exit(OVERFLOW); 
    (*T)->data=ch; // ��ֵ����T��ָ��� 
    CreateBiTree(&(*T)->lchild); // �ݹ鹹�������� 
    CreateBiTree(&(*T)->rchild); // �ݹ鹹�������� 
  }
	
	return OK;
	
}//CreateBiTree

void PreOrderTraverse(BiTree T)
{
	if(T)
	{
		printf("%c ",T->data);
		//Visit(T->data);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}

void InOrderTraverse(BiTree T, void(*Visit)(TElemType))
{
	if(T)
	{
		InOrderTraverse(T->lchild, Visit);
		Visit(T->data);   //Visit���൱�ں���PrintElem 
		InOrderTraverse(T->rchild, Visit);
	}
}

void PostOrderTraverse(BiTree T, void(Visit)(TElemType))
{
	if(T)
	{
		PostOrderTraverse(T->lchild, Visit);
		PostOrderTraverse(T->rchild, Visit);
		Visit(T->data);
	}
}


void PrintElem(TElemType e)
{
	printf("%c ",e);
}


Status InitQueue_L(LinkQueue *Q)
{
	(*Q).front = (*Q).rear = (QueuePtr)malloc(sizeof(QNode));
	if(!(*Q).front)
		exit(OVERFLOW);

	(*Q).front->next = NULL;

	return OK;
}

Status GetHead_L(LinkQueue *Q, QElemType_L *e)
{
	QueuePtr p;
	
	if((*Q).front==(*Q).rear)
		return ERROR;
		
	p = (*Q).front->next;
	*e = p->Data;
//	printf("%c",(*e)->data);
	return OK;
} 

Status EnQueue_L(LinkQueue *Q, QElemType_L e)
{
	QueuePtr p;
	
	p = (QueuePtr)malloc(sizeof(QNode));                //��һ�������� 
	if(!p)
		exit(OVERFLOW);

	p->Data = e;
	p->next = NULL;          //��һ��Ҳ������ 
	
	(*Q).rear->next = p;
	(*Q).rear=p;
//    printf("%c\n",((*Q).rear)->Data->data);
//    printf("%c\n",((*Q).front)->next->Data->data);
		return OK;
} 

Status DeQueue_L(LinkQueue *Q, QElemType_L *e)
{
	QueuePtr p;
	
	if((*Q).front==(*Q).rear)
		return ERROR;
		
	p = (*Q).front->next;
	*e = p->Data;
//	printf("DeQueue:%c",p->Data->data);
	(*Q).front->next = p->next;
	if((*Q).rear==p)           //���ֻ��һ��Ԫ�أ���ͷָ���βָ�붼ָ��ͷ��㣬����Ϊ�� 
		(*Q).rear = (*Q).front;
		
	free(p);
	
	return OK;
} 

void InitCSTree(CSTree *T)
{
	*T=NULL;
	(*T)->firstchild=NULL;
	(*T)->nextsibling=NULL;
}

void CreatTree(CSTree *Tree)
{
	TElemType fa,ch;
	CSTree T;
	
	QElemType_L r,s;
//	InitCSTree(&T);
    T=NULL;
	LinkQueue Q;
	InitQueue_L(&Q);
	*Tree=NULL;
//	for(scanf("%c %c",&fa,&ch);ch!=' ';scanf("%c %c",&fa,&ch))   ������������еĽ�� 
     scanf("%c %c",&fa,&ch);
     getchar();
     while(ch!='#')    //��#����� 
	{
//		getchar();
		T=(CSTree)malloc(sizeof(CSNode));
		T->data=ch;
		T->firstchild=NULL;
		T->nextsibling=NULL;
//		printf("%c %c\n",fa,ch);
		EnQueue_L(&Q,T);
		if(fa=='#')
		*Tree=T;
		else
		{
			GetHead_L(&Q,&s);
			while(s->data!=fa)
			{
				DeQueue_L(&Q,&s);
				GetHead_L(&Q,&s);
			}
			if(!(s->firstchild))
			    {
			    	s->firstchild=T;
			    	r=T;
				}
			else 
			{
				r->nextsibling=T;
				r=T;
				}	
		}
		
		scanf("%c %c",&fa,&ch);
		getchar();
		
	}
}

void PreOrderTraverse_t(CSTree T)
{
	if(T)
	{
		printf("%c ",T->data);
		//Visit(T->data);
		PreOrderTraverse_t(T->firstchild);
		PreOrderTraverse_t(T->nextsibling);
	}
}
