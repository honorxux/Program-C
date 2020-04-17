#include "cpxNum.h"

//（a + bi）*（c + di）=（ac - bd）+（ad + bc）i 

cpxNum cmultiply(cpxNum c1, cpxNum c2) /*实现两个复数c1, c2的乘法, 积作为函数cmultiply的返回值*/
{
	cpxNum result;
	result._real=(c1._real*c2._real)-(c1._imag*c2._imag);
	result._imag=(c1._real*c2._imag)+(c1._imag*c2._real);
	
	return result;
 } 
