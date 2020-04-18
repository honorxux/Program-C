#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define LIST_INIT_SIZE 100				//˳���洢�ռ�ĳ�ʼ������ 

typedef int Status;
typedef int ElemType;
typedef struct
{
	ElemType *elem;
	int length;
}SqList;

Status InitList_Sq(SqList *L);    //��ʼ����˳���L
void ClearList_Sq(SqList *L);     //���˳���L
void DestroyList_Sq(SqList *L);   //����˳���L��
Status ListEmpty_Sq(SqList *L);   //�ж�˳���L�Ƿ�Ϊ�ա�
Status ListLength_Sq(SqList *L);  //����˳���L��Ԫ�ظ���
Status GetElem_Sq(SqList *L, int i, ElemType *e);    //��e����˳���L�е�i��Ԫ��
Status ListInsert_Sq(SqList *L, int i, ElemType e);    //��˳���L�ĵ�i��λ���ϲ���e
Status ListDelete_Sq(SqList *L, int i, ElemType *e);      //ɾ��˳���L�ϵ�i��λ�õ�Ԫ�أ�����e����


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
		printf("�洢�ռ�����/n");
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

	printf("��1\n������ InitList_Sq ����...\n");		//1.����InitList_Sq����
	{
		printf("��ʼ��˳��� L ...\n");					 
		InitList_Sq(&L);
		printf("\n");	
	}
	
	printf("��4\n������ ListEmpty_Sq ����...\n");		//4.����ListEmpty_Sq����
	{
		ListEmpty_Sq(&L) ? printf(" L Ϊ�գ���\n") : printf(" L ��Ϊ�գ�\n");
		printf("\n");	
	}
		
	printf("��10\n������ ListInsert_Sq ����...\n");		//10.����ListInsert_Sq����
	{
		for(i=1; i<=6; i++)									
		{
			printf("��Ϊʾ������ L �� %d ��λ�ò��� \"%d\"...\n", i, 2*i);
			ListInsert_Sq(&L, i, 2*i);
		}
		printf("\n");	
	}
		
	printf("��5\n������ ListLength_Sq ����...\n");		//5.����ListLength_Sq����
	{
		i = ListLength_Sq(&L);
		printf(" L �ĳ���Ϊ %d \n", i);
		printf("\n");	
	}
			
	printf("��11\n������ ListDelete_Sq ����...\n");		//11.����ListDelete_Sq����
	{
		ListDelete_Sq(&L, 6, &e);
		printf("ɾ�� L �е� 6 ��Ԫ�� \"%d\" ...\n", e);
	}
		
	printf("��6\n������ GetElem_Sq ����...\n");			//6.����GetElem_Sq����
	{
		GetElem_Sq(&L, 4, &e);
		printf(" L �е� 4 ��λ�õ�Ԫ��Ϊ \"%d\" \n", e);
		printf("\n");
	}
		
	printf("��2\n������ ClearList_Sq ����...\n");		//2.����ClearList_Sq����
	{
		printf("��� L ǰ��");
		ListEmpty_Sq(&L) ? printf(" L Ϊ�գ���\n") : printf(" L ��Ϊ�գ�\n");		
		ClearList_Sq(&L);
		printf("��� L ��");
		ListEmpty_Sq(&L) ? printf(" L Ϊ�գ���\n") : printf(" L ��Ϊ�գ�\n");
		printf("\n");
	}
		
	printf("��3\n������ DestroyList_Sq ����...\n");		//3.����DestroyList_Sq����
	{
		printf("���� L ǰ��");
		L.elem ? printf(" L ���ڣ�\n") : printf(" L �����ڣ���\n");
		DestroyList_Sq(&L);
		printf("���� L ��");
		L.elem ? printf(" L ���ڣ�\n") : printf(" L �����ڣ���\n");
		printf("\n");
	}
		
	return 0;
}
