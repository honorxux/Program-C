//还没有考虑  同类项相减系数为0的情况                 
#include <stdio.h>
#include <stdlib.h>
#include "polynomial.h"
#include <math.h>

   void SubPolyn(Link p1, Link p2,int a,int b)
{
    Link head,p;
	int i,cnt=0;
	double x;
	double sum=0;
//	p=p1;
	head=p2;
	while(p2->_next)  //让p指向最后一个结点 
	{
		p2=p2->_next;
		p2->_codf=-p2->_codf; 
	}
	p2->_next=p1->_next; 
	p2=head;
	free(p1);
	p=sort(p2,&cnt);
	
	printf("\n请输入x的值：");
	scanf ("%lf",&x);
	
	printf("\nAx-Bx=\n");
	for(i=0;i<(a+b-cnt);i++)  //a+b 为 两个多项式相加之前的总项数         
	{
		p=p->_next;
	if(p->_expn!=0)
	 {
		if(p->_codf >0)
		printf("+%fx^%d",p->_codf,p->_expn);
		else if(p->_codf==0)
		printf(""); 
		else
		printf("%fx^%d",p->_codf,p->_expn);
     }
    else
     {
    	if(p->_codf >0)
		printf("+%f",p->_codf);
		else if(p->_codf==0)
		printf(""); 
		else
		printf("%f",p->_codf);
    	}
    	
    	 sum+=p->_codf*pow(x,p->_expn);
	}
	
		printf("\n代入x=%f后结果为：%f",x,sum);

}

