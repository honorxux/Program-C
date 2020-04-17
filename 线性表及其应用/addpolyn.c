//还存在bug  为什么两个多项式 相同 运行不了 

#include <stdio.h>
#include "polynomial.h"
#include <stdlib.h>
#include <math.h>

void AddPolyn(Link p1,Link p2,int a,int b)
{
	Link head,p;
	int i,cnt=0;
	int x;
	double sum=0;
//	p=p1;
	head=p1;
	while(head->_next)  //让p指向最后一个结点 
	{
		head=head->_next; 
	}
	head->_next=p2->_next; 
    free(p2);
    head=p1;
	p=sort(head,&cnt);
	
	printf("\n请输入x的值：");
	scanf ("%d",&x);
	
	printf("\nAx+Bx=\n");
	for(i=0;i<(a+b-cnt);i++)  //a+b 为 两个多项式相加之前的总项数         
	{
		p=p->_next;
 	if(p->_expn!=0)
   	{
		if(p->_codf >=0)
		printf("+%fx^%d",p->_codf,p->_expn);
		else
		printf("%fx^%d",p->_codf,p->_expn);
	  }
	 else{
	 	if(p->_codf >=0)
		printf("+%f",p->_codf);
		else
		printf("%f",p->_codf);
	 } 
	 sum+=p->_codf*pow(x,p->_expn);
	}
	
	printf("\n代入x=%d后结果为：%f",x,sum);


}


