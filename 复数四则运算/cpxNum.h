
typedef struct {
	double _real;  //复数的实部 
	double _imag;  // 复数的虚部 
}cpxNum; 


cpxNum cplus(cpxNum *c1, cpxNum *c2);  /*实现两个复数c1, c2的加法, 和作为函数cplus的返回值*/ 
cpxNum cmilus(cpxNum c1, cpxNum c2);  /*实现两个复数c1, c2的减法, 差作为函数cmilus的返回值*/
cpxNum cmultiply(cpxNum c1,cpxNum c2);  /*实现两个复数c1, c2的乘法, 积作为函数cmultiply的返回值*/ 
cpxNum cdivide(cpxNum c1, cpxNum c2);  /*实现两个复数c1, c2的除法, 商作为函数cdivide的返回值*/      
