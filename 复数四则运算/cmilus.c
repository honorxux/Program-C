#include "cpxNum.h"


cpxNum cmilus(cpxNum c1,cpxNum c2) /*ʵ����������c1, c2�ļ���, ����Ϊ����cmilus�ķ���ֵ*/
{
    cpxNum result;
	result._real=c1._real-c2._real;
	result._imag=c1._imag-c2._imag;
	
	return result;
}
