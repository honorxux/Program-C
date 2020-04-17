#include <stdio.h>
#include "polynomial.h"

Link polynomial2(int j, int*q)
{
//调用尾插函数
	int i; 
	int cnt=0;//用来计数 指数相同的项数 
	Link p2,head;
	push_back(p2,j);
	//调用排序函数
	p2=sort(p2,&cnt);
	head=p2;
	printf("\n按指数降序输出多项式B(x)为:\n");
	for(i=0;i<(j-cnt);i++)
	{
		p2=p2->_next;
 	if(p2->_expn!=0)
   	{
		if(p2->_codf >=0)
		printf("+%fx^%d",p2->_codf,p2->_expn);
		else
		printf("%fx^%d",p2->_codf,p2->_expn);
	  }
	 else{
	 	if(p2->_codf >=0)
		printf("+%f",p2->_codf);
		else
		printf("%f",p2->_codf);
	 } 
	}
	p2->_next=NULL;
	p2=head;
	*q=j-cnt;
	return p2;
}
