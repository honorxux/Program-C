#include <stdio.h>
#include "polynomial.h"



Link polynomial1(int j,int *p)
{
	//调用尾插函数
	int i; 
	int cnt=0; //用来计数 指数相同的项的个数 
	Link p1,head;
	push_back(p1,j);
	//调用排序函数
	p1=sort(p1,&cnt);
	head=p1;
	printf("\n按指数降序输出多项式A(x)为:\n");
	for(i=0;i<(j-cnt);i++)
//    while(p1->_next)
	{
		p1=p1->_next;
 	if(p1->_expn!=0)
   	{
		if(p1->_codf >=0)
		printf("+%fx^%d",p1->_codf,p1->_expn);
		else
		printf("%fx^%d",p1->_codf,p1->_expn);
	  }
	 else{
	 	if(p1->_codf >=0)
		printf("+%f",p1->_codf);
		else
		printf("%f",p1->_codf);
	 } 
	}
	p1->_next=NULL;
	p1=head;
	*p=j-cnt;
	return p1;
}


