#include "cpxNum.h"


cpxNum cmilus(cpxNum c1,cpxNum c2) /*实现两个复数c1, c2的减法, 差作为函数cmilus的返回值*/
{
    cpxNum result;
	result._real=c1._real-c2._real;
	result._imag=c1._imag-c2._imag;
	
	return result;
}
