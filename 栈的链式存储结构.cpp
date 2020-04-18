//栈顶放在单链表的头部。  通常对于链栈来说，是不需要头结点的。 
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

typedef struct stacknode{
	SElemType data;
	struct stacknode *next;
}StackNode,*LinkStackPtr;

typedef struct linkstack{
	LinkStackPtr top;
	LinkStackPtr bottom;
}LinkStack;

void InitStack(LinkStack *S);              //    初始化栈的函数
Status Push(LinkStack *S ,int);             //    进行压栈操作的函数
void TraverseStack(LinkStack *S);          //    遍历栈函数
Status Empty(LinkStack *S);                //    判断栈是否为空的函数
Status Pop(LinkStack *S,int *e);                  //    进行出栈操作的函数
void Clear(LinkStack *S);                  //    清空栈的函数

void InitStack(LinkStack *S)
{
	S->top=(LinkStackPtr)malloc(sizeof(StackNode));
	if(!S->top)
	{
		exit(ERROR); 
	}
	else{
		S->top->next=NULL;
		S->bottom=S->top;
	}
}

void Clear(LinkStack *S)
{
	LinkStackPtr New=NULL;
	while(S->bottom != S->top)
	{
		New=S->top;
		S->top=S->top->next;
		free(New);
	}
}

Status Empty(LinkStack *S)
{
	if(S->bottom==S->top)
	{
		return TRUE;
	}
	else
	{
		return FALSE; 
	}
}

Status Push(LinkStack *S ,int e)
{
	LinkStackPtr New=(LinkStackPtr)malloc(sizeof(StackNode));
	if(New==NULL)
	{
		return ERROR;
	}
	New->data=e;
	New->next=S->top;
	S->top=New;
	return OK;
}

Status Pop(LinkStack *S,int *e)
{
	LinkStackPtr New=NULL;
	if(S->bottom==S->top)
	{
		return ERROR;
	}
	*e=S->top->data;
	New=S->top;
	S->top=S->top->next;
	free(New); 
	
	return OK;
}

void TraverseStack(LinkStack *S)
{
	LinkStackPtr New=S->top;
	while(New !=S->bottom)
	{
		printf("%d ",New->data);
		New=New->next;
	}
}


int main()
{
    LinkStack s;                        //    定义一个栈
    int i;
    int num;
    int data;     //    临时保存用户输入的数据
    int re_num;   //    保存Pop函数的返回值 
    InitStack(&s);
    printf("你想输入几个数据啊：");
    scanf("%d",&num); 
    for (i = 0;i < num;i++) 
    {
        printf("第 %d 个数：",i+1);
        scanf("%d",&data);
        if (Push(&s,data)) //    调用Push函数
        {
            continue;     
        } 
        else
        {
            printf("进行进栈操作失败！\n");
            exit(-1);
        }
    }
    TraverseStack(&s);         //调用遍历函数
    printf("你想去掉几个数啊: ");
    scanf("%d",&data);
    printf("你去掉的数字是：");
    for (i = 0; i < data;i++)
    {
        Pop(&s,&re_num);      //    调用Pop函数，并把返回值赋给re_num;
        printf("%d ",re_num);
    }
    printf("看看删除后还有啥：");
    TraverseStack(&s);
    printf("\n");
    Clear(&s);                 //调用清空栈函数
    printf("遍历下看看栈清空没????\n");
    TraverseStack(&s);
    printf("\n");
    return 0;
}
