#include "cpxNum.h"

cpxNum cdivide(cpxNum c1,cpxNum c2) /*ʵ����������c1, c2�ĳ���, ����Ϊ����cdivide�ķ���ֵ*/ 
{
	cpxNum result;
	result._real=(c1._real*c2._real+c1._imag*c2._imag)/(c2._real*c2._real+c2._imag*c2._imag);
	result._imag=(c1._imag*c2._real-c1._real*c2._imag)/(c2._real*c2._real+c2._imag*c2._imag);

	return result;
 } 
