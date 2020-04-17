#include "cpxNum.h"


cpxNum cplus(cpxNum *c1, cpxNum *c2) /*实现两个复数c1, c2的加法, 和作为函数cplus的返回值*/ 
{
	cpxNum result;
	result._real=c1->_real+c2->_real;
	result._imag=c1->_imag+c2->_imag;
	return result;
}
