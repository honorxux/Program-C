#include "cpxNum.h"

//��a + bi��*��c + di��=��ac - bd��+��ad + bc��i 

cpxNum cmultiply(cpxNum c1, cpxNum c2) /*ʵ����������c1, c2�ĳ˷�, ����Ϊ����cmultiply�ķ���ֵ*/
{
	cpxNum result;
	result._real=(c1._real*c2._real)-(c1._imag*c2._imag);
	result._imag=(c1._real*c2._imag)+(c1._imag*c2._real);
	
	return result;
 } 
