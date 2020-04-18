#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define LIST_INIT_SIZE 100				//顺序表存储空间的初始分配量 

typedef int Status;
typedef int ElemType;
typedef struct
{
	ElemType *elem;
	int length;
}SqList;

Status InitList_Sq(SqList *L);    //初始化空顺序表L
void ClearList_Sq(SqList *L);     //清空顺序表L
void DestroyList_Sq(SqList *L);   //销毁顺序表L。
Status ListEmpty_Sq(SqList *L);   //判断顺序表L是否为空。
Status ListLength_Sq(SqList *L);  //返回顺序表L中元素个数
Status GetElem_Sq(SqList *L, int i, ElemType *e);    //用e接收顺序表L中第i个元素
Status ListInsert_Sq(SqList *L, int i, ElemType e);    //在顺序表L的第i个位置上插入e
Status ListDelete_Sq(SqList *L, int i, ElemType *e);      //删除顺序表L上第i个位置的元素，并用e返回


Status InitList_Sq(SqList *L)
{
	L->elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if(!L->elem){
		return ERROR;
	}
	L->length=0;
	return OK;
}

void ClearList_Sq(SqList *L)
{
	L->length=0;
}

void DestroyList_Sq(SqList *L)
{
	free(L->elem);
	L->length=0;
	L->elem=NULL;
}

Status ListEmpty_Sq(SqList *L)
{
	return L->length==0?TRUE:FALSE;
}

Status ListLength_Sq(SqList *L)
{
	return L->length;
}

Status GetElem_Sq(SqList *L, int i, ElemType *e){
	if(i>L->length||i<1){
		return ERROR;
	}
	else
	{
		*e=L->elem[i-1];
		return OK;
	}
}

Status ListInsert_Sq(SqList *L, int i, ElemType e)
{
	ElemType k; 
	if(i>L->length+1||i<1){
		return ERROR;
	}
	if(L->length==LIST_INIT_SIZE){
		printf("存储空间已满/n");
		return ERROR;
	}
	if(i<=L->length){
		for(k=L->length;k>=i;k--)
		{
			L->elem[k]=L->elem[k-1];
		}
	}
	L->elem[i-1]=e;
	L->length++;
	return OK;
}

Status ListDelete_Sq(SqList *L, int i, ElemType *e)
{
	ElemType k;
	if(i>L->length||i<1){
		return ERROR;
	}
	if(L->length==0)
	{
		return ERROR;
	}
	*e=L->elem[i-1];
	for(k=i;k<=L->length;k++)
	{
		L->elem[k-1]=L->elem[k];
	}
	L->length--;
	return OK;
}


int main()
{
	SqList L;
	int i;
	ElemType e;

	printf("▼1\n▲函数 InitList_Sq 测试...\n");		//1.函数InitList_Sq测试
	{
		printf("初始化顺序表 L ...\n");					 
		InitList_Sq(&L);
		printf("\n");	
	}
	
	printf("▼4\n▲函数 ListEmpty_Sq 测试...\n");		//4.函数ListEmpty_Sq测试
	{
		ListEmpty_Sq(&L) ? printf(" L 为空！！\n") : printf(" L 不为空！\n");
		printf("\n");	
	}
		
	printf("▼10\n▲函数 ListInsert_Sq 测试...\n");		//10.函数ListInsert_Sq测试
	{
		for(i=1; i<=6; i++)									
		{
			printf("作为示范，在 L 第 %d 个位置插入 \"%d\"...\n", i, 2*i);
			ListInsert_Sq(&L, i, 2*i);
		}
		printf("\n");	
	}
		
	printf("▼5\n▲函数 ListLength_Sq 测试...\n");		//5.函数ListLength_Sq测试
	{
		i = ListLength_Sq(&L);
		printf(" L 的长度为 %d \n", i);
		printf("\n");	
	}
			
	printf("▼11\n▲函数 ListDelete_Sq 测试...\n");		//11.函数ListDelete_Sq测试
	{
		ListDelete_Sq(&L, 6, &e);
		printf("删除 L 中第 6 个元素 \"%d\" ...\n", e);
	}
		
	printf("▼6\n▲函数 GetElem_Sq 测试...\n");			//6.函数GetElem_Sq测试
	{
		GetElem_Sq(&L, 4, &e);
		printf(" L 中第 4 个位置的元素为 \"%d\" \n", e);
		printf("\n");
	}
		
	printf("▼2\n▲函数 ClearList_Sq 测试...\n");		//2.函数ClearList_Sq测试
	{
		printf("清空 L 前：");
		ListEmpty_Sq(&L) ? printf(" L 为空！！\n") : printf(" L 不为空！\n");		
		ClearList_Sq(&L);
		printf("清空 L 后：");
		ListEmpty_Sq(&L) ? printf(" L 为空！！\n") : printf(" L 不为空！\n");
		printf("\n");
	}
		
	printf("▼3\n▲函数 DestroyList_Sq 测试...\n");		//3.函数DestroyList_Sq测试
	{
		printf("销毁 L 前：");
		L.elem ? printf(" L 存在！\n") : printf(" L 不存在！！\n");
		DestroyList_Sq(&L);
		printf("销毁 L 后：");
		L.elem ? printf(" L 存在！\n") : printf(" L 不存在！！\n");
		printf("\n");
	}
		
	return 0;
}
