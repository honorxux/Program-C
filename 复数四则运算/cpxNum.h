
typedef struct {
	double _real;  //������ʵ�� 
	double _imag;  // �������鲿 
}cpxNum; 


cpxNum cplus(cpxNum *c1, cpxNum *c2);  /*ʵ����������c1, c2�ļӷ�, ����Ϊ����cplus�ķ���ֵ*/ 
cpxNum cmilus(cpxNum c1, cpxNum c2);  /*ʵ����������c1, c2�ļ���, ����Ϊ����cmilus�ķ���ֵ*/
cpxNum cmultiply(cpxNum c1,cpxNum c2);  /*ʵ����������c1, c2�ĳ˷�, ����Ϊ����cmultiply�ķ���ֵ*/ 
cpxNum cdivide(cpxNum c1, cpxNum c2);  /*ʵ����������c1, c2�ĳ���, ����Ϊ����cdivide�ķ���ֵ*/      
