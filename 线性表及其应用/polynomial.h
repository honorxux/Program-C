#ifndef _POLYNOMIAL_H_
#define _POLYNOMIAL_H_
 

 //定义多项式链表的'结点'存储结构，每一个结点对应稀疏多项式中的一项
 typedef struct LNode{
 	float _codf; //多项式的系数
	int _expn; //多项式的指数 
	struct LNode *_next; //指向下一个多项式结点的指针 
 } *Link;  //定义了一个新的类型link,该类型变量是指向多项式结点的指针
 


void AddPolyn(Link , Link,int ,int);
void SubPolyn(Link , Link,int ,int); 
void Derivation(Link, int);  
Link polynomial1(int ,int * );
void push_back(Link,int); 
Link sort(Link,int *);
Link polynomial2(int ,int* );
#endif


