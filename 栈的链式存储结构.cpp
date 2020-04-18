//ջ�����ڵ������ͷ����  ͨ��������ջ��˵���ǲ���Ҫͷ���ġ� 
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

typedef struct stacknode{
	SElemType data;
	struct stacknode *next;
}StackNode,*LinkStackPtr;

typedef struct linkstack{
	LinkStackPtr top;
	LinkStackPtr bottom;
}LinkStack;

void InitStack(LinkStack *S);              //    ��ʼ��ջ�ĺ���
Status Push(LinkStack *S ,int);             //    ����ѹջ�����ĺ���
void TraverseStack(LinkStack *S);          //    ����ջ����
Status Empty(LinkStack *S);                //    �ж�ջ�Ƿ�Ϊ�յĺ���
Status Pop(LinkStack *S,int *e);                  //    ���г�ջ�����ĺ���
void Clear(LinkStack *S);                  //    ���ջ�ĺ���

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
    LinkStack s;                        //    ����һ��ջ
    int i;
    int num;
    int data;     //    ��ʱ�����û����������
    int re_num;   //    ����Pop�����ķ���ֵ 
    InitStack(&s);
    printf("�������뼸�����ݰ���");
    scanf("%d",&num); 
    for (i = 0;i < num;i++) 
    {
        printf("�� %d ������",i+1);
        scanf("%d",&data);
        if (Push(&s,data)) //    ����Push����
        {
            continue;     
        } 
        else
        {
            printf("���н�ջ����ʧ�ܣ�\n");
            exit(-1);
        }
    }
    TraverseStack(&s);         //���ñ�������
    printf("����ȥ����������: ");
    scanf("%d",&data);
    printf("��ȥ���������ǣ�");
    for (i = 0; i < data;i++)
    {
        Pop(&s,&re_num);      //    ����Pop���������ѷ���ֵ����re_num;
        printf("%d ",re_num);
    }
    printf("����ɾ������ɶ��");
    TraverseStack(&s);
    printf("\n");
    Clear(&s);                 //�������ջ����
    printf("�����¿���ջ���û????\n");
    TraverseStack(&s);
    printf("\n");
    return 0;
}
