#include <stdio.h>
#include <stdlib.h>
#include "polynomial.h"


void push_back(Link L,int j)//尾插法建立链表 
{
	int i;
	Link s,r;//s用来指示新生成的结点 r用来指示L的终端结点 
	r=L;//r 指向头结点，此时头结点是终端结点 
	float codf;
	int expn;
	for(i=1;i<=j;i++)
	{
	s=(Link)malloc(sizeof(struct LNode));//  修改一下 用别的表示法 
	printf("请分别输入第%d项的系数和指数",i);
	scanf("%f %d",&codf,&expn);
	s->_codf=codf;
	s->_expn=expn;
	r->_next=s;//r用来接纳新的结点
	r=s;//r指向终端结点 
    }
    r->_next=NULL;
    
}
