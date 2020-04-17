#include <stdio.h>
#include "polynomial.h"
#include <stdlib.h>
#include <math.h>

void Derivation(Link p, int j)
{
	int i;
	Link head;
	double x;
	double sum=0;
	head=p;
	printf("\n请输入x的值：");
	scanf ("%lf",&x);
	
	while(p->_next)
	{
		p=p->_next;
		if(p->_expn!=0)
		{
			p->_codf=p->_codf*p->_expn;
			p->_expn=p->_expn-1;
		}
		else
		{
			p->_codf==0;
		}
	}
	p=head;
	
	for(i=0;i<j;i++)        
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
  
  
