#include <stdio.h>
#include <stdlib.h>
#include "polynomial.h"


void push_back(Link L,int j)//β�巨�������� 
{
	int i;
	Link s,r;//s����ָʾ�����ɵĽ�� r����ָʾL���ն˽�� 
	r=L;//r ָ��ͷ��㣬��ʱͷ������ն˽�� 
	float codf;
	int expn;
	for(i=1;i<=j;i++)
	{
	s=(Link)malloc(sizeof(struct LNode));//  �޸�һ�� �ñ�ı�ʾ�� 
	printf("��ֱ������%d���ϵ����ָ��",i);
	scanf("%f %d",&codf,&expn);
	s->_codf=codf;
	s->_expn=expn;
	r->_next=s;//r���������µĽ��
	r=s;//rָ���ն˽�� 
    }
    r->_next=NULL;
    
}
