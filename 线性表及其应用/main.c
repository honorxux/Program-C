#include<stdio.h>
#include <stdlib.h>
#include "polynomial.h"

int main()
{   
    int i,j,op;
    int m=0,n=0;  //��������  �ϲ�ͬ�����ʣ�����ĸ��� 
    Link p1,p2;
	printf("����ʽA(X)һ���ж�����\n");
	scanf("%d",&i);
	p1=polynomial1(i,&m);
	printf("\n\n����ʽB(X)һ���ж�����\n");
	scanf("%d",&j);
	p2=polynomial2(j,&n);
	
	
	printf("\n\n��������Ҫ��������[1.A(x)+B(x); 2.A(x)-B(x); 3.A'(x); 4.B'(x) ]��\n"); 
	scanf("%d",&op);
	
	switch (op)
	{
		case 1:
			AddPolyn(p1,p2,m,n);
			break;
		case 2:
			SubPolyn(p1,p2,m,n);
			break;
		case 3:
			Derivation(p1,m);
			break;
		case 4:
			Derivation(p2,n);
			break;
		default:
			printf("�������"); 
	}
	
	return 0; 
 } 
