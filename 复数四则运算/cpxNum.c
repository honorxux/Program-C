#include <stdio.h>
#include "cpxNum.h"


int main(int argc, char *argv[]) 
{
	cpxNum c1,c2,result;
	int opselect;
	printf("�������һ��������ʵ�����鲿��\n");
	scanf("%lf %lf",&c1._real,&c1._imag );
	printf("\n������ڶ���������ʵ�����鲿��\n");
	scanf("%lf %lf",&c2._real,&c2._imag);
	printf("��������Ҫ������������Ӧ����ţ���1.�ӷ� 2.���� 3.�˷� 4.������\n");
	scanf("%d",&opselect);
	switch (opselect)
	{
		case 1:
			result=cplus(&c1,&c2);			
			break;
		case 2:
			result=cmilus(c1, c2);
			break;
		case 3:
			result=cmultiply(c1,c2);
			break;
		case 4:
			result=cdivide(c1, c2);
			break;	
	 }
	 
	 if(opselect!=1&&opselect!=2&&opselect!=3&&opselect!=4)
	 printf("error��");
	 else 
	 {
	 if(c2._real==0&&c2._imag==0&&opselect==4)
			printf("error!");
	else
	    {
		   if(result._imag<0)
	      printf("���Ϊ%lf%lfi",result._real,result._imag);
	      else
	      printf("���Ϊ%lf+%lfi",result._real,result._imag); 
        }
	 
}
	return 0;
}
