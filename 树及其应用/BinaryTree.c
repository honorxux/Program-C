#include "BinaryTree.h"

void InitBiTree(BiTree *T)
{
	*T=NULL;
}

Status CreateBiTree(BiTree *T)
{//按先序次序输入二叉树中结点的值(可为字符型或整型，在主程中定义)， 
 // 构造二叉链表表示的二叉树T。空格字符表示空树。 
 TElemType ch; 
 scanf("%c",&ch); // 输入结点的值 
// getchar();
 if(ch=='#') // 结点的值为空 
    *T=NULL; 
   else // 结点的值不为空 
   { *T=(BiTree)malloc(sizeof(BiTNode)); // 生成根结点 
   if(!(*T)) 
    exit(OVERFLOW); 
    (*T)->data=ch; // 将值赋给T所指结点 
    CreateBiTree(&(*T)->lchild); // 递归构造左子树 
    CreateBiTree(&(*T)->rchild); // 递归构造右子树 
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
		Visit(T->data);   //Visit就相当于函数PrintElem 
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
	
	p = (QueuePtr)malloc(sizeof(QNode));                //这一步经常忘 
	if(!p)
		exit(OVERFLOW);

	p->Data = e;
	p->next = NULL;          //这一步也经常忘 
	
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
	if((*Q).rear==p)           //如果只有一个元素，则头指针和尾指针都指向头结点，队列为空 
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
//	for(scanf("%c %c",&fa,&ch);ch!=' ';scanf("%c %c",&fa,&ch))   按层次输入树中的结点 
     scanf("%c %c",&fa,&ch);
     getchar();
     while(ch!='#')    //用#代表空 
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
