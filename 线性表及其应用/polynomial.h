#ifndef _POLYNOMIAL_H_
#define _POLYNOMIAL_H_
 

 //�������ʽ�����'���'�洢�ṹ��ÿһ������Ӧϡ�����ʽ�е�һ��
 typedef struct LNode{
 	float _codf; //����ʽ��ϵ��
	int _expn; //����ʽ��ָ�� 
	struct LNode *_next; //ָ����һ������ʽ����ָ�� 
 } *Link;  //������һ���µ�����link,�����ͱ�����ָ�����ʽ����ָ��
 


void AddPolyn(Link , Link,int ,int);
void SubPolyn(Link , Link,int ,int); 
void Derivation(Link, int);  
Link polynomial1(int ,int * );
void push_back(Link,int); 
Link sort(Link,int *);
Link polynomial2(int ,int* );
#endif


