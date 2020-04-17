#include "cpxNum.h"

cpxNum cdivide(cpxNum c1,cpxNum c2) /*实现两个复数c1, c2的除法, 商作为函数cdivide的返回值*/ 
{
	cpxNum result;
	result._real=(c1._real*c2._real+c1._imag*c2._imag)/(c2._real*c2._real+c2._imag*c2._imag);
	result._imag=(c1._imag*c2._real-c1._real*c2._imag)/(c2._real*c2._real+c2._imag*c2._imag);

	return result;
 } 
