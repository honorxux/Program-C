#include <stdio.h>
#include <stdlib.h>
#include "polynomial.h"


 
 Link sort(Link L,int *cnt)
 {
 	Link r,s,p,q;
 	Link head,b;
 	r=L;
    r=r->_next->_next;
/*
    static int count=0;
    count++;
    if(count>1)
    free(s);
*/
 	s=(Link)malloc(sizeof(struct LNode));
 	q=(Link)malloc(sizeof(struct LNode));
 	p=(Link)malloc(sizeof(struct LNode));
 	//s=malloc(sizeof(Link));
 //	s->_next=NULL;
 	
 	q->_codf=L->_next->_codf;
	q->_expn=L->_next->_expn; 
	
 //   q->_next=NULL; 
 //	p->_next=s->_next;
    s->_next=q;
    head=s;
    
 
  //  p=s->_next; 

    
 	while(r)
 	{   
      //  s=(Link)malloc(sizeof(struct LNode));
 	    p=s->_next; 
        while(s)
  //      do
 	    {
 	   
 	    	if(r->_expn>(p->_expn))
 	    	{
 	    		b=(Link)malloc(sizeof(struct LNode));
 	    		b->_codf=r->_codf;
				b->_expn=r->_expn; 
				b->_next=p;
 	    		s->_next=b;
 	            break;
			 }
			 
			else if(r->_expn==p->_expn)
 	    	{
 	    		p->_codf=p->_codf+r->_codf;
 	    		*cnt=*cnt+1;
 	            break;
			 } 
			else
		{
	    	s=s->_next;
			p=s->_next;
	    }
		 }           //   while(s);
		 
 		r=r->_next;
 		s=head;
	 }

	 
	 return s;
 }
